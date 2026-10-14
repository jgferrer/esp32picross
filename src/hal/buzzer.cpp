#include "hal/buzzer.h"
#include "config.h"

static bool sound_enabled = true;

void buzzer_init() {
    ledcSetup(BUZZER_CHANNEL, 2000, 8);
    ledcAttachPin(BUZZER_PIN, BUZZER_CHANNEL);
    ledcWrite(BUZZER_CHANNEL, 0);
}

void buzzer_set_enabled(bool enabled) {
    sound_enabled = enabled;
    if (!sound_enabled) {
        ledcWrite(BUZZER_CHANNEL, 0);
    }
}

bool buzzer_is_enabled() {
    return sound_enabled;
}

void buzzer_beep(uint32_t freq, uint32_t duration_ms) {
    if (!sound_enabled || freq == 0) {
        ledcWrite(BUZZER_CHANNEL, 0);
        return;
    }
    ledcWriteTone(BUZZER_CHANNEL, freq);
    delay(duration_ms);
    ledcWrite(BUZZER_CHANNEL, 0);
}

void buzzer_click() {
    buzzer_beep(2200, 8);
}

void buzzer_fill() {
    if (!sound_enabled) return;
    ledcWriteTone(BUZZER_CHANNEL, 880);
    delay(12);
    ledcWriteTone(BUZZER_CHANNEL, 1320);
    delay(15);
    ledcWrite(BUZZER_CHANNEL, 0);
}

void buzzer_cross() {
    buzzer_beep(1800, 10);
}

void buzzer_erase() {
    if (!sound_enabled) return;
    ledcWriteTone(BUZZER_CHANNEL, 600);
    delay(10);
    ledcWriteTone(BUZZER_CHANNEL, 400);
    delay(10);
    ledcWrite(BUZZER_CHANNEL, 0);
}

void buzzer_line_complete() {
    if (!sound_enabled) return;
    ledcWriteTone(BUZZER_CHANNEL, 1046); // C6
    delay(30);
    ledcWriteTone(BUZZER_CHANNEL, 1318); // E6
    delay(35);
    ledcWriteTone(BUZZER_CHANNEL, 1568); // G6
    delay(45);
    ledcWrite(BUZZER_CHANNEL, 0);
}

void buzzer_hint() {
    if (!sound_enabled) return;
    ledcWriteTone(BUZZER_CHANNEL, 1200);
    delay(20);
    ledcWriteTone(BUZZER_CHANNEL, 1600);
    delay(25);
    ledcWriteTone(BUZZER_CHANNEL, 2000);
    delay(30);
    ledcWrite(BUZZER_CHANNEL, 0);
}

void buzzer_victory() {
    if (!sound_enabled) return;
    // Fanfarria clásica alegre estilo Nintendo
    const uint16_t melody[] = { 1046, 1318, 1568, 2093, 1760, 2093 };
    const uint8_t duration[] = { 60,   60,   60,  120,   80,  250 };
    for (size_t i = 0; i < sizeof(melody)/sizeof(melody[0]); i++) {
        ledcWriteTone(BUZZER_CHANNEL, melody[i]);
        delay(duration[i]);
        ledcWrite(BUZZER_CHANNEL, 0);
        delay(15);
    }
}
