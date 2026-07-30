#pragma once

#include "pins.h"

// Board-specific configuration for Waveshare ESP32-Touch-LCD-3.5 (ESP32-D0WDR2-V3)

// Display geometry
#define TFT_WIDTH   320
#define TFT_HEIGHT  480
#define TFT_ROTATION 1

// LVGL settings
#define LVGL_COLOR_DEPTH 16

// Touch
#define FT6336_I2C_ADDR 0x38

// Backlight PWM settings (optional)
#define BACKLIGHT_LEDC_CHANNEL 0
#define BACKLIGHT_LEDC_FREQ 5000
#define BACKLIGHT_LEDC_RESOLUTION 8

// Other board feature toggles
#define WAVESHARE_BOARD_3P5 1

// Helper: check for PSRAM availability at runtime
static inline bool boardHasPSRAM() {
#if CONFIG_ESP32_SPIRAM_SUPPORT
    return true;
#else
    return false;
#endif
}
