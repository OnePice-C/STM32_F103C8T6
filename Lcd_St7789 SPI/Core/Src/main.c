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
#include "st7789.h"

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
SPI_HandleTypeDef hspi1;
DMA_HandleTypeDef hdma_spi1_tx;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_SPI1_Init(void);

void    LL_mDelay(uint32_t Delay);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_DMA_Init();
  MX_SPI1_Init();
	ST7789_Init();
	ST7789_FillScreen(BLACK);
//	conversion_ready = 1;
//	trigger_point = 1;


  /* USER CODE BEGIN 2 */
//	ST7789_WriteString(24, 102, "OSCILLOSCOPE", Font_16x26, WHITE, BLACK);
//	ST7789_WriteString(50, 130, "Sampling Rate 1MSa/s", Font_7x10, WHITE, BLACK);
//	LL_mDelay(1000);
//	ST7789_WriteString(46, 130, "       Vanan92       ", Font_7x10, WHITE, BLACK);
//	LL_mDelay(1000);
//	ST7789_WriteString(50, 130, "        V1.1        ", Font_7x10, WHITE, BLACK);
//	LL_mDelay(1000);

//		ST7789_FillScreen(BLUE);
//	LL_mDelay(1000);
//		ST7789_FillScreen(WHITE);
//	LL_mDelay(1000);
//		ST7789_FillScreen(RED);
//	LL_mDelay(1000);
//	ST7789_WriteString(20, 20, "WELLCOME @@", Font_16x26, WHITE, RED);
//	LL_mDelay(2000);
//	
//	lcd_clear(WHITE);
	
	
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
//		ST7789_Init();
//		ST7789_FillScreen(BLACK);


//			ST7789_FillScreen(BLUE);
//		LL_mDelay(500);
//			ST7789_FillScreen(WHITE);
//		LL_mDelay(500);
//			ST7789_FillScreen(CYAN);
//		LL_mDelay(500);
//			ST7789_FillScreen(RED);
//		LL_mDelay(500);
//			ST7789_FillScreen(GREEN);
//		LL_mDelay(500);
//			ST7789_FillScreen(YELLOW);
//		LL_mDelay(500);
//				ST7789_FillScreen(BROWN);
//		LL_mDelay(500);
//			ST7789_FillScreen(DARKBLUE);
//		LL_mDelay(500);
//			ST7789_FillScreen(MAGENTA);
//		LL_mDelay(500);
//			ST7789_FillScreen(LIGHTGREEN);
//		LL_mDelay(500);
//			ST7789_FillScreen(LIGHTBLUE);
//		LL_mDelay(500);
//			ST7789_FillScreen(LGRAY);
//		LL_mDelay(500);
//			ST7789_FillScreen(LBBLUE);
//		LL_mDelay(500);
//			ST7789_FillScreen(LGRAYBLUE);
//		LL_mDelay(500);
//			ST7789_FillScreen(WHITE);
//		LL_mDelay(500);		
//		
//	ST7789_WriteString(10, 10, "Font test.", Font_16x26, GBLUE, WHITE);
//	ST7789_WriteString(10, 50, "Hello Steve!", Font_7x10, RED, WHITE);
//	ST7789_WriteString(10, 75, "Hello Steve!", Font_11x18, YELLOW, WHITE);
//	ST7789_WriteString(10, 100, "Hello Steve!", Font_16x26, MAGENTA, WHITE);
//	HAL_Delay(1000);

	ST7789_FillScreen(RED);
	ST7789_WriteString(10, 10, "Rect./Line.", Font_11x18, YELLOW, RED);
	ST7789_FillRectangle(30, 30, 100, 100, WHITE);
	HAL_Delay(1000);	

	ST7789_FillScreen(RED);
	ST7789_WriteString(10, 10, "Circle.", Font_11x18, YELLOW, RED);
	ST7789_DrawCircle(60, 60, 25, WHITE);
	HAL_Delay(1000);
	
	ST7789_FillScreen(WHITE);
	ST7789_DrawImage(0, 0, 128, 128, (uint16_t *)saber);
	HAL_Delay(3000);
	
//	ST7789_FillScreen(WHITE);
//	ST7789_DrawImage(0, 0, 240, 240, (uint16_t *) tek);
//	HAL_Delay(3000);
	//lcd_clear(WHITE);
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL3;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_HIGH;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel3_IRQn);

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
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(DC_ST7789_GPIO_Port, DC_ST7789_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(RST_ST7789_GPIO_Port, RST_ST7789_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : DC_ST7789_Pin RST_ST7789_Pin */
  GPIO_InitStruct.Pin = DC_ST7789_Pin|RST_ST7789_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

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

void LL_mDelay(uint32_t Delay)
{
  __IO uint32_t  tmp = SysTick->CTRL;  /* Clear the COUNTFLAG first */
  /* Add this code to indicate that local variable is not used */
  ((void)tmp);

  /* Add a period to guaranty minimum wait */
  if (Delay < LL_MAX_DELAY)
  {
    Delay++;
  }

  while (Delay)
  {
    if ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) != 0U)
    {
      Delay--;
    }
  }
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

