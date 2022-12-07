#include "main.h"
#include "led.h"

void set_led(Led const *const led, Led_State const state)
{
	switch (state)
	{
	case LED_ON:
		HAL_GPIO_WritePin(led->port, led->pin, led->ON);
		break;
	case LED_OFF:
		HAL_GPIO_WritePin(led->port, led->pin, led->OFF);
		break;
	default:
		break;
	}
}

void toggle_led(Led const *const led)
{
	HAL_GPIO_TogglePin(led->port, led->pin);
}

Led LED_ONE_SHOT = {
	.port = LED_ONE_SHOT_GPIO_Port,
	.pin = LED_ONE_SHOT_Pin,
	.ON = GPIO_PIN_RESET,
	.OFF = GPIO_PIN_SET,
};

Led LED_1 = {
	.port = LED_1_GPIO_Port,
	.pin = LED_1_Pin,
	.ON = GPIO_PIN_RESET,
	.OFF = GPIO_PIN_SET,
};

Led LED_2 = {
	.port = LED_2_GPIO_Port,
	.pin = LED_2_Pin,
	.ON = GPIO_PIN_RESET,
	.OFF = GPIO_PIN_SET,
};

Led LED_3 = {
	.port = LED_3_GPIO_Port,
	.pin = LED_3_Pin,
	.ON = GPIO_PIN_RESET,
	.OFF = GPIO_PIN_SET,
};

Led LED_4 = {
	.port = LED_4_GPIO_Port,
	.pin = LED_4_Pin,
	.ON = GPIO_PIN_RESET,
	.OFF = GPIO_PIN_SET,
};
