#include "gpio.h"
#include "main.h"

#ifndef __Tracing_H
#define __Tracing_H

#define Left_1 HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_0)
#define Left_2 HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_1)
#define Left_3 HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_2)
#define Midlight HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_3)
#define Right_3 HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_4)
#define Right_2 HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_5)
#define Right_1 HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_6)
void Tracing(void);

#endif
