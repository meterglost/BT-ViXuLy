#ifndef INC_UART_H
#define INC_UART_H

#include "main.h"
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define MAX_BUFFER_SIZE 30

extern char buffer[MAX_BUFFER_SIZE];
extern bool buffer_flag;
extern uint8_t buffer_index;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

#endif
