#include "uart.h"

extern UART_HandleTypeDef huart2;

char temp = '\0';
char buffer[MAX_BUFFER_SIZE];
bool buffer_flag = false;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == huart2.Instance)
	{
		if (strlen(buffer) == MAX_BUFFER_SIZE)
			buffer[0] = '\0';
		strcat(buffer, &temp);
		buffer_flag = 1;
		HAL_UART_Receive_IT(&huart2, (unsigned char *)&temp, 1);
	}
}
