/*
 * Copyright (C) 2019 MRNIU
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdio.h>
#include <aos/kernel.h>

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include <arduino_exp_wire.h>

extern "C" int application_start(int argc, char *argv[]);

int application_start(int argc, char *argv[])
{
    printf("Test Begin !\n");


    printf("End!\n");

    // arduino_exp_wire_write();
    arduino_exp_wire_read();

    return 0;
}

void arduino_exp_wire_write(void)
{
    byte val = 0;
    Wire.begin();

    while(1){
        Wire.beginTransmission(0x6A);
        Wire.write(val);
        Wire.endTransmission();
        val++;
        if(val == 64) {
            val = 0;
        }
        delay(500);
        printf("AliOS Things is working !\n");
    }
    Wire.end();

    return;
}

void arduino_exp_wire_read(void)
{
    Wire.begin();
    while(1) {
        Wire.requestFrom(2, 6);

        while(Wire.available()) {
            char c = Wire.read();
            printf("%c\n", c);
        }
        delay(500);
        printf("AliOS Things is working !\n");
    }
    Wire.end();

    return;
}
