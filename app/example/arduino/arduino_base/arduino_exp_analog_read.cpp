/*
 * Copyright (C) 2019 MRNIU
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdio.h>

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include <arduino_exp_base.h>

void arduino_exp_ana_read(void)
{
    gpio_dev_t analogPin;
    analogPin.port = PORT_ADC1;
    int val = 0;

    val = analogRead(&analogPin);
    printf("val = %d\n", val);

    return;
}
