/*
 * Copyright (C) 2019 MRNIU
 */

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

#include <stdio.h>

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include <arduino_exp_base.h>

extern "C" int application_start(int argc, char *argv[]);

int application_start(int argc, char *argv[])
{
    printf("Test Begin !\n");

    // arduino_exp_dig_read();
    // arduino_exp_dig_write();
    arduino_exp_dig_pinmode();

    // arduino_exp_ana_read();
    // arduino_exp_ana_write();

    // arduino_exp_time_millis();
    // arduino_exp_time_micros();
    // arduino_exp_time_delay();
    // arduino_exp_time_delayMicroseconds();

    printf("Test End !\n");

    return 0;
}
