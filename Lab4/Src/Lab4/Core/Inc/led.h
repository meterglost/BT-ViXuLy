#ifndef INC_LED_H_
#define INC_LED_H_

#include "stm32f1xx.h"

typedef enum
{
	LED_ON,
	LED_OFF,
} Led_State;

typedef struct
{
	GPIO_TypeDef *const port;
	uint16_t const pin;
	GPIO_PinState const ON;
	GPIO_PinState const OFF;
} Led;

void set_led(Led const *const led, Led_State const state);

void toggle_led(Led const *const led);

#endif /* INC_LED_H_ */
