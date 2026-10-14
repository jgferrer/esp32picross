#include <Arduino.h>
#include "config.h"
#include "hal/display.h"
#include "hal/buzzer.h"
#include "hal/led.h"
#include "game/storage.h"
#include "game/picross_game.h"
#include "ui/renderer.h"

void setup() {
    Serial.begin(115200);
    delay(150);
    Serial.println("\n==========================================");
    Serial.println("   ★ ESP-PICROSS RETRO (ESP32-CYD) ★     ");
    Serial.println("==========================================");

    storage_init();
    buzzer_init();
    buzzer_set_enabled(storage_get_sound());
    led_init();
    display_init();
    renderer_init();
    game.init();

    renderer_draw_screen(true);
    Serial.println("[MAIN] Juego inicializado con exito.");
}

void loop() {
    uint16_t touchX, touchY;
    bool touched = tft.getTouch(&touchX, &touchY);

    static bool was_touched = false;

    if (touched) {
        if (!was_touched) {
            was_touched = true;
            game.handle_touch_down((int16_t)touchX, (int16_t)touchY);
            renderer_draw_screen(false);
        } else {
            game.handle_touch_move((int16_t)touchX, (int16_t)touchY);
        }
    } else {
        if (was_touched) {
            was_touched = false;
            game.handle_touch_up();
            renderer_draw_screen(false);
        }
    }

    game.update_timer();
    renderer_draw_timer_only();

    delay(5);
}
