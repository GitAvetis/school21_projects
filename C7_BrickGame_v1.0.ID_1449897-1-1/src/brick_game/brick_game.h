/**
 * @page fsm_page Finite State Machine
 * @image html "FSM.png" "Диаграмма КА" width=900px
 */
/**
 * @file brick_game.h
 * @brief Основной заголовочный файл игр типа Brick game
 * @defgroup game_core Основной модуль игры
 * @{
 */

#ifndef BRICK_GAME_H
#define BRICK_GAME_H

/**
 * @brief Действия пользователя
 *
 * Перечисление всех возможных действий, которые может совершить пользователь
 */
typedef enum {
  Start,     /**< Начать игру */
  Pause,     /**< Приостановить игру */
  Terminate, /**< Завершить игру */
  Left,      /**< Движение влево */
  Right,     /**< Движение вправо */
  Up,        /**< Движение вверх (не используется) */
  Down,      /**< Ускоренное падение */
  Action     /**< Поворот фигуры */
} UserAction_t;

/**
 * @brief Структура информации об игре
 *
 * Содержит всю информацию о текущем состоянии игры для отображения
 */
typedef struct {
  int **field;    /**< Игровое поле 20x10 */
  int **next;     /**< Следующая фигура */
  int score;      /**< Текущий счет */
  int high_score; /**< Рекордный счет */
  int level;      /**< Текущий уровень */
  int speed;      /**< Скорость игры */
  int pause;      /**< Состояние паузы */
} GameInfo_t;

/**
 * @brief Обновляет текущее состояние игры
 * @return GameInfo_t Структура с информацией об игре
 *
 * @note Эта функция вызывается фронтендом для получения актуального состояния
 */
GameInfo_t updateCurrentState();

/**
 * @brief Обрабатывает пользовательский ввод
 * @param action Действие пользователя
 * @param hold Флаг удержания клавиши
 *
 * @warning Не вызывать напрямую, использовать только через фронтенд
 */
void userInput(UserAction_t action, bool hold);

#endif
/** @} */
