#include "fsm.h"

extern ADC_HandleTypeDef hadc1;
static uint32_t ADC_value;

extern UART_HandleTypeDef huart2;
static char req[30];

enum
{
	STOP,
	START,
} command_parser_fsm_state = STOP;

void command_parser_fsm()
{
	switch (command_parser_fsm_state)
	{
	case STOP:
		if (strstr(buffer, "!RST#") != NULL)
		{
			buffer[0] = '\0';
			// HAL_UART_Transmit(&huart2, (unsigned char *)req, sprintf(req, "\r\nRST\r\n"), 100);
			command_parser_fsm_state = START;
		}
		break;

	case START:
		if (strstr(buffer, "!OK#") != NULL)
		{
			buffer[0] = '\0';
			// HAL_UART_Transmit(&huart2, (unsigned char *)req, sprintf(req, "\r\nOK\r\n"), 100);
			command_parser_fsm_state = STOP;
		}
		break;

	default:
		break;
	}
}

enum
{
	PENDING,
	INIT,
	SENDING,
} uart_communication_fsm_state = PENDING;

void uart_communication_fsm()
{
	switch (uart_communication_fsm_state)
	{
	case PENDING:
		if (command_parser_fsm_state == START)
			uart_communication_fsm_state = INIT;
		break;

	case INIT:
		HAL_ADC_Start(&hadc1);
		HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
		ADC_value = HAL_ADC_GetValue(&hadc1);
		HAL_ADC_Stop(&hadc1);
		uart_communication_fsm_state = SENDING;
		break;

	case SENDING:
		if (command_parser_fsm_state == STOP)
			uart_communication_fsm_state = PENDING;
		else if (timer_flag == true)
		{
			HAL_UART_Transmit(&huart2, (void *)req, sprintf(req, "\r\n%lu\r\n", ADC_value), 100);
			timer_counter = 3000;
			timer_flag = false;
		}
		break;

	default:
		break;
	}
}
