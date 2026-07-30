#include "board_config.h"
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

// Simple ST7796 display init & LVGL flush skeleton
// This is minimal glue to get the display up; adapt to your project's Display_* API

namespace Display_ST7796 {

static SPIClass *spi = NULL;

void begin() {
    if (!spi) spi = new SPIClass(VSPI);
    spi->begin(TFT_SCLK, TFT_MISO, TFT_MOSI, TFT_CS);
    pinMode(TFT_CS, OUTPUT);
    pinMode(TFT_DC, OUTPUT);
    pinMode(TFT_RST, OUTPUT);
    pinMode(TFT_BL, OUTPUT);

    // Hardware reset
    digitalWrite(TFT_RST, LOW);
    delay(20);
    digitalWrite(TFT_RST, HIGH);
    delay(20);

    // Init sequence – placeholder: use Waveshare/ST7796 recommended init
    // You should replace this with the full command sequence from the driver or use LovyanGFX/TFT_eSPI
}

void setBacklight(uint8_t brightness) {
    // Simple on/off for now
    if (brightness == 0) digitalWrite(TFT_BL, LOW);
    else digitalWrite(TFT_BL, HIGH);
}

// LVGL flush callback signature (example)
void lvglFlush(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_p) {
    // TODO: implement SPI write to display memory for the given area
    lv_disp_flush_ready(drv);
}

} // namespace Display_ST7796
