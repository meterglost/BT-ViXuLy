/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void display7SEG(int num)
{
	switch (num)
	{
	case 0:
		GPIOB->ODR = 0b1000000; // GFEDCBA
		break;

	case 1:
		GPIOB->ODR = 0b1111001; // GFEDCBA
		break;

	case 2:
		GPIOB->ODR = 0b0100100; // GFEDCBA
		break;

	case 3:
		GPIOB->ODR = 0b0110000; // GFEDCBA
		break;

	case 4:
		GPIOB->ODR = 0b0011001; // GFEDCBA
		break;

	case 5:
		GPIOB->ODR = 0b0010010; // GFEDCBA
		break;

	case 6:
		GPIOB->ODR = 0b0000010; // GFEDCBA
		break;

	case 7:
		GPIOB->ODR = 0b1111000; // GFEDCBA
		break;

	case 8:
		GPIOB->ODR = 0b0000000; // GFEDCBA
		break;

	case 9:
		GPIOB->ODR = 0b0010000; // GFEDCBA
		break;

	default:
		break;
	}
}
/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	/* USER CODE BEGIN 2 */
	int clockCount = 0;
	const int CLOCK_CYCLE = 0 + 5 + 2 + 3;
	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1)
	{
		switch (clockCount)
		{
		case 0:
			HAL_GPIO_WritePin(LED_RED_X_GPIO_Port, LED_RED_X_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW_X_GPIO_Port, LED_YELLOW_X_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN_X_GPIO_Port, LED_GREEN_X_Pin, GPIO_PIN_RESET);
			break;

		case 0 + 5:
			HAL_GPIO_WritePin(LED_RED_X_GPIO_Port, LED_RED_X_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_YELLOW_X_GPIO_Port, LED_YELLOW_X_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN_X_GPIO_Port, LED_GREEN_X_Pin, GPIO_PIN_SET);
			break;

		case 0 + 5 + 3:
			HAL_GPIO_WritePin(LED_RED_X_GPIO_Port, LED_RED_X_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_YELLOW_X_GPIO_Port, LED_YELLOW_X_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_X_GPIO_Port, LED_GREEN_X_Pin, GPIO_PIN_RESET);
			break;

		default:
			break;
		}

		switch (clockCount)
		{
		case 0:
			HAL_GPIO_WritePin(LED_RED_Y_GPIO_Port, LED_RED_Y_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_YELLOW_Y_GPIO_Port, LED_YELLOW_Y_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN_Y_GPIO_Port, LED_GREEN_Y_Pin, GPIO_PIN_SET);
			break;

		case 0 + 3:
			HAL_GPIO_WritePin(LED_RED_Y_GPIO_Port, LED_RED_Y_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_YELLOW_Y_GPIO_Port, LED_YELLOW_Y_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_Y_GPIO_Port, LED_GREEN_Y_Pin, GPIO_PIN_RESET);
			break;

		case 0 + 3 + 2:
			HAL_GPIO_WritePin(LED_RED_Y_GPIO_Port, LED_RED_Y_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW_Y_GPIO_Port, LED_YELLOW_Y_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN_Y_GPIO_Port, LED_GREEN_Y_Pin, GPIO_PIN_RESET);
			break;

		default:
			break;
		}

		display7SEG(clockCount);

		HAL_Delay(1000);
		clockCount = (++clockCount < CLOCK_CYCLE) ? clockCount : 0;
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
	{
		Error_Handler();
	}
}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA, LED_RED_X_Pin | LED_YELLOW_X_Pin | LED_GREEN_X_Pin | LED_RED_Y_Pin | LED_YELLOW_Y_Pin | LED_GREEN_Y_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB, LED7SEG_A_Pin | LED7SEG_B_Pin | LED7SEG_C_Pin | LED7SEG_D_Pin | LED7SEG_E_Pin | LED7SEG_F_Pin | LED7SEG_G_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pins : LED_RED_X_Pin LED_YELLOW_X_Pin LED_GREEN_X_Pin LED_RED_Y_Pin
							 LED_YELLOW_Y_Pin LED_GREEN_Y_Pin */
	GPIO_InitStruct.Pin = LED_RED_X_Pin | LED_YELLOW_X_Pin | LED_GREEN_X_Pin | LED_RED_Y_Pin | LED_YELLOW_Y_Pin | LED_GREEN_Y_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configure GPIO pins : LED7SEG_A_Pin LED7SEG_B_Pin LED7SEG_C_Pin LED7SEG_D_Pin
							 LED7SEG_E_Pin LED7SEG_F_Pin LED7SEG_G_Pin */
	GPIO_InitStruct.Pin = LED7SEG_A_Pin | LED7SEG_B_Pin | LED7SEG_C_Pin | LED7SEG_D_Pin | LED7SEG_E_Pin | LED7SEG_F_Pin | LED7SEG_G_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
	}
	/* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
	   ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
