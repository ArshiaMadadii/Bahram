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
#define LED_DATA_Pin GPIO_PIN_13
#define LED_DATA_GPIO_Port GPIOC
#define LM35_Pin GPIO_PIN_0
#define LM35_GPIO_Port GPIOA
#define DS18B20_Pin GPIO_PIN_1
#define DS18B20_GPIO_Port GPIOA
#define GPS_RX_Pin GPIO_PIN_2
#define GPS_RX_GPIO_Port GPIOA
#define GPS_TX_Pin GPIO_PIN_3
#define GPS_TX_GPIO_Port GPIOA
#define Soil_M_Pin GPIO_PIN_4
#define Soil_M_GPIO_Port GPIOA
#define SIM800_RX_Pin GPIO_PIN_10
#define SIM800_RX_GPIO_Port GPIOB
#define SIM800_TX_Pin GPIO_PIN_11
#define SIM800_TX_GPIO_Port GPIOB
#define SPI2_nss_Pin GPIO_PIN_12
#define SPI2_nss_GPIO_Port GPIOB
#define LED_DATAA8_Pin GPIO_PIN_8
#define LED_DATAA8_GPIO_Port GPIOA
#define BLE_TX_Pin GPIO_PIN_9
#define BLE_TX_GPIO_Port GPIOA
#define BLE_RX_Pin GPIO_PIN_10
#define BLE_RX_GPIO_Port GPIOA
#define LED_LoRa_Pin GPIO_PIN_11
#define LED_LoRa_GPIO_Port GPIOA
#define LED_LoRaA12_Pin GPIO_PIN_12
#define LED_LoRaA12_GPIO_Port GPIOA
#define DS18B20A15_Pin GPIO_PIN_15
#define DS18B20A15_GPIO_Port GPIOA
#define LED_DS18B20_Pin GPIO_PIN_3
#define LED_DS18B20_GPIO_Port GPIOB
#define DHT22_Pin GPIO_PIN_4
#define DHT22_GPIO_Port GPIOB
#define LED_DHT22_Pin GPIO_PIN_5
#define LED_DHT22_GPIO_Port GPIOB
#define OLED_SCL_Pin GPIO_PIN_6
#define OLED_SCL_GPIO_Port GPIOB
#define OLED_SDA_Pin GPIO_PIN_7
#define OLED_SDA_GPIO_Port GPIOB
#define LED_DHT11_Pin GPIO_PIN_8
#define LED_DHT11_GPIO_Port GPIOB
#define DHT11_Pin GPIO_PIN_9
#define DHT11_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
