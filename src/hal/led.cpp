#include "hal/led.h"
#include "config.h"

void led_init() {
    pinMode(LED_RED_PIN, OUTPUT);
    pinMode(LED_GREEN_PIN, OUTPUT);
    pinMode(LED_BLUE_PIN, OUTPUT);
    led_off();
}

void led_set(bool r, bool g, bool b) {
    // Active-LOW logic
    digitalWrite(LED_RED_PIN, r ? LOW : HIGH);
    digitalWrite(LED_GREEN_PIN, g ? LOW : HIGH);
    digitalWrite(LED_BLUE_PIN, b ? LOW : HIGH);
}

void led_playing() {
    // Azul cian suave durante el juego
    led_set(false, false, true);
}

void led_victory() {
    // Verde brillante al completar el puzzle
    led_set(false, true, false);
}

void led_hint() {
    // Amarillo al usar pista
    led_set(true, true, false);
}

void led_off() {
    led_set(false, false, false);
}
