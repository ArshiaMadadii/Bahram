/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */


#include "stdio.h"
#include "string.h"
#include "uart.h"
#include "DHT11_LIB.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/*
char msg[50] ;
char message1[16];
char message1[16];
uint8_t TOUT =0 , CheckSum , i;
uint8_t T_Byte1 , T_Byte2 , RH_Byte1 , RH_Byte2 ;*/

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

char texto[100];
unsigned int DHT11_TEMP;// Declarar en al main
unsigned int DHT11_HUM;  //declarar en el main
uint32_t milis,timepass;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/*************************************** DHT11 *********************************/
/*
void delay_us ( uint16_t us)
{
    __HAL_TIM_SET_COUNTER(&htim1,0);
    while(__HAL_TIM_GET_COUNTER(&htim1) < us);
}

void start_signal (void){
     GPIO_InitTypeDef GPIO_InitStruct = {0};


      GPIO_InitStruct.Pin = DHT11_Pin;
      GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
      GPIO_InitStruct.Pull = GPIO_NOPULL;
      GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
      HAL_GPIO_Init(DHT11_GPIO_Port, &GPIO_InitStruct);

      HAL_GPIO_WritePin(DHT11_GPIO_Port, DHT11_Pin, GPIO_PIN_RESET);
      HAL_Delay(18);
      HAL_GPIO_WritePin(DHT11_GPIO_Port, DHT11_Pin, GPIO_PIN_SET);
      delay_us(30);

      GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
      HAL_GPIO_Init(DHT11_GPIO_Port, &GPIO_InitStruct);

}



uint8_t check_response(void){
    TOUT=0;
    __HAL_TIM_SET_COUNTER(&htim1,0);
    while(!HAL_GPIO_ReadPin(DHT11_GPIO_Port, DHT11_Pin) && (__HAL_TIM_GET_COUNTER(&htim1) < 100)) {};
    if(__HAL_TIM_GET_COUNTER(&htim1)>= 100){
        return 0; //timeout
    }
    while(HAL_GPIO_ReadPin(DHT11_GPIO_Port, DHT11_Pin) && (__HAL_TIM_GET_COUNTER(&htim1) < 100)) {};
        if(__HAL_TIM_GET_COUNTER(&htim1)>= 100){
            return 0; //timeout
        }
    return 1;
}

uint8_t read_byte(void){
    uint8_t num =0 ;
    for(i=0 ;i<8; i++){
        while(!HAL_GPIO_ReadPin(DHT11_GPIO_Port, DHT11_Pin))  {};
        __HAL_TIM_SET_COUNTER(&htim1,0);
        while(HAL_GPIO_ReadPin(DHT11_GPIO_Port, DHT11_Pin))  {};
        if(__HAL_TIM_GET_COUNTER(&htim1) > 40)
        {
            num |= (1 << (7 - i));
        }

    }
    return num;
}

void process_sensor_data(void){
    RH_Byte1 = read_byte();
    RH_Byte2 = read_byte();
    T_Byte1 = read_byte();
    T_Byte2 = read_byte();
    CheckSum = read_byte();

    uint8_t humidity_integer =  RH_Byte1 ;
    uint8_t humidity_decimal =  RH_Byte2 / 10 ;

    uint8_t temperature_integer =  T_Byte1 ;
    uint8_t temperature_decimal =  T_Byte2 / 10 ;

    if(CheckSum ==((RH_Byte1+RH_Byte2 +T_Byte1+T_Byte2)& 0xff)){
        snprintf(msg,sizeof(msg),"RH = %d.%d %%\r\n",humidity_integer,humidity_decimal);
        send_uart_message(msg);
        snprintf(msg,sizeof(msg),"temp = %d.%d C\r\n",temperature_integer,temperature_decimal);
        send_uart_message(msg);

    }else
    {
        send_uart_message("Checksum Errors ! Trying Again ...\r\n");
    }
}

void send_uart_message(char *messsage){
    HAL_UART_Transmit(&huart1, (uint8_t*)messsage, strlen(messsage), HAL_MAX_DELAY);
}

*/
/******************************* DHT11 *********************************************/




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
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  delay_us_dwt_init();
  milis=uwTick;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

	  if (timepass>=1000)
	  	{
	  	  if( DHT11_ok()==1)
	  	  		 {
	  	  		 DHT11_Read();
	  	  		 }
	  	      	 else uartx_write_text(&huart1, (uint8_t *)"DHTPbad\r\n");

	         milis=uwTick;
	  	}


	  	    timepass= uwTick-milis;
	  		 sprintf(texto,"Temp=%u    Hum=%u\r\n",(unsigned int)DHT11_TEMP,(unsigned int)DHT11_HUM);    // manda info serialmente
	  		uartx_write_text(&huart1, (uint8_t *)texto);


	  	  HAL_Delay(200);

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
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(DHT11_GPIO_Port, DHT11_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : DHT11_Pin */
  GPIO_InitStruct.Pin = DHT11_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(DHT11_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
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
