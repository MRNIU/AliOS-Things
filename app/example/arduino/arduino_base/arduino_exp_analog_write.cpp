/*
 * Copyright (C) 2019 MRNIU
 */

#include <arduino_exp_base.h>

void arduino_exp_ana_write(void)
{
    gpio_dev_t ledPin;
    gpio_dev_t analogPin;
    analogPin.port = PORT_ADC1;
    int val = 0;

    pinMode(&ledPin, LED_1, OUTPUT);

    val = analogRead(&analogPin);
    analogWrite(&ledPin, val / 4);

    return;
}

