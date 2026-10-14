#ifndef UI_RENDERER_H
#define UI_RENDERER_H

#include <Arduino.h>
#include "game/picross_game.h"

void renderer_init();
void renderer_draw_screen(bool force_full_redraw = false);
void renderer_draw_timer_only();
void renderer_draw_cell(uint8_t r, uint8_t c);

#endif // UI_RENDERER_H
