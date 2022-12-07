#include "main.h"
#include "scheduler.h"

#define SCHEDULER_TASK_MAX 50

uint8_t scheduler_task_count = 0;
static Task *task[SCHEDULER_TASK_MAX];

void Scheduler_Init()
{
	for (uint8_t index = 0; index < SCHEDULER_TASK_MAX; ++index)
		task[index] = NULL;
}

uint8_t Scheduler_Subscribe(Task *const new_task)
{
	if (scheduler_task_count < SCHEDULER_TASK_MAX)
	{
		task[scheduler_task_count] = new_task;
		++scheduler_task_count;
	}
	return scheduler_task_count;
}

void Scheduler_Dispatch()
{
	for (uint8_t index = 0; index < scheduler_task_count; ++index)
	{
		if (task[index]->runFlag > 0)
		{
			task[index]->func();
			task[index]->runFlag -= 1;
			if (task[index]->period == 0)
				Scheduler_Unsubscribe(index);
		}
	}
}

void Scheduler_Update(uint32_t time)
{
	for (uint8_t index = 0; index < scheduler_task_count; ++index)
	{
		if (task[index]->delay == 0)
		{
			task[index]->runFlag += 1;
			if (task[index]->period != 0)
				task[index]->delay = task[index]->period;
		}
		else
		{
			task[index]->delay = task[index]->delay >= time ? (task[index]->delay - time) : 0;
		}
	}
}

void Scheduler_Unsubscribe(uint8_t task_index)
{
	if (task_index < scheduler_task_count)
	{
		--scheduler_task_count;
		for (uint8_t index = task_index; index < scheduler_task_count; ++index)
			task[index] = task[index + 1];
		task[scheduler_task_count] = NULL;
	}
}

void Scheduler_Idle()
{
}
