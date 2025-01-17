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
#include <stdio.h>
#include <string.h>
#include "at_comand.h"
#include "at_flash.h"
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
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
struct my_struct par;
type (*pointer)(void);
//void (*pointer)(void);

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
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
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(USART1_IRQn);
  par.num0=1;//№ параметра
  par.num1=2;
  par.num2=3;
  par.num3=4;
  par.num4=5;
  par.num5=6;
  par.num6=7;
  par.num7=8;
  par.num8=9;
  par.num9=10;
  par.num10=11;
  par.num11=12;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  HAL_UART_Receive_IT(&huart1, &rxbyte, 1);//вызов приёма, подготовка к приёму
  while (1)
  {
    /* USER CODE END WHILE */
	  if (flag==1)
	  {
		  pointer=adr_func[check()];//pointer указатель на функцию, adr_func массив адресов функций
		  pointer();
		  /*switch (check())
	      {
	      	  case 0:
	      		  //sprintf(writeBuf, "%s", readBuf);//передаём в массив writeBuf
	      		  SPD();//скорость соединения
	      		  break;
	          case 1:
	               //sprintf(writeBuf, "%s", readBuf);//передаём в массив writeBuf
	               LNOPEN();//расстояние полного открытия
	               break;
	          case 2:
	               //sprintf(writeBuf, "%s", readBuf);//передаём в массив writeBuf
	               LNHLOPEN();//расстояние неполного открытия
	               break;
	          case 3:
	               //sprintf(writeBuf, "%s", readBuf);//передаём в массив writeBuf
	               CURERRLOCK1();//аварийное значение токо линии замков 1
	               break;
	          case 4:
	               //sprintf(writeBuf, "%s", readBuf);//передаём в массив writeBuf
	               CURERRLOCK2();//аварийное значение токо линии замков 2
	               break;
	          case 5:
	               //sprintf(writeBuf, "%s", readBuf);//передаём в массив writeBuf
	               CURERRDRIVE1();//аварийное значение  тока линии цепей привода окна 1
	               break;
	          case 6:
	               //sprintf(writeBuf, "%s", readBuf);//передаём в массив writeBuf
	               CURERRDRIVE2();//аварийное значение  тока линии цепей привода окна 2
	               break;
	          case 7:
	               //sprintf(writeBuf, "%s", readBuf);//передаём в массив writeBuf
	               CURERRDRIVE3();//аварийное значение  тока линии цепей привода окна 3
	               break;
	          case 8:
	               //sprintf(writeBuf, "%s", readBuf);//передаём в массив writeBuf
	               CURERRDRIVE4();//аварийное значение  тока линии цепей привода окна 4
	               break;
	          case 9:
	               //sprintf(writeBuf, "%s", readBuf);//передаём в массив writeBuf
	               CURERRTIME();//время удержания аварийного значения  тока линии цепей
	               break;
	          case 10:
	               //sprintf(writeBuf, "%s", readBuf);//передаём в массив writeBuf
	               STOTIMELOCK();//время нахождения в упоре замков
	               break;
	          case 11:
	        	  //sprintf(writeBuf, "%s", readBuf);//передаём в массив writeBuf
	              STOTIMEDRIVE();//время нахождения в упоре цепей
	              break;
	          case 12:
	        	  //sprintf(writeBuf, "%s", readBuf);//передаём в массив writeBuf
	              SAVEFLASH();//сохранить всё во flash
	              break;
	          case 13:
	        	  //sprintf(writeBuf, "%s", readBuf);//передаём в массив writeBuf
	              READFLASH();//"холодный старт"
	              break;
	          default:
	              sprintf(writeBuf, "%s", "Error\r\n");//передаём в массив writeBuf
	              break;
	      }*/
	           	 flag=0;//сбрасываем флаг
	             HAL_UART_Transmit(&huart1, (uint8_t*)writeBuf, strlen(writeBuf), HAL_MAX_DELAY);
	             HAL_UART_Receive_IT(&huart1, &rxbyte, 1);//вызов приёма, подготовка к приёму
	  }
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

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
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
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
  huart1.Init.BaudRate = 115200;
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
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle)
{
  /* Установить флаг передачи: передача завершена */
     // UartReady = SET;
      readBuf[i++]=rxbyte;//принимаем побайтно
      if (i >= sizeof(readBuf)) //если буфер переполнился
          i=0;//сбрасываем счётчик
      if (rxbyte=='\n') //если принятый байт символ перевода каретки
      {
          readBuf[i++] = '\0';//добавляем символ конца строки
          flag = 1; //устанавливаем флаг
          i=0;//сбрасываем счётчик
          //HAL_UART_AbortReceive(&huart1);//прекращение приёма из UART
      }
      else
          HAL_UART_Receive_IT(&huart1, &rxbyte, 1);//вызов приёма, подготовка к приёму
}
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
