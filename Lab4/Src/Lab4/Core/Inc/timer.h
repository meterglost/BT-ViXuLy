#ifndef TIMER_H
#define TIMER_H

#include "stm32f1xx.h"
#include "scheduler.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif
