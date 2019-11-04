/*
 * Copyright (C) 2019 MRNIU
 */

#include <arduino_exp_base.h>

void arduino_exp_time_delay(void)
{
    gpio_dev_t ledPin;
    pinMode(&ledPin, LED_1,OUTPUT);

    digitalWrite(&ledPin, HIGH);
    delay(1000);
    digitalWrite(&ledPin, LOW);
    delay(1000);

    return;
}