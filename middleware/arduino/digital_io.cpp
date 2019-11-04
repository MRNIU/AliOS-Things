/*
 * Copyright (C) 2019 MRNIU
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stddef.h>
#include <stdio.h>
#include <aos/hal/gpio.h>

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include <include/arduino.h>

// TODO:
// improve digitIO interface, remove parameters different from arduino such as gpio

static void setPin(gpio_dev_t * gpio, uint8_t pin, uint8_t config, void * val);
static gpio_config_t type_switch(uint8_t config);
void pinMode(gpio_dev_t * gpio, uint8_t pin, uint8_t config);
void digitalWrite(gpio_dev_t * gpio, uint8_t val);
int digitalRead(gpio_dev_t * gpio);

static void setPin(gpio_dev_t * gpio, uint8_t pin, uint8_t config, void * val)
{
    gpio->port = pin;
    gpio->config = type_switch(config);
    gpio->priv = val;
    if(hal_gpio_init(gpio))
        printf("hal_gpio_init error!\n");
    return;
}

static gpio_config_t type_switch(uint8_t config)
{
    if(config == OUTPUT)
        return OUTPUT_PUSH_PULL;
    else if(config == INPUT)
        return INPUT_PULL_DOWN;
    return INPUT_PULL_UP;
}

/**
 * set pin mode
 *
 * @param[in]  gpio  the gpio pin which should be set
 * @param[in]  pin   the pin number
 * @param[in]  config   INPUT or OUTPUT
 * 
 * @return     void
 */
void pinMode(gpio_dev_t * gpio, uint8_t pin, uint8_t config)
{
    setPin(gpio, pin, config, NULL);
    return;
}

/**
 * write a digital pin
 *
 * @param[in]  gpio  the gpio pin which should be write
 * @param[in]  val   the value which should be write
 * 
 * @return     void
 */
void digitalWrite(gpio_dev_t * gpio, uint8_t val){
    if(val == HIGH) {
        if(hal_gpio_output_high(gpio))
            printf("hal_gpio_output_high error!\n");
        return;
    }
    else if(val == LOW) {
        if(hal_gpio_output_low(gpio))
            printf("hal_gpio_output_low error!\n");
        return;
    }
    else
        return;
}

/**
 * set pin mode
 *
 * @param[in]  gpio  the gpio pin which should be read
 * @return     the value from gpio pin
 */
int digitalRead(gpio_dev_t * gpio)
{
    uint32_t val;
    if(hal_gpio_input_get(gpio, &val))
        printf("hal_gpio_input_get error!\n");
    return val;
}
