#ifndef GAME_PICROSS_H
#define GAME_PICROSS_H

#include <Arduino.h>
#include "game/puzzle_data.h"

enum GameState {
    STATE_MENU,
    STATE_PLAYING,
    STATE_VICTORY
};

enum ToolMode {
    TOOL_FILL,  // Pintar casilla (■)
    TOOL_CROSS  // Marcar con cruz (✕)
};

enum CellState : uint8_t {
    CELL_EMPTY   = 0,
    CELL_FILLED  = 1,
    CELL_CROSSED = 2
};

enum DragAction {
    DRAG_NONE,
    DRAG_SET_FILL,
    DRAG_SET_CROSS,
    DRAG_CLEAR
};

class PicrossGame {
public:
    GameState state;
    uint8_t current_level_idx;
    ToolMode tool_mode;
    uint8_t hints_remaining;

    // Estado del tablero actual
    uint8_t grid_size;
    CellState player_grid[MAX_GRID_SIZE][MAX_GRID_SIZE];
    uint8_t row_clues[MAX_GRID_SIZE][MAX_CLUES];
    uint8_t row_clue_counts[MAX_GRID_SIZE];
    uint8_t col_clues[MAX_GRID_SIZE][MAX_CLUES];
    uint8_t col_clue_counts[MAX_GRID_SIZE];

    bool row_satisfied[MAX_GRID_SIZE];
    bool col_satisfied[MAX_GRID_SIZE];

    // Cronómetro
    uint32_t start_time_ms;
    uint32_t elapsed_seconds;
    bool timer_running;

    // Arrastre táctil (Drag & Drop con lápiz)
    bool is_dragging;
    int8_t last_drag_col;
    int8_t last_drag_row;
    DragAction current_drag_action;

    // Métricas del grid en pantalla
    int16_t grid_x;
    int16_t grid_y;
    int16_t cell_size;
    int16_t clue_row_x;
    int16_t clue_col_y;

public:
    void init();
    void load_level(uint8_t level_idx);
    void reset_current_level();
    void use_hint();
    void update_timer();
    void set_tool(ToolMode mode);

    // Entrada táctil
    void handle_touch_down(int16_t tx, int16_t ty);
    void handle_touch_move(int16_t tx, int16_t ty);
    void handle_touch_up();

    bool check_victory();
    void update_clue_satisfaction();

    const Puzzle& get_current_puzzle() const { return PUZZLES[current_level_idx]; }
};

extern PicrossGame game;

#endif // GAME_PICROSS_H
