# FT6336 touch driver minimal implementation (I2C + LVGL glue)
#include "Touch_FT6336.h"
#include "pins.h"

namespace Touch_FT6336 {

static TwoWire *i2c = &Wire;

void begin() {
    i2c->begin(TOUCH_SDA, TOUCH_SCL);
}

bool lv_read(lv_indev_drv_t *drv, lv_indev_data_t *data) {
    // Minimal read: poll touch, return single point
    uint8_t buf[10];
    i2c->beginTransmission(FT6336_I2C_ADDR);
    i2c->write(0x02); // POINTS register
    if (i2c->endTransmission(false) != 0) {
        data->state = LV_INDEV_STATE_REL;
        return false;
    }
    if (i2c->requestFrom(FT6336_I2C_ADDR, (uint8_t)7) != 7) {
        data->state = LV_INDEV_STATE_REL;
        return false;
    }
    for (int i = 0; i < 7; ++i) buf[i] = i2c->read();

    uint8_t points = buf[0] & 0x0F;
    if (points == 0) {
        data->state = LV_INDEV_STATE_REL;
        return false;
    }

    // Parse first point
    uint16_t x = ((buf[1] & 0x0F) << 8) | buf[2];
    uint16_t y = ((buf[3] & 0x0F) << 8) | buf[4];

    data->point.x = x;
    data->point.y = y;
    data->state = LV_INDEV_STATE_PR;
    return false; // no more data to read
}

} // namespace Touch_FT6336
