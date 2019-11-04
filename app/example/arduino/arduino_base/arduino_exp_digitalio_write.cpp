/*
 * Copyright (C) 2019 MRNIU
 */

#include <arduino_exp_base.h>

void arduino_exp_dig_write(void)
{
    gpio_dev_t writePin;
    pinMode(&writePin, LED_2, OUTPUT);

    while(1) {
        digitalWrite(&writePin, HIGH);
        delay(1000);
        digitalWrite(&writePin, LOW);
        delay(1000);
    }

    return;
}