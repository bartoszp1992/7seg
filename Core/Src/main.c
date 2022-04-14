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
#include "7seg.h"
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
TIM_HandleTypeDef htim1;

/* USER CODE BEGIN PV */
//LED DISPLAY-Create Structure
LEDdisplayTypeDef disp1;

char text1[4] = { "151A" };
char text2[4] = { "HAL" };

//encoder counter
volatile uint16_t counter = 5000;
volatile uint8_t flagEncoderActive = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
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
	MX_TIM1_Init();
	/* USER CODE BEGIN 2 */
	HAL_TIM_Base_Start_IT(&htim1);

	// LED DISPLAY- Pin assignment
	disp1.Field0Port = DISP_FIELD_0_GPIO_Port;
	disp1.Field0Pin = DISP_FIELD_0_Pin;
	disp1.Field1Port = DISP_FIELD_1_GPIO_Port;
	disp1.Field1Pin = DISP_FIELD_1_Pin;
	disp1.Field2Port = DISP_FIELD_2_GPIO_Port;
	disp1.Field2Pin = DISP_FIELD_2_Pin;
	disp1.Field3Port = DISP_FIELD_3_GPIO_Port;
	disp1.Field3Pin = DISP_FIELD_3_Pin;

	disp1.SegAPort = DISP_SEG_A_GPIO_Port;
	disp1.SegAPin = DISP_SEG_A_Pin;
	disp1.SegBPort = DISP_SEG_B_GPIO_Port;
	disp1.SegBPin = DISP_SEG_B_Pin;
	disp1.SegCPort = DISP_SEG_C_GPIO_Port;
	disp1.SegCPin = DISP_SEG_C_Pin;
	disp1.SegDPort = DISP_SEG_D_GPIO_Port;
	disp1.SegDPin = DISP_SEG_D_Pin;
	disp1.SegEPort = DISP_SEG_E_GPIO_Port;
	disp1.SegEPin = DISP_SEG_E_Pin;
	disp1.SegFPort = DISP_SEG_F_GPIO_Port;
	disp1.SegFPin = DISP_SEG_F_Pin;
	disp1.SegGPort = DISP_SEG_G_GPIO_Port;
	disp1.SegGPin = DISP_SEG_G_Pin;
	disp1.SegDOTPort = DISP_SEG_DOT_GPIO_Port;
	disp1.SegDOTPin = DISP_SEG_DOT_Pin;

	//set transition separator
	disp1.transitionSeparator[0] = '_';
	disp1.transitionSeparator[1] = '_';
	disp1.transitionSeparator[2] = '_';

	LEDinit(&disp1);

	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1) {

		LEDchar(&disp1, 0, 'H');
		LEDchar(&disp1, 1, 'A');
		LEDchar(&disp1, 2, 'L');
		HAL_Delay(300);
		LEDclear(&disp1);

		LEDdot(&disp1, 0, DOT_ACTIVE);
		HAL_Delay(300);
		LEDdot(&disp1, 1, DOT_ACTIVE);
		HAL_Delay(300);
		LEDdot(&disp1, 2, DOT_ACTIVE);
		HAL_Delay(300);
		LEDdot(&disp1, 3, DOT_ACTIVE);
		HAL_Delay(300);
		LEDclear(&disp1);

		for (uint16_t i = 9000; i < 10000; i++) {
			LEDclear(&disp1);
			LEDint(&disp1, 0, i, LED_TRANSITION_DISABLED);
			HAL_Delay(1);
		}
		LEDclear(&disp1);

		LEDstr(&disp1, 0, "Err", LED_TRANSITION_DIR_LEFT);
		HAL_Delay(500);
		LEDstr(&disp1, 0, "LEd", LED_TRANSITION_DIR_RIGHT);
		HAL_Delay(500);

		LEDstr(&disp1, 0, "Err", LED_TRANSITION_DIR_LEFT);
		HAL_Delay(500);
		LEDstr(&disp1, 0, "LEd", LED_TRANSITION_DIR_RIGHT);
		HAL_Delay(500);

		LEDclear(&disp1);

		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/** Configure the main internal regulator output voltage
	 */
	HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);
	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}
	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief TIM1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM1_Init(void) {

	/* USER CODE BEGIN TIM1_Init 0 */

	/* USER CODE END TIM1_Init 0 */

	TIM_ClockConfigTypeDef sClockSourceConfig = { 0 };
	TIM_MasterConfigTypeDef sMasterConfig = { 0 };

	/* USER CODE BEGIN TIM1_Init 1 */

	/* USER CODE END TIM1_Init 1 */
	htim1.Instance = TIM1;
	htim1.Init.Prescaler = 40;
	htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim1.Init.Period = 1999;
	htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim1.Init.RepetitionCounter = 0;
	htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim1) != HAL_OK) {
		Error_Handler();
	}
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK) {
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig)
			!= HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN TIM1_Init 2 */

	/* USER CODE END TIM1_Init 2 */

}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB,
			LED_GREEN_Pin | DISP_FIELD_3_Pin | DISP_SEG_G_Pin | DISP_SEG_C_Pin
					| DISP_SEG_DOT_Pin | DISP_SEG_D_Pin | DISP_SEG_E_Pin,
			GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA,
			DISP_FIELD_0_Pin | DISP_SEG_F_Pin | DISP_FIELD_1_Pin
					| DISP_FIELD_2_Pin | DISP_SEG_B_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(DISP_SEG_A_GPIO_Port, DISP_SEG_A_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pins : LED_GREEN_Pin DISP_FIELD_3_Pin DISP_SEG_G_Pin DISP_SEG_C_Pin
	 DISP_SEG_DOT_Pin DISP_SEG_D_Pin DISP_SEG_E_Pin */
	GPIO_InitStruct.Pin = LED_GREEN_Pin | DISP_FIELD_3_Pin | DISP_SEG_G_Pin
			| DISP_SEG_C_Pin | DISP_SEG_DOT_Pin | DISP_SEG_D_Pin
			| DISP_SEG_E_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pin : BUTTON_Pin */
	GPIO_InitStruct.Pin = BUTTON_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(BUTTON_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : ENC_L_Pin ENC_R_Pin */
	GPIO_InitStruct.Pin = ENC_L_Pin | ENC_R_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configure GPIO pins : DISP_FIELD_0_Pin DISP_SEG_F_Pin DISP_FIELD_1_Pin DISP_FIELD_2_Pin
	 DISP_SEG_B_Pin */
	GPIO_InitStruct.Pin = DISP_FIELD_0_Pin | DISP_SEG_F_Pin | DISP_FIELD_1_Pin
			| DISP_FIELD_2_Pin | DISP_SEG_B_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configure GPIO pin : DISP_SEG_A_Pin */
	GPIO_InitStruct.Pin = DISP_SEG_A_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(DISP_SEG_A_GPIO_Port, &GPIO_InitStruct);

	/* EXTI interrupt init*/
	HAL_NVIC_SetPriority(EXTI4_15_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {

	if (htim->Instance == TIM1) {
		LEDmultiplexing(&disp1);
//		LEDmultiplexing(&disp2);
	}

}

void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin) {

	flagEncoderActive = 1;
	if (GPIO_Pin == ENC_L_Pin) {
		if (HAL_GPIO_ReadPin(ENC_R_GPIO_Port, ENC_R_Pin)
				!= HAL_GPIO_ReadPin(ENC_L_GPIO_Port, ENC_L_Pin)) {

//			LEDstr(&disp1, 0, text1, LED_TRANSITION_DIR_LEFT);
			counter++;

		}
	}
	if (GPIO_Pin == ENC_R_Pin) {
		if (HAL_GPIO_ReadPin(ENC_R_GPIO_Port, ENC_R_Pin)
				!= HAL_GPIO_ReadPin(ENC_L_GPIO_Port, ENC_L_Pin)) {

//			LEDstr(&disp1, 0, text2, LED_TRANSITION_DIR_RIGHT);
			counter--;
		}
	}

}

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
	}
	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
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

