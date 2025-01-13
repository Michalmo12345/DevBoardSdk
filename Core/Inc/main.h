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
#include "stm32l4xx_hal.h"

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
#define SW_PC13_Pin GPIO_PIN_13
#define SW_PC13_GPIO_Port GPIOC
#define TOF_GPIO1_Pin GPIO_PIN_2
#define TOF_GPIO1_GPIO_Port GPIOC
#define TOF_XSHUT_Pin GPIO_PIN_3
#define TOF_XSHUT_GPIO_Port GPIOC
#define DIG_B2_Pin GPIO_PIN_2
#define DIG_B2_GPIO_Port GPIOA
#define DIG_B3_Pin GPIO_PIN_3
#define DIG_B3_GPIO_Port GPIOA
#define RMF_DIO5_Pin GPIO_PIN_4
#define RMF_DIO5_GPIO_Port GPIOC
#define RMF_DIO1_Pin GPIO_PIN_1
#define RMF_DIO1_GPIO_Port GPIOB
#define RMF_DIO0_Pin GPIO_PIN_2
#define RMF_DIO0_GPIO_Port GPIOB
#define DIG_LED3_Pin GPIO_PIN_10
#define DIG_LED3_GPIO_Port GPIOB
#define RMF_DIO4_Pin GPIO_PIN_13
#define RMF_DIO4_GPIO_Port GPIOB
#define RMF_DIO3_Pin GPIO_PIN_14
#define RMF_DIO3_GPIO_Port GPIOB
#define RMF_DIO2_Pin GPIO_PIN_15
#define RMF_DIO2_GPIO_Port GPIOB
#define DIG_LED2_Pin GPIO_PIN_8
#define DIG_LED2_GPIO_Port GPIOA
#define DIG_LED1_Pin GPIO_PIN_9
#define DIG_LED1_GPIO_Port GPIOA
#define DIG_B1_Pin GPIO_PIN_10
#define DIG_B1_GPIO_Port GPIOA
#define RFM_RST_Pin GPIO_PIN_11
#define RFM_RST_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SPI3_CS_Pin GPIO_PIN_2
#define SPI3_CS_GPIO_Port GPIOD
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define DIG_LED4_Pin GPIO_PIN_4
#define DIG_LED4_GPIO_Port GPIOB
#define DIG_LED5_Pin GPIO_PIN_5
#define DIG_LED5_GPIO_Port GPIOB
#define SPI1_CS_Pin GPIO_PIN_6
#define SPI1_CS_GPIO_Port GPIOB


/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
