#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// ==========================================
// PANTALLA TFT 2.8" (320x240 / 240x320)
// ==========================================
#define SCREEN_WIDTH    240
#define SCREEN_HEIGHT   320
#define SCREEN_ROTATION 0 // 0 = Vertical nativo (240x320)

// Pines TFT (Bus HSPI)
#define TFT_MISO_PIN   12
#define TFT_MOSI_PIN   13
#define TFT_SCLK_PIN   14
#define TFT_CS_PIN     15
#define TFT_DC_PIN      2
#define TFT_RST_PIN    -1
#define TFT_BL_PIN     21

// Pines Panel Táctil Resistivo XPT2046 (Software SPI)
#define TOUCH_MOSI_PIN 32
#define TOUCH_MISO_PIN 39
#define TOUCH_CLK_PIN  25
#define TOUCH_CS_PIN   33
#define TOUCH_IRQ_PIN  36

// ==========================================
// PERIFÉRICOS
// ==========================================
// LED RGB Integrado (Lógica Active-LOW: LOW=Encendido, HIGH=Apagado)
#define LED_RED_PIN    4
#define LED_GREEN_PIN  16
#define LED_BLUE_PIN   17

// Zumbador / Audio
#define BUZZER_PIN     26
#define BUZZER_CHANNEL  0

// Sensor LDR (Opcional)
#define LDR_PIN        34

// ==========================================
// PALETA DE COLORES RETRO (RGB565)
// ==========================================
#define COLOR_BG          0x18C3 // Azul pizarra oscuro retro (#181828)
#define COLOR_HEADER      0x2126 // Azul marino oscuro (#202434)
#define COLOR_GRID_BG     0xF7BE // Blanco marfil suave (#F7F7F7)
#define COLOR_GRID_LINE   0xAD55 // Gris suave separación celdas
#define COLOR_GRID_MAJOR  0x4208 // Gris azulado oscuro (bloques 5x5)
#define COLOR_FILLED      0x18C3 // Bloque pintado (Azul oscuro / Carbón)
#define COLOR_CROSS       0xD185 // Cruz roja suave (#D03030)
#define COLOR_TEXT        0xFFFF // Blanco
#define COLOR_TEXT_MUTED  0x8410 // Gris medio para números completados
#define COLOR_ACCENT      0x2D7F // Azul celeste brillante para botones
#define COLOR_ACCENT_ACT  0xFDE0 // Amarillo cálido para botón activo
#define COLOR_SUCCESS     0x2EA5 // Verde esmeralda (#2CC050)
#define COLOR_GOLD        0xFDE0 // Dorado cálido

#endif // CONFIG_H
