/*
 * Copyright (C) 2019 MRNIU
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

#include <stddef.h>
#include <stdio.h>
#include <aos/kernel.h>
#include <aos/hal/gpio.h>
#include <aos/hal/adc.h>
#include <aos/hal/dac.h>

#ifdef __cplusplus
}
#endif /* __cplusplus */ 

#include <include/arduino.h>

#define DAC_CHANNEL_ONE 1

static void gpio2adc(gpio_dev_t * gpio, adc_dev_t * adc_dev);
static void gpio2dac(gpio_dev_t * gpio, dac_dev_t * dac_dev);
int analogRead(gpio_dev_t * gpio);
void analogWrite(gpio_dev_t * gpio, int val);

static void gpio2adc(gpio_dev_t * gpio, adc_dev_t * adc_dev)
{
    adc_dev->port=gpio->port;
    adc_dev->config.sampling_cycle= 100;
    adc_dev->priv=NULL;
    if(hal_adc_init(adc_dev) != 0)
        printf("hal_adc_init error!\n");

    return;
}

static void gpio2dac(gpio_dev_t * gpio, dac_dev_t * dac_dev)
{
    dac_dev->port=gpio->port;
    dac_dev->priv=NULL;
    if(hal_dac_init(dac_dev))
        printf("hal_dac_init error!\n");
    return;
}

/**
 * read analog pin
 *
 * @param[in]  gpio  the gpio pin which should be read
 *                   gpio.port: read hal_adc_xxx.h to obtain value range
 * 
 * @return     the data being read
 */
int analogRead(gpio_dev_t * gpio)
{
    int res = 0;
    adc_dev_t adc_dev;
    gpio2adc(gpio, &adc_dev);
    if(hal_adc_value_get(&adc_dev, &res, HAL_WAIT_FOREVER))
        printf("hal_adc_value_get error!\n");
    hal_adc_finalize(&adc_dev);
	return res;
}

/**
 * write analog pin
 *
 * @param[in]  gpio  the gpio pin which should be write
 *                   gpio.port: read hal_dac_xxx.h to obtain value range
 * @param[in]  val   the value which should be write
 * 
 * @return     void
 */
void analogWrite(gpio_dev_t * gpio, int val)
{
    dac_dev_t dac_dev;
    gpio2dac(gpio, &dac_dev);

    if(hal_dac_init(&dac_dev))
        printf("dac_dev init error !\n");

    if(hal_dac_set_value(&dac_dev, DAC_CHANNEL_ONE, val))
        printf("dac_dev set value error !\n");

    hal_dac_finalize(&dac_dev);

    return;
}
