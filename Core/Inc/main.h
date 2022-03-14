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
#include "stm32g0xx_hal.h"

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
#define LED_GREEN_Pin GPIO_PIN_9
#define LED_GREEN_GPIO_Port GPIOB
#define DISP2_SEG_E_Pin GPIO_PIN_14
#define DISP2_SEG_E_GPIO_Port GPIOC
#define DISP2_SEG_D_Pin GPIO_PIN_0
#define DISP2_SEG_D_GPIO_Port GPIOA
#define DISP2_SEG_DOT_Pin GPIO_PIN_1
#define DISP2_SEG_DOT_GPIO_Port GPIOA
#define DISP2_SEG_C_Pin GPIO_PIN_2
#define DISP2_SEG_C_GPIO_Port GPIOA
#define DISP2_SEG_G_Pin GPIO_PIN_3
#define DISP2_SEG_G_GPIO_Port GPIOA
#define BUTTON_Pin GPIO_PIN_4
#define BUTTON_GPIO_Port GPIOA
#define DISP2_FIELD_3_Pin GPIO_PIN_5
#define DISP2_FIELD_3_GPIO_Port GPIOA
#define DISP2_SEG_B_Pin GPIO_PIN_6
#define DISP2_SEG_B_GPIO_Port GPIOA
#define DISP2_FIELD_2_Pin GPIO_PIN_7
#define DISP2_FIELD_2_GPIO_Port GPIOA
#define DISP2_FIELD_1_Pin GPIO_PIN_0
#define DISP2_FIELD_1_GPIO_Port GPIOB
#define DISP2_SEG_F_Pin GPIO_PIN_1
#define DISP2_SEG_F_GPIO_Port GPIOB
#define DISP2_SEG_A_Pin GPIO_PIN_2
#define DISP2_SEG_A_GPIO_Port GPIOB
#define DISP2_FIELD_0_Pin GPIO_PIN_8
#define DISP2_FIELD_0_GPIO_Port GPIOA
#define DISP_FIELD_0_Pin GPIO_PIN_9
#define DISP_FIELD_0_GPIO_Port GPIOA
#define DISP_SEG_A_Pin GPIO_PIN_6
#define DISP_SEG_A_GPIO_Port GPIOC
#define DISP_SEG_F_Pin GPIO_PIN_10
#define DISP_SEG_F_GPIO_Port GPIOA
#define DISP_FIELD_1_Pin GPIO_PIN_11
#define DISP_FIELD_1_GPIO_Port GPIOA
#define DISP_FIELD_2_Pin GPIO_PIN_12
#define DISP_FIELD_2_GPIO_Port GPIOA
#define DISP_SEG_B_Pin GPIO_PIN_15
#define DISP_SEG_B_GPIO_Port GPIOA
#define DISP_FIELD_3_Pin GPIO_PIN_3
#define DISP_FIELD_3_GPIO_Port GPIOB
#define DISP_SEG_G_Pin GPIO_PIN_4
#define DISP_SEG_G_GPIO_Port GPIOB
#define DISP_SEG_C_Pin GPIO_PIN_5
#define DISP_SEG_C_GPIO_Port GPIOB
#define DISP_SEG_DOT_Pin GPIO_PIN_6
#define DISP_SEG_DOT_GPIO_Port GPIOB
#define DISP_SEG_D_Pin GPIO_PIN_7
#define DISP_SEG_D_GPIO_Port GPIOB
#define DISP_SEG_E_Pin GPIO_PIN_8
#define DISP_SEG_E_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
