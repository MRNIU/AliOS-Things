/*
 * Copyright (C) 2019 MRNIU
 */

#include <arduino_exp_eeprom.h>

void arduino_exp_eeprom_clear(void)
{
    gpio_dev_t led1;

    pinMode(&led1, LED_1, OUTPUT);
    
    for (uint32_t i=0; i<64; i++){
        EEPROM.write(i, 0);
        digitalWrite(&led1, LOW);
        delay(100);
        digitalWrite(&led1, HIGH);
    }
    
    return;
}
