#include "timer.h"

extern TIM_HandleTypeDef htim2;

bool timer_flag = true;
uint16_t timer_counter = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == htim2.Instance)
	{
		if (timer_counter > 10)
			timer_counter = timer_counter - 10;
		else
			timer_flag = true;
	}
}
