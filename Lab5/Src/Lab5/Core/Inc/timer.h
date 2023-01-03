#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>
#include <stdbool.h>
#include "stm32f1xx.h"

extern bool timer_flag;
extern uint16_t timer_counter;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif
