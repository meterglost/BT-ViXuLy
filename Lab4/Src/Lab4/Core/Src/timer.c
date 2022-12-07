#include "timer.h"

extern TIM_HandleTypeDef htim2;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == htim2.Instance)
	{
		Scheduler_Update(htim2.Init.Period + 1);
	}
}
