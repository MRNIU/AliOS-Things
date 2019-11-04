/*
 * Copyright (C) 2019 MRNIU
 */

#include <arduino_exp_base.h>

void arduino_exp_dig_pinmode(void)
{
    gpio_dev_t pin;
    pinMode(&pin, LED_2, OUTPUT);

    while(1) {
        digitalWrite(&pin, HIGH);
        delay(1000);
        digitalWrite(&pin, LOW);
        delay(1000);
    }
    
    return;
}