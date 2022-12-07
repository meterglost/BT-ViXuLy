#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "stddef.h"
#include "stdint.h"

typedef struct
{
	void (*const func)(void);
	uint32_t const period;
	uint32_t delay;
	uint8_t runFlag;
} Task;

void Scheduler_Init();
uint8_t Scheduler_Subscribe(Task *const new_task);
void Scheduler_Dispatch();
void Scheduler_Update(uint32_t time);
void Scheduler_Unsubscribe(uint8_t task_index);
void Scheduler_Idle();

#endif
