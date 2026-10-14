#ifndef HAL_LED_H
#define HAL_LED_H

#include <Arduino.h>

void led_init();
void led_set(bool r, bool g, bool b);
void led_playing();
void led_victory();
void led_hint();
void led_off();

#endif // HAL_LED_H
