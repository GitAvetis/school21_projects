#include "test.h"

START_TEST(Game_over_test) {
  ModelInfo_t *actual_info = get_info();
  actual_info->state = Game_over;
  run_actions_by_state(actual_info);

  ck_assert_int_eq(actual_info->pause, PAUSE_GAME_OVER);
  ck_assert_int_eq(actual_info->state, Start_state);

  for (int y = FIELD_HEIGHT - 1; y < FIELD_HEIGHT; y++) {
    for (int x = 0; x < FIELD_WIDTH; x++) {
      (actual_info->field_base[y][x] = 1);
    }
  }
  actual_info->state = Attaching;
  actual_info->score = 0;
  run_actions_by_state(actual_info);

  ck_assert_int_eq(actual_info->score, 100);
  actual_info->score = 0;
}
END_TEST

START_TEST(pause_actions_test) {
  ModelInfo_t *actual_info = get_info();
  actual_info->state = Pause_state;
  actual_info->user_action = Pause;
  actual_info->hold = true;
  run_actions_by_state(actual_info);

  ck_assert_int_eq(actual_info->pause, NOT_PAUSED);
  ck_assert_int_eq(actual_info->state, Moving);

  actual_info->state = Pause_state;
  actual_info->user_action = Terminate;
  run_actions_by_state(actual_info);

  ck_assert_int_eq(actual_info->state, Exit_state);
}
END_TEST

START_TEST(attach_tetramino_test) {
  ModelInfo_t *actual_info = get_info();
  fill_tetramino(actual_info->next_tetramino, TETRO_T);
  fill_tetramino(actual_info->next_tetramino, TETRO_L);
  fill_tetramino(actual_info->next_tetramino, TETRO_J);
  fill_tetramino(actual_info->next_tetramino, TETRO_Z);
  fill_tetramino(actual_info->next_tetramino, TETRO_S);
  actual_info->current_type = TETRO_O;
  fill_tetramino(actual_info->next_tetramino, TETRO_O);
  actual_info->state = Spawn;
  run_actions_by_state(actual_info);
  actual_info->x_position = -2;
  actual_info->y_position = 0;
  actual_info->state = Moving;
  run_actions_by_state(actual_info);
  ck_assert_int_eq(is_move_collision(actual_info), COLLISION_BASE);
  reset_matrix(actual_info->next_tetramino, TETR_SIZE, TETR_SIZE);

  actual_info->current_type = TETRO_I;
  fill_tetramino(actual_info->next_tetramino, TETRO_I);
  actual_info->state = Spawn;
  run_actions_by_state(actual_info);
  actual_info->x_position = FIELD_WIDTH + 2;
  actual_info->y_position = 0;
  actual_info->state = Moving;
  run_actions_by_state(actual_info);
  ck_assert_int_eq(is_move_collision(actual_info), COLLISION_BASE);
}
END_TEST

START_TEST(shifting_test) {
  ModelInfo_t *actual_info = get_info();
  actual_info->current_type = TETRO_S;
  fill_tetramino(actual_info->next_tetramino, TETRO_S);
  actual_info->state = Spawn;
  run_actions_by_state(actual_info);

  actual_info->x_position = -100;
  actual_info->y_position = 0;
  ck_assert_int_eq(is_move_collision(actual_info), COLLISION_BASE);
  actual_info->x_position = 0;
  actual_info->y_position = 22;
  ck_assert_int_eq(is_move_collision(actual_info), COLLISION_FLOOR);
  actual_info->x_position = 0;
  actual_info->y_position = FIELD_HEIGHT;
  run_actions_by_state(actual_info);
}
END_TEST
START_TEST(moving_test) {
  ModelInfo_t *actual_info = get_info();

  actual_info->state = Spawn;
  run_actions_by_state(actual_info);
  actual_info->state = Moving;
  actual_info->user_action = Left;
  actual_info->hold = true;
  run_actions_by_state(actual_info);
  ck_assert_int_eq(actual_info->x_position, SPAWN_X_POSITION - 1);
  actual_info->user_action = Right;
  run_actions_by_state(actual_info);
  ck_assert_int_eq(actual_info->x_position, SPAWN_X_POSITION);

  actual_info->user_action = Action;
  run_actions_by_state(actual_info);
  for (int i = 0; i < TETR_SIZE; i++) {
    for (int j = 0; j < TETR_SIZE; j++) {
      ck_assert_int_eq(actual_info->current_tetramino[i][j],
                       actual_info->collision_test_tetramino[i][j]);
    }
  }
  actual_info->state = Moving;
  actual_info->user_action = Pause;
  run_actions_by_state(actual_info);
  ck_assert_int_eq(actual_info->state, Pause_state);
  ck_assert_int_eq(actual_info->pause, PAUSE_ACTIVATED);

  actual_info->state = Moving;
  actual_info->user_action = Terminate;
  run_actions_by_state(actual_info);
  ck_assert_int_eq(actual_info->state, Pause_state);

  actual_info->state = Moving;
  actual_info->user_action = Down;
  run_actions_by_state(actual_info);
}

START_TEST(initialize_game_test) {
  ModelInfo_t *actual_info = get_info();
  actual_info->state = Start_state;
  actual_info->hold = true;
  actual_info->user_action = Start;
  write_score(0);
  run_actions_by_state(actual_info);
  ck_assert_int_eq(actual_info->score, 0);
  ck_assert_int_eq(actual_info->level, 1);
  ck_assert_int_eq(actual_info->speed, 0);
  ck_assert_int_eq(actual_info->pause, NOT_PAUSED);
  ck_assert_int_eq(actual_info->high_score, 0);
  ck_assert_int_eq(actual_info->state, Spawn);
  reset_matrix(actual_info->field_base, FIELD_HEIGHT, FIELD_WIDTH);
  for (int i = 0; i < FIELD_HEIGHT; i++) {
    for (int j = 0; j < FIELD_WIDTH; j++) {
      ck_assert_int_eq(actual_info->field_base[i][j], 0);
    }
  }
}
END_TEST

START_TEST(spawn_tetramino_test) {
  ModelInfo_t *actual_info = get_info();
  actual_info->state = Spawn;
  run_actions_by_state(actual_info);
  ck_assert_int_eq(actual_info->x_position, SPAWN_X_POSITION);
  ck_assert_int_eq(actual_info->y_position, SPAWN_Y_POSITION);
}
END_TEST

START_TEST(input_test) {
  ModelInfo_t *actual_info = get_info();
  actual_info->pause = 1;
  actual_info->state = Pause_state;
  userInput(Pause, true);
  ck_assert_int_eq(actual_info->user_action, Pause);
  ck_assert_int_eq(actual_info->hold, true);
  userInput(Up, false);
  ck_assert_int_eq(actual_info->user_action, Up);
  ck_assert_int_eq(actual_info->hold, false);
}
END_TEST

START_TEST(score_and_high_score_test) {
  ModelInfo_t *actual_info = get_info();
  actual_info->score = 100;
  ck_assert_int_eq(actual_info->high_score, 0);
  actual_info->high_score = 2000;
  update_high_score(actual_info);
  ck_assert_int_eq(actual_info->high_score, 2000);
  update_score(actual_info, 1);
  ck_assert_int_eq(actual_info->score, 200);
  update_score(actual_info, 2);
  ck_assert_int_eq(actual_info->score, 500);
  update_score(actual_info, 3);
  ck_assert_int_eq(actual_info->score, 1200);
  update_score(actual_info, 4);
  ck_assert_int_eq(actual_info->score, 2700);
  update_high_score(actual_info);
  ck_assert_int_eq(actual_info->high_score, 2700);
  write_score(3000);
  ck_assert_int_eq(read_score(), 3000);
}
END_TEST

START_TEST(update_speed_and_level_test) {
  GameInfo_t game_info = updateCurrentState();
  free_game_info(&game_info);
  ModelInfo_t *actual_info = get_info();
  actual_info->score = 0;
  actual_info->level = 1;
  actual_info->speed = 0;
  update_speed_and_level(actual_info);
  ck_assert_int_eq(actual_info->speed, 0);
  ck_assert_int_eq(actual_info->level, 1);
  actual_info->score = 6000;
  update_speed_and_level(actual_info);
  ck_assert_int_eq(actual_info->speed, 9);
  ck_assert_int_eq(actual_info->level, 10);
}
END_TEST

Suite *tetris(void) {
  Suite *suite = suite_create("tetris");
  TCase *tc_core = tcase_create("tetris");

  tcase_add_test(tc_core, shifting_test);
  tcase_add_test(tc_core, attach_tetramino_test);
  tcase_add_test(tc_core, pause_actions_test);
  tcase_add_test(tc_core, Game_over_test);

  tcase_add_test(tc_core, spawn_tetramino_test);
  tcase_add_test(tc_core, input_test);
  tcase_add_test(tc_core, initialize_game_test);
  tcase_add_test(tc_core, score_and_high_score_test);
  tcase_add_test(tc_core, update_speed_and_level_test);
  tcase_add_test(tc_core, moving_test);
  suite_add_tcase(suite, tc_core);

  return suite;
}
