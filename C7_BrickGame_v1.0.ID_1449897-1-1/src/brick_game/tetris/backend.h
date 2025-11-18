/**
 * @file backend.h
 * @brief Заголовочный файл бэкенда игры Тетрис
 * @defgroup backend_module Модуль бэкенда
 * @{
 */

#ifndef BACKEND_H
#define BACKEND_H

#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#include "../brick_game.h"

// Размеры игрового поля
#define FIELD_WIDTH 10  /**< Ширина игрового поля */
#define FIELD_HEIGHT 20 /**< Высота игрового поля */
#define TETR_SIZE 5     /**< Размер матрицы для тетрамино */

// Позиция спавна фигур
#define SPAWN_X_POSITION 3  /**< X-координата спавна фигуры */
#define SPAWN_Y_POSITION -2 /**< Y-координата спавна фигуры */

/**
 * @brief Типы коллизий
 */
typedef enum CollisionType_t {
  COLLISION_NONE,  /**< Коллизии нет */
  COLLISION_BASE,  /**< Коллизия с установленными фигурами */
  COLLISION_FLOOR, /**< Коллизия с полом */
  COLLISION_LEFT,  /**< Коллизия с левой стенкой */
  COLLISION_RIGHT, /**< Коллизия с правой стенкой */
} CollisionType_t;

/**
 * @brief Состояния паузы
 */
typedef enum PauseState {
  PAUSE_EXIT_GAME = -1, /**< Игра завершена */
  NOT_PAUSED,           /**< Игра не на паузе */
  PAUSE_ACTIVATED,      /**< Пауза активирована */
  PAUSE_GAME_OVER       /**< Game over экран */
} PauseState;

/**
 * @brief Типы тетрамино
 */
typedef enum TetraminoType_t {
  TETRO_O = 1, /**< Квадратная фигура */
  TETRO_I,     /**< Длинная палка */
  TETRO_T,     /**< T-образная фигура */
  TETRO_S,     /**< S-образная фигура */
  TETRO_Z,     /**< Z-образная фигура */
  TETRO_J,     /**< J-образная фигура */
  TETRO_L      /**< L-образная фигура */
} TetraminoType_t;

/**
 * @brief Конечные состояния игры
 */
typedef enum FiniteState_t {
  Start_state, /**< Начальное состояние */
  Spawn,       /**< Появление новой фигуры */
  Moving,      /**< Движение фигуры */
  Attaching,   /**< Прикрепление фигуры */
  Game_over,   /**< Конец игры */
  Pause_state, /**< Состояние паузы */
  Exit_state   /**< Выход из игры */
} FiniteState_t;

/**
 * @brief Структура информации о модели игры
 *
 * Содержит всю внутреннюю логику и состояние игры
 */
typedef struct ModelInfo_t {
  FiniteState_t state;            /**< Текущее состояние игры */
  UserAction_t user_action;       /**< Последнее действие пользователя */
  bool hold;                      /**< Флаг удержания клавиши */
  int **field_base;               /**< Базовое игровое поле */
  int **next_tetramino;           /**< Следующая фигура */
  TetraminoType_t next_type;      /**< Тип следующей фигуры */
  int **current_tetramino;        /**< Текущая фигура */
  int **collision_test_tetramino; /**< Фигура для теста коллизий */
  TetraminoType_t current_type;   /**< Тип текущей фигуры */
  int x_position;                 /**< X-позиция текущей фигуры */
  int y_position;                 /**< Y-позиция текущей фигуры */
  int score;                      /**< Текущий счет */
  int high_score;                 /**< Рекордный счет */
  int level;                      /**< Текущий уровень */
  int speed;                      /**< Скорость игры */
  int pause;                      /**< Состояние паузы */
  long long int timer;            /**< Таймер для управления скоростью */
} ModelInfo_t;

// Прототипы функций
ModelInfo_t *get_info();

int create_matrix(int ***matrix, int rows, int columns);
void remove_matrix(int ***matrix, int rows);
void copy_matrix(int **dest, int **src, int rows, int columns);
void reset_matrix(int **src, int rows, int columns);

long long int update_timer();
void write_score(int high_score);
int read_score();
void free_game_info(GameInfo_t *game_info);

void fill_tetramino(int **filled, TetraminoType_t num);
void set_tetramino_on_field(int **field, ModelInfo_t *actual_info);
void spawn_tetramino(ModelInfo_t *actual_info);
TetraminoType_t generate_next_tetramino(int **next);

CollisionType_t is_move_collision(const ModelInfo_t *actual_info);
CollisionType_t check_rotate_collision(const ModelInfo_t *actual_info);
CollisionType_t is_rotation_blocked();
CollisionType_t i_wall_kick(ModelInfo_t *actual_info, CollisionType_t collision,
                            int original_x);
CollisionType_t wall_kick(ModelInfo_t *actual_info, CollisionType_t collision);

void rotate_matrix_90(int ***matrix);
void move_left(ModelInfo_t *actual_info);
void move_right(ModelInfo_t *actual_info);
void move_tetramino(ModelInfo_t *actual_info);
void shift_tetramino(ModelInfo_t *actual_info);
void attach_tetramino(ModelInfo_t *actual_info);

void game_over_actions(ModelInfo_t *actual_info);
void calculate_lines(ModelInfo_t *actual_info);
void clear_line(int **field_base, int line);
void update_score(ModelInfo_t *actual_info, int cleard_lines);
void update_high_score(ModelInfo_t *actual_info);
void update_speed_and_level(ModelInfo_t *actual_info);

void run_actions_by_state(ModelInfo_t *actual_info);
void initialize_game(ModelInfo_t *actual_info);
void pause_actions(ModelInfo_t *actual_info);
void run_terminate_actions(ModelInfo_t *actual_info);

#endif
