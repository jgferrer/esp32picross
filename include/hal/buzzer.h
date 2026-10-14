#ifndef HAL_BUZZER_H
#define HAL_BUZZER_H

#include <Arduino.h>

void buzzer_init();
void buzzer_set_enabled(bool enabled);
bool buzzer_is_enabled();

void buzzer_beep(uint32_t freq, uint32_t duration_ms);
void buzzer_click();
void buzzer_fill();
void buzzer_cross();
void buzzer_erase();
void buzzer_line_complete();
void buzzer_hint();
void buzzer_victory();

#endif // HAL_BUZZER_H
