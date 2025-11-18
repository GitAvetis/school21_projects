#include "backend.h"

int create_matrix(int ***matrix, int rows, int columns) {
  *matrix = NULL;
  int err = 0;
  if (rows <= 0 || columns <= 0) err++;
  if (!err) {
    *matrix = calloc(rows, sizeof(int *));
    if (!(*matrix)) err++;
    for (int i = 0; i < rows && !err; i++) {
      (*matrix)[i] = calloc(columns, sizeof(int));
      if (!(*matrix)[i]) {
        err++;
        for (int j = 0; j < i; j++) {
          free((*matrix)[j]);
          (*matrix)[j] = NULL;
        }
        free((*matrix));
        (*matrix) = NULL;
      }
    }
  }
  return err;
}
void remove_matrix(int ***matrix, int rows) {
  if (matrix && *matrix) {
    for (int i = 0; i < rows; i++) {
      if ((*matrix)[i]) {
        free((*matrix)[i]);
        (*matrix)[i] = NULL;
      }
    }
    free(*matrix);
    *matrix = NULL;
  }
}

void free_game_info(GameInfo_t *result) {
  if (result->field) remove_matrix(&result->field, FIELD_HEIGHT);
  if (result->next) remove_matrix(&result->next, TETR_SIZE);
}

void copy_matrix(int **dest, int **src, int rows, int columns) {
  if (dest && src && rows > 0 && columns > 0) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        dest[i][j] = src[i][j];
      }
    }
  }
}

void reset_matrix(int **src, int rows, int columns) {
  if (src && rows > 0 && columns > 0) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        src[i][j] = 0;
      }
    }
  }
}

void write_score(int high_score) {
  FILE *file = fopen("tetris_score.txt", "w");
  if (file) {
    fprintf(file, "%d", high_score);
    fclose(file);
  }
}

int read_score() {
  int high_score = 0;
  FILE *file = fopen("tetris_score.txt", "r");
  if (file) {
    if (fscanf(file, "%d", &high_score) != 1) {
      high_score = 0;
    }
    fclose(file);
  }
  return high_score;
}

long long int update_timer() {
  struct timeval current_time;
  gettimeofday(&current_time, NULL);
  return (long long int)current_time.tv_sec * 1000 +
         current_time.tv_usec / 1000;
}

void fill_tetramino(int **filled, TetraminoType_t num) {
  reset_matrix(filled, TETR_SIZE, TETR_SIZE);
  switch (num) {
    case TETRO_O:
      filled[1][1] = TETRO_O;
      filled[1][2] = TETRO_O;
      filled[2][1] = TETRO_O;
      filled[2][2] = TETRO_O;
      break;
    case TETRO_I:
      for (int i = 0; i < 4; i++) filled[2][i] = TETRO_I;
      break;
    case TETRO_T:
      filled[2][2] = TETRO_T;
      for (int i = 1; i < 4; i++) filled[1][i] = TETRO_T;
      break;
    case TETRO_S:
      filled[1][2] = TETRO_S;
      filled[1][3] = TETRO_S;
      filled[2][1] = TETRO_S;
      filled[2][2] = TETRO_S;
      break;
    case TETRO_Z:
      filled[1][1] = TETRO_Z;
      filled[1][2] = TETRO_Z;
      filled[2][2] = TETRO_Z;
      filled[2][3] = TETRO_Z;
      break;
    case TETRO_J:
      filled[1][1] = TETRO_J;
      for (int i = 1; i < 4; i++) filled[2][i] = TETRO_J;
      break;
    case TETRO_L:
      filled[1][3] = TETRO_L;
      for (int i = 1; i < 4; i++) filled[2][i] = TETRO_L;
      break;
    default:
      break;
  }
}
TetraminoType_t generate_next_tetramino(int **next) {
  TetraminoType_t tetr_type = (rand() % 7) + 1;
  fill_tetramino(next, tetr_type);
  if (tetr_type != TETRO_O) {
    int random_rotation = rand() % 4;
    while (random_rotation--) rotate_matrix_90(&next);
  }
  return tetr_type;
}

void set_tetramino_on_field(int **field, ModelInfo_t *actual_info) {
  for (int y = 0; y < TETR_SIZE; y++) {
    for (int x = 0; x < TETR_SIZE; x++) {
      int field_y = actual_info->y_position + y;
      int field_x = actual_info->x_position + x;
      // actual_info->*_position - координата левого верхнего угла матрицы
      // фигуры
      if (field_x >= 0 && field_x < FIELD_WIDTH && field_y >= 0 &&
          field_y < FIELD_HEIGHT) {
        if (actual_info->current_tetramino[y][x] != 0) {
          field[field_y][field_x] = actual_info->current_tetramino[y][x];
        }
      }
    }
  }
}
CollisionType_t is_move_collision(const ModelInfo_t *actual_info) {
  CollisionType_t collision_type = COLLISION_NONE;
  int field_y;
  int field_x;
  for (int y = 0; y < TETR_SIZE; y++) {
    for (int x = 0; x < TETR_SIZE; x++) {
      // Преобразуем координаты фигуры в координаты игрового поля
      field_y = actual_info->y_position + y;
      field_x = actual_info->x_position + x;
      if (actual_info->current_tetramino[y][x] != 0) {
        if (field_x >= FIELD_WIDTH || field_x < 0)
          collision_type = COLLISION_BASE;
        else if (field_y >= FIELD_HEIGHT)
          collision_type = COLLISION_FLOOR;
        else if (field_y >= 0 && actual_info->field_base[field_y][field_x] != 0)
          collision_type = COLLISION_BASE;
      }
    }
  }
  return collision_type;
}

CollisionType_t check_rotate_collision(const ModelInfo_t *actual_info) {
  CollisionType_t collision_type = COLLISION_NONE;
  int field_y;
  int field_x;
  for (int y = 0; y < TETR_SIZE; y++) {
    for (int x = 0; x < TETR_SIZE; x++) {
      field_y = actual_info->y_position + y;
      field_x = actual_info->x_position + x;
      if (actual_info->collision_test_tetramino[y][x] != 0) {
        if (field_x >= FIELD_WIDTH)
          collision_type = COLLISION_RIGHT;
        else if (field_x < 0)
          collision_type = COLLISION_LEFT;
        else if (field_y >= FIELD_HEIGHT)
          collision_type = COLLISION_FLOOR;
        else if (field_y >= 0 && actual_info->field_base[field_y][field_x] != 0)
          collision_type = COLLISION_BASE;
      }
    }
  }
  return collision_type;
}

CollisionType_t is_rotation_blocked() {
  ModelInfo_t *actual_info = get_info();
  CollisionType_t collision = COLLISION_NONE;
  int origin_posotion_x = actual_info->x_position;

  copy_matrix(actual_info->collision_test_tetramino,
              actual_info->current_tetramino, TETR_SIZE, TETR_SIZE);
  if (actual_info->current_type != TETRO_O)
    rotate_matrix_90(&(actual_info->collision_test_tetramino));
  collision = check_rotate_collision(actual_info);
  if (actual_info->current_type == TETRO_I && collision)
    collision = i_wall_kick(actual_info, collision, origin_posotion_x);
  else if (collision) {
    collision = wall_kick(actual_info, collision);
  }
  if (collision != COLLISION_NONE) actual_info->x_position = origin_posotion_x;
  return collision;
}
CollisionType_t wall_kick(ModelInfo_t *actual_info, CollisionType_t collision) {
  CollisionType_t new_collision = COLLISION_NONE;

  if (collision == COLLISION_LEFT)
    actual_info->x_position++;
  else if (collision == COLLISION_RIGHT)
    actual_info->x_position--;
  new_collision = check_rotate_collision(actual_info);

  if (new_collision == COLLISION_NONE) {
    collision = new_collision;
  }

  return collision;
}
CollisionType_t i_wall_kick(ModelInfo_t *actual_info, CollisionType_t collision,
                            int original_x) {
  const int offsets[] = {-1, 1, 2, -2, -1, 1, 2};
  int num_attempts = 8;

  for (int i = 0; i < num_attempts; i++) {
    actual_info->x_position = original_x + offsets[i];
    CollisionType_t new_collision = check_rotate_collision(actual_info);

    if (new_collision == COLLISION_NONE) {
      collision = new_collision;
      i = num_attempts;
    }
  }
  return collision;
}

void rotate_matrix_90(int ***matrix) {
  int **rotated = NULL;
  int error = create_matrix(&rotated, TETR_SIZE, TETR_SIZE);
  if (error == 0) {
    for (int i = 0; i < TETR_SIZE; i++) {
      for (int j = 0; j < TETR_SIZE; j++) {
        rotated[j][TETR_SIZE - 1 - i] = (*matrix)[i][j];
      }
    }
    copy_matrix(*matrix, rotated, TETR_SIZE, TETR_SIZE);
  }
  if (rotated != NULL) {
    remove_matrix(&rotated, TETR_SIZE);
  }
}

void move_left(ModelInfo_t *actual_info) {
  actual_info->x_position--;
  if (is_move_collision(actual_info) != COLLISION_NONE)
    actual_info->x_position++;
}

void move_right(ModelInfo_t *actual_info) {
  actual_info->x_position++;
  if (is_move_collision(actual_info) != COLLISION_NONE)
    actual_info->x_position--;
}

void shift_tetramino(ModelInfo_t *actual_info) {
  actual_info->y_position++;
  if (is_move_collision(actual_info) != COLLISION_NONE) {
    actual_info->y_position--;
    actual_info->state = Attaching;
  } else
    actual_info->state = Moving;
}

void attach_tetramino(ModelInfo_t *actual_info) {
  set_tetramino_on_field(actual_info->field_base, actual_info);
  calculate_lines(actual_info);
  actual_info->state = Spawn;
}

void move_tetramino(ModelInfo_t *actual_info) {
  if (actual_info->hold) {
    switch (actual_info->user_action) {
      case Left:
        move_left(actual_info);
        break;
      case Right:
        move_right(actual_info);
        break;
      case Down:
        shift_tetramino(actual_info);
        break;
      case Action:
        if (!is_rotation_blocked()) {
          copy_matrix(actual_info->current_tetramino,
                      actual_info->collision_test_tetramino, TETR_SIZE,
                      TETR_SIZE);
        }
        break;
      case Terminate:
      case Pause:
        actual_info->state = Pause_state;
        actual_info->pause = PAUSE_ACTIVATED;
        break;
      default:
        break;
    }
  }
  int drop_interval = 700 - (actual_info->speed * 52);
  if (drop_interval < 50) drop_interval = 50;
  if ((update_timer() - actual_info->timer) >= drop_interval) {
    actual_info->timer = update_timer();
    shift_tetramino(actual_info);
  }
}

void calculate_lines(ModelInfo_t *actual_info) {
  int cleard_lines = 0;
  for (int y = 0; y < FIELD_HEIGHT; y++) {
    bool full_line_trg = true;
    for (int x = 0; x < FIELD_WIDTH; x++) {
      if (actual_info->field_base[y][x] == 0) full_line_trg = false;
    }
    if (full_line_trg) {
      clear_line(actual_info->field_base, y);
      cleard_lines++;
    }
  }
  if (cleard_lines > 0) {
    update_score(actual_info, cleard_lines);
    update_speed_and_level(actual_info);
  }
}

void clear_line(int **field_base, int line) {
  for (int i = line; i > 0; i--) {
    for (int j = 0; j < FIELD_WIDTH; j++) {
      field_base[i][j] = field_base[i - 1][j];
    }
  }
  for (int i = 0; i < FIELD_WIDTH; i++) {
    field_base[0][i] = 0;
  }
}

void update_score(ModelInfo_t *actual_info, int cleard_lines) {
  int multiplier = 1;
  for (int i = 0; i < cleard_lines; i++) {
    multiplier *= 2;
  }
  actual_info->score += 100 * (multiplier - 1);
}

void update_speed_and_level(ModelInfo_t *actual_info) {
  int new_level = (actual_info->score / 600) + 1;
  if (new_level > 10) new_level = 10;
  actual_info->level = new_level;
  actual_info->speed = actual_info->level - 1;
}

void spawn_tetramino(ModelInfo_t *actual_info) {
  update_high_score(actual_info);
  copy_matrix(actual_info->current_tetramino, actual_info->next_tetramino,
              TETR_SIZE, TETR_SIZE);
  actual_info->current_type = actual_info->next_type;
  actual_info->next_type = generate_next_tetramino(actual_info->next_tetramino);
  actual_info->x_position = SPAWN_X_POSITION;
  actual_info->y_position = SPAWN_Y_POSITION;
  if (is_move_collision(actual_info))
    actual_info->state = Game_over;
  else
    actual_info->state = Moving;
}
void run_actions_by_state(ModelInfo_t *actual_info) {
  switch (actual_info->state) {
    case Start_state:
      initialize_game(actual_info);
      break;
    case Spawn:
      spawn_tetramino(actual_info);
      break;
    case Moving:
      move_tetramino(actual_info);
      break;
    case Attaching:
      attach_tetramino(actual_info);
      break;
    case Pause_state:
      pause_actions(actual_info);
      break;
    case Game_over:
      game_over_actions(actual_info);
      break;
    case Exit_state:
      run_terminate_actions(actual_info);
      break;
    default:
      break;
  }
}

void game_over_actions(ModelInfo_t *actual_info) {
  // update_high_score(actual_info);
  actual_info->pause = PAUSE_GAME_OVER;
  actual_info->state = Start_state;
}

void pause_actions(ModelInfo_t *actual_info) {
  if (actual_info->hold) {
    if (actual_info->user_action == Pause) {
      actual_info->pause = NOT_PAUSED;
      actual_info->state = Moving;
    } else if (actual_info->user_action == Terminate)
      actual_info->state = Exit_state;
  }
}

void update_high_score(ModelInfo_t *actual_info) {
  if (actual_info->score > actual_info->high_score) {
    write_score(actual_info->score);
    actual_info->high_score = actual_info->score;
  }
}

void initialize_game(ModelInfo_t *actual_info) {
  if (actual_info->hold) {
    switch (actual_info->user_action) {
      case Start:
        reset_matrix(actual_info->field_base, FIELD_HEIGHT, FIELD_WIDTH);
        actual_info->score = 0;
        actual_info->level = 1;
        actual_info->speed = 0;
        actual_info->pause = NOT_PAUSED;
        actual_info->high_score = read_score();
        actual_info->state = Spawn;
        break;
      case Terminate:
        actual_info->state = Exit_state;
        break;
      default:
        break;
    }
  }
}

void run_terminate_actions(ModelInfo_t *actual_info) {
  // update_high_score(actual_info);
  if (actual_info->field_base) {
    remove_matrix(&actual_info->field_base, FIELD_HEIGHT);
  }
  if (actual_info->current_tetramino) {
    remove_matrix(&actual_info->current_tetramino, TETR_SIZE);
  }
  if (actual_info->next_tetramino) {
    remove_matrix(&actual_info->next_tetramino, TETR_SIZE);
  }
  if (actual_info->collision_test_tetramino) {
    remove_matrix(&actual_info->collision_test_tetramino, TETR_SIZE);
  }
  actual_info->pause = PAUSE_EXIT_GAME;
}

void userInput(UserAction_t action, bool hold) {
  ModelInfo_t *actual_info = get_info();
  actual_info->user_action = action;
  actual_info->hold = hold;
}

GameInfo_t updateCurrentState() {  // для запроса состояния от бэка к фронту

  ModelInfo_t *actual_info = get_info();
  GameInfo_t result = {NULL, NULL, 0, 0, 1, 0, 0};
  int error = 0;

  if (!result.field)
    error += create_matrix(&result.field, FIELD_HEIGHT, FIELD_WIDTH);

  if (!result.next) error += create_matrix(&result.next, TETR_SIZE, TETR_SIZE);

  if (!error) {
    run_actions_by_state(actual_info);
  } else {
    run_terminate_actions(actual_info);
    free_game_info(&result);
  }
  result.pause = actual_info->pause;

  if (actual_info->pause != PAUSE_EXIT_GAME) {
    copy_matrix(result.field, actual_info->field_base, FIELD_HEIGHT,
                FIELD_WIDTH);
    copy_matrix(result.next, actual_info->next_tetramino, TETR_SIZE, TETR_SIZE);
    set_tetramino_on_field(result.field, actual_info);

    result.score = actual_info->score;
    result.high_score = actual_info->high_score;
    result.level = actual_info->level;
    result.speed = actual_info->speed;
  } else {
    free_game_info(&result);
  }

  return result;
}

ModelInfo_t *get_info() {
  static ModelInfo_t actual_info;
  static bool is_initialized = false;
  if (!is_initialized) {
    int error = 0;
    actual_info.state = Start_state;
    actual_info.user_action = Up;
    actual_info.hold = false;
    error += create_matrix(&actual_info.field_base, FIELD_HEIGHT, FIELD_WIDTH);
    error += create_matrix(&actual_info.next_tetramino, TETR_SIZE, TETR_SIZE);
    actual_info.next_type = generate_next_tetramino(actual_info.next_tetramino);
    error +=
        create_matrix(&actual_info.current_tetramino, TETR_SIZE, TETR_SIZE);
    error += create_matrix(&actual_info.collision_test_tetramino, TETR_SIZE,
                           TETR_SIZE);
    actual_info.current_type = 0;
    actual_info.x_position = SPAWN_X_POSITION;
    actual_info.y_position = SPAWN_Y_POSITION;
    actual_info.score = 0;
    actual_info.high_score = read_score();
    actual_info.level = 1;
    actual_info.speed = 0;
    actual_info.pause = error ? PAUSE_EXIT_GAME : NOT_PAUSED;
    actual_info.timer = update_timer();

    srand(time(NULL));

    is_initialized = true;
  }

  return &actual_info;
}
