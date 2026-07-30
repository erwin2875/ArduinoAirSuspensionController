#ifndef _TOUCH_FT6336_H_
#define _TOUCH_FT6336_H_

#include <Arduino.h>
#include <Wire.h>
#include <lvgl.h>

namespace Touch_FT6336 {
    void begin();
    bool lv_read(lv_indev_drv_t *drv, lv_indev_data_t *data); // LVGL indev read callback
}

#endif // _TOUCH_FT6336_H_
