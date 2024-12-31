/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_system.h"
#include "stm32f4xx_ll_exti.h"
#include "stm32f4xx_ll_cortex.h"
#include "stm32f4xx_ll_utils.h"
#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_dma.h"
#include "stm32f4xx_ll_tim.h"
#include "stm32f4xx_ll_gpio.h"

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
#define MIDI_IN_PORTS_NUM   0x01 // Specify input ports number of your device
#define MIDI_OUT_PORTS_NUM  0x01 // Specify output ports number of your device

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DeckBBtn5_Pin LL_GPIO_PIN_3
#define DeckBBtn5_GPIO_Port GPIOA
#define DeckBBtn4_Pin LL_GPIO_PIN_4
#define DeckBBtn4_GPIO_Port GPIOA
#define DeckBEncBtn_Pin LL_GPIO_PIN_5
#define DeckBEncBtn_GPIO_Port GPIOA
#define DeckBEncA_Pin LL_GPIO_PIN_6
#define DeckBEncA_GPIO_Port GPIOA
#define DeckBEncB_Pin LL_GPIO_PIN_7
#define DeckBEncB_GPIO_Port GPIOA
#define DeckBBtn3_Pin LL_GPIO_PIN_0
#define DeckBBtn3_GPIO_Port GPIOB
#define DeckBBtn2_Pin LL_GPIO_PIN_1
#define DeckBBtn2_GPIO_Port GPIOB
#define DeckBBtn1_Pin LL_GPIO_PIN_2
#define DeckBBtn1_GPIO_Port GPIOB
#define DeckABtn5_Pin LL_GPIO_PIN_10
#define DeckABtn5_GPIO_Port GPIOB
#define DeckABtn4_Pin LL_GPIO_PIN_12
#define DeckABtn4_GPIO_Port GPIOB
#define DeckABtn3_Pin LL_GPIO_PIN_13
#define DeckABtn3_GPIO_Port GPIOB
#define DeckABtn2_Pin LL_GPIO_PIN_14
#define DeckABtn2_GPIO_Port GPIOB
#define DeckABtn1_Pin LL_GPIO_PIN_15
#define DeckABtn1_GPIO_Port GPIOB
#define DeckAEncA_Pin LL_GPIO_PIN_8
#define DeckAEncA_GPIO_Port GPIOA
#define DeckAEncB_Pin LL_GPIO_PIN_9
#define DeckAEncB_GPIO_Port GPIOA
#define DeckAEncBtn_Pin LL_GPIO_PIN_10
#define DeckAEncBtn_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
