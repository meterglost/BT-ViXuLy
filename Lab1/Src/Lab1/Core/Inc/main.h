/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_RED_X_Pin GPIO_PIN_5
#define LED_RED_X_GPIO_Port GPIOA
#define LED_YELLOW_X_Pin GPIO_PIN_6
#define LED_YELLOW_X_GPIO_Port GPIOA
#define LED_GREEN_X_Pin GPIO_PIN_7
#define LED_GREEN_X_GPIO_Port GPIOA
#define LED7SEG_A_Pin GPIO_PIN_0
#define LED7SEG_A_GPIO_Port GPIOB
#define LED7SEG_B_Pin GPIO_PIN_1
#define LED7SEG_B_GPIO_Port GPIOB
#define LED7SEG_C_Pin GPIO_PIN_2
#define LED7SEG_C_GPIO_Port GPIOB
#define LED_RED_Y_Pin GPIO_PIN_9
#define LED_RED_Y_GPIO_Port GPIOA
#define LED_YELLOW_Y_Pin GPIO_PIN_10
#define LED_YELLOW_Y_GPIO_Port GPIOA
#define LED_GREEN_Y_Pin GPIO_PIN_11
#define LED_GREEN_Y_GPIO_Port GPIOA
#define LED7SEG_D_Pin GPIO_PIN_3
#define LED7SEG_D_GPIO_Port GPIOB
#define LED7SEG_E_Pin GPIO_PIN_4
#define LED7SEG_E_GPIO_Port GPIOB
#define LED7SEG_F_Pin GPIO_PIN_5
#define LED7SEG_F_GPIO_Port GPIOB
#define LED7SEG_G_Pin GPIO_PIN_6
#define LED7SEG_G_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
