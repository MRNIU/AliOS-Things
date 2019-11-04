/*
 * Copyright (C) 2019 MRNIU
 */

#include <arduino_exp_base.h>

void arduino_exp_dig_read(void)
{
    gpio_dev_t ledPin;
    gpio_dev_t inPin;
    int val = 0;

    pinMode(&ledPin, LED_2, OUTPUT);
    pinMode(&inPin, HAL_GPIO_55, INPUT);

    val = digitalRead(&inPin);
    digitalWrite(&ledPin, val);
    
    return;
}
