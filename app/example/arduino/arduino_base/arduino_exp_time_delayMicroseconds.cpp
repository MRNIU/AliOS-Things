/*
 * Copyright (C) 2019 MRNIU
 */

#include <arduino_exp_base.h>

void arduino_exp_time_delayMicroseconds(void)
{
    gpio_dev_t outPin;
    pinMode(&outPin, HAL_GPIO_55,OUTPUT);
    digitalWrite(&outPin, HIGH);

    delayMicroseconds(50);
    digitalWrite(&outPin, LOW);
    delayMicroseconds(50);
    
    return;
}