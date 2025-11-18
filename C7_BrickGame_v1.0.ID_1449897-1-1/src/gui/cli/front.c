#include "front.h"

int main() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);
  nodelay(stdscr, TRUE);
  run_game_loop();

  endwin();
  return 0;
}

bool run_game_loop() {
  UserAction_t user_action;
  bool is_ok = true;
  Interface_t windows;
  windows.welcome_win = newwin(FIELD_HEIGHT + 2, FIELD_WIDTH * 4 - 1, 1, 1);
  windows.game_win = newwin(FIELD_WIDTH * 2 + 2, FIELD_HEIGHT + 2, 1, 1);
  windows.next_win = newwin(7, 17, 1, FIELD_WIDTH * 2 + 3);
  windows.info_win = newwin(15, 17, 8, FIELD_WIDTH * 2 + 3);

  start_color();
  init_pair((short)1, COLOR_BLACK, COLOR_CYAN);
  init_pair((short)2, COLOR_BLACK, COLOR_YELLOW);
  init_pair((short)3, COLOR_BLACK, COLOR_RED);
  init_pair((short)4, COLOR_BLACK, COLOR_GREEN);
  init_pair((short)5, COLOR_BLACK, COLOR_MAGENTA);
  init_pair((short)6, COLOR_BLACK, COLOR_BLUE);
  init_pair((short)7, COLOR_BLACK, COLOR_WHITE);
  int start = 0;

  while (is_ok) {
    GameInfo_t gameInfo = updateCurrentState();
    int key = ERR;
    while (!start) {
      print_welcome_info(&windows);
      int input = getch();
      if (input == 10) {
        key = input;
        start = 1;
        werase(windows.welcome_win);
      } else if (input == 'q' || input == 'Q') {
        is_ok = false;
        start = 1;
      }
      napms(200);
    }

    if (gameInfo.pause != EXIT_GAME) {
      print_field(&gameInfo, &windows);
      print_next(&gameInfo, &windows);
      print_info(&gameInfo, &windows);
      bool hold;
      if (key != ERR) {
        hold = true;
        user_action = get_action(key);

      } else {
        key = getch();
        hold = (key != ERR);
        user_action = get_action(key);
      }

      userInput(user_action, hold);
      free_game_info_f(&gameInfo);

      refresh();
      napms(5);
    } else
      is_ok = false;
  }
  delwin(windows.welcome_win);
  delwin(windows.game_win);
  delwin(windows.next_win);
  delwin(windows.info_win);

  return 0;
}
void free_game_info_f(GameInfo_t *gameInfo) {
  if (gameInfo == NULL) return;

  if (gameInfo->field != NULL) {
    for (int i = 0; i < FIELD_HEIGHT; i++) {
      if (gameInfo->field[i] != NULL) {
        free(gameInfo->field[i]);
        gameInfo->field[i] = NULL;
      }
    }
    free(gameInfo->field);
    gameInfo->field = NULL;
  }

  if (gameInfo->next != NULL) {
    for (int i = 0; i < TETR_SIZE; i++) {
      if (gameInfo->next[i] != NULL) {
        free(gameInfo->next[i]);
        gameInfo->next[i] = NULL;
      }
    }
    free(gameInfo->next);
    gameInfo->next = NULL;
  }
}

void print_welcome_info(Interface_t *windows) {
  werase(windows->welcome_win);
  box(windows->welcome_win, 0, 0);

  const char title[] = "= T E T R I S =";
  int color = 1;
  for (int i = 0; i < (int)strlen(title); i++) {
    char sym = title[i];
    if (sym != ' ' && sym != '=')
      wattron(windows->welcome_win, COLOR_PAIR(++color));
    mvwaddch(windows->welcome_win, 5, 12 + i, sym);
    wattroff(windows->welcome_win, COLOR_PAIR(1 + i));
  }

  mvwprintw(windows->welcome_win, 7, 10, "press Enter to start");
  mvwprintw(windows->welcome_win, 10, 16, "Controls");
  mvwprintw(windows->welcome_win, 12, 13, "< arrow keys >");
  mvwprintw(windows->welcome_win, 13, 19, "v");
  mvwprintw(windows->welcome_win, 16, 9, "press 'space' to rotate");

  wrefresh(windows->welcome_win);
}
void print_field(const GameInfo_t *gameInfo, Interface_t *windows) {
  werase(windows->game_win);
  box(windows->game_win, 0, 0);
  for (int y = 0; y < FIELD_HEIGHT; ++y) {
    for (int x = 0; x < FIELD_WIDTH; ++x) {
      if (gameInfo->field[y][x]) {
        if (gameInfo->pause) {
          mvwaddch(windows->game_win, y + 1, x * 2 + 1, '[');
          mvwaddch(windows->game_win, y + 1, x * 2 + 2, ']');
        } else {
          wattron(windows->game_win, COLOR_PAIR(gameInfo->field[y][x]));
          mvwaddch(windows->game_win, y + 1, x * 2 + 1, ' ');
          mvwaddch(windows->game_win, y + 1, x * 2 + 2, ' ');
          wattroff(windows->game_win, COLOR_PAIR(gameInfo->field[y][x]));
        }
      } else {
        mvwaddch(windows->game_win, y + 1, x * 2 + 1, ' ');
        mvwaddch(windows->game_win, y + 1, x * 2 + 2, ' ');
      }
    }
  }
  wrefresh(windows->game_win);
}

void print_next(const GameInfo_t *gameInfo, Interface_t *windows) {
  werase(windows->next_win);
  box(windows->next_win, 0, 0);
  for (int y = 0; y < TETR_SIZE; ++y) {
    for (int x = 0; x < TETR_SIZE; ++x) {
      if (gameInfo->next[y][x]) {
        if (gameInfo->pause) {
          mvwaddch(windows->next_win, y + 1, x * 2 + 4, '[');
          mvwaddch(windows->next_win, y + 1, x * 2 + 5, ']');
        } else {
          wattron(windows->next_win, COLOR_PAIR(gameInfo->next[y][x]));
          mvwaddch(windows->next_win, y + 1, x * 2 + 4, ' ');
          mvwaddch(windows->next_win, y + 1, x * 2 + 5, ' ');
          wattroff(windows->next_win, COLOR_PAIR(gameInfo->next[y][x]));
        }
      } else {
        mvwaddch(windows->next_win, y + 1, x * 2 + 4, ' ');
        mvwaddch(windows->next_win, y + 1, x * 2 + 5, ' ');
      }
    }
  }

  wrefresh(windows->next_win);
}

void print_info(const GameInfo_t *gameInfo, Interface_t *windows) {
  int offset_high = score_offset_counter(gameInfo->high_score);
  int offset = score_offset_counter(gameInfo->score);
  werase(windows->info_win);
  box(windows->info_win, 0, 0);
  if (gameInfo->pause == PAUSE_ACTIVATED) {
    mvwprintw(windows->info_win, 1, 4, "= PAUSE =");
    mvwprintw(windows->info_win, 3, 4, "press  'P'");
    mvwprintw(windows->info_win, 4, 4, "to  resume");
  } else if (gameInfo->pause == PAUSE_GAME_OVER) {
    mvwprintw(windows->info_win, 1, 3, "=GAME OVER=");
    mvwprintw(windows->info_win, 3, 3, "press 'ENTER'");
    mvwprintw(windows->info_win, 4, 5, "to start");
  }
  if (gameInfo->pause) {
    mvwprintw(windows->info_win, 5, 4, "press 'Q'");
    mvwprintw(windows->info_win, 6, 5, "to exit");
    mvwprintw(windows->info_win, 8, 3, "High score:");
    wattron(windows->info_win, COLOR_PAIR(2));
    mvwprintw(windows->info_win, 9, 8 - offset_high, "%d",
              gameInfo->high_score);
    wattroff(windows->info_win, COLOR_PAIR(2));
    mvwprintw(windows->info_win, 11, 6, "Score:");
    mvwprintw(windows->info_win, 12, 8 - offset, "%d", gameInfo->score);

  } else {
    mvwprintw(windows->info_win, 1, 2, "'P' for pause");
    mvwprintw(windows->info_win, 3, 3, "high score");
    mvwprintw(windows->info_win, 4, 8 - offset_high, "%d",
              gameInfo->high_score);
    mvwprintw(windows->info_win, 5, 6, "score");
    mvwprintw(windows->info_win, 6, 8 - offset, "%d", gameInfo->score);
    mvwprintw(windows->info_win, 8, 6, "speed");
    mvwprintw(windows->info_win, 9, 6, "%3.1f x",
              (float)gameInfo->speed * 0.3 + 1);
    mvwprintw(windows->info_win, 11, 6, "level");
    mvwprintw(windows->info_win, 12, 4, "%5d", gameInfo->level);
  }
  wrefresh(windows->info_win);
}

UserAction_t get_action(int key) {
  UserAction_t action;
  switch (key) {
    case ENTER_KEY:
      action = Start;
      break;
    case 'p':
    case 'P':
      action = Pause;
      break;
    case 'q':
    case 'Q':
      action = Terminate;
      break;
    case KEY_LEFT:
      action = Left;
      break;
    case KEY_RIGHT:
      action = Right;
      break;
    case KEY_DOWN:
      action = Down;
      break;
    case SPACE_KEY:
      action = Action;
      break;
    case KEY_UP:
      action = Up;
      break;
      // default:
      break;
  }
  return action;
}

int score_offset_counter(int number) {
  int count = 0;

  while (number > 0) {
    count++;
    number /= 10;
  }

  return count / 2;
}
