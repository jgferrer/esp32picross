#ifndef GAME_STORAGE_H
#define GAME_STORAGE_H

#include <Arduino.h>

void storage_init();
bool storage_is_completed(uint8_t level_idx);
uint32_t storage_get_best_time(uint8_t level_idx);
void storage_save_completion(uint8_t level_idx, uint32_t time_sec);
uint8_t storage_get_last_level();
void storage_set_last_level(uint8_t level_idx);
bool storage_get_sound();
void storage_set_sound(bool enabled);

#endif // GAME_STORAGE_H
