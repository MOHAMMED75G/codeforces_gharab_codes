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

#include "cmsis_os.h"



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

osThreadId defaultTaskHandle;

osThreadId Task1Handle;

osThreadId Task2Handle;

osThreadId Task3Handle;

osThreadId Task4Handle;

osSemaphoreId myBinarySem01Handle;

/* USER CODE BEGIN PV */



/* USER CODE END PV */



/* Private function prototypes -----------------------------------------------*/

void SystemClock_Config(void);

static void MX_GPIO_Init(void);

void StartDefaultTask(void const * argument);

void StartTask02(void const * argument);

void StartTask03(void const * argument);

void StartTask04(void const * argument);

void StartTask05(void const * argument);



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

  /* USER CODE BEGIN 2 */



  /* USER CODE END 2 */



  /* USER CODE BEGIN RTOS_MUTEX */

  /* add mutexes, ... */

  /* USER CODE END RTOS_MUTEX */



  /* Create the semaphores(s) */

  /* definition and creation of myBinarySem01 */

  osSemaphoreDef(myBinarySem01);

  myBinarySem01Handle = osSemaphoreCreate(osSemaphore(myBinarySem01), 1);



  /* USER CODE BEGIN RTOS_SEMAPHORES */

  /* add semaphores, ... */

  /* USER CODE END RTOS_SEMAPHORES */



  /* USER CODE BEGIN RTOS_TIMERS */

  /* start timers, add new ones, ... */

  /* USER CODE END RTOS_TIMERS */



  /* USER CODE BEGIN RTOS_QUEUES */

  /* add queues, ... */

  /* USER CODE END RTOS_QUEUES */



  /* Create the thread(s) */

  /* definition and creation of defaultTask */

  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);

  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);



  /* definition and creation of Task1 */

  osThreadDef(Task1, StartTask02, osPriorityHigh, 0, 128);

  Task1Handle = osThreadCreate(osThread(Task1), NULL);



  /* definition and creation of Task2 */

  osThreadDef(Task2, StartTask03, osPriorityIdle, 0, 128);

  Task2Handle = osThreadCreate(osThread(Task2), NULL);



  /* definition and creation of Task3 */

  osThreadDef(Task3, StartTask04, osPriorityAboveNormal, 0, 128);

  Task3Handle = osThreadCreate(osThread(Task3), NULL);



  /* definition and creation of Task4 */

  osThreadDef(Task4, StartTask05, osPriorityIdle, 0, 128);

  Task4Handle = osThreadCreate(osThread(Task4), NULL);



  /* USER CODE BEGIN RTOS_THREADS */

  /* add threads, ... */

  /* USER CODE END RTOS_THREADS */



  /* Start scheduler */

  osKernelStart();



  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */

  /* USER CODE BEGIN WHILE */

  while (1)

  {

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



  /** Configure the main internal regulator output voltage

  */

  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);



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

  __HAL_RCC_GPIOA_CLK_ENABLE();

  __HAL_RCC_GPIOD_CLK_ENABLE();



  /*Configure GPIO pin Output Level */

  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);



  /*Configure GPIO pin : PA0 */

  GPIO_InitStruct.Pin = GPIO_PIN_0;

  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;

  GPIO_InitStruct.Pull = GPIO_NOPULL;

  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);



  /*Configure GPIO pins : PD12 PD13 PD14 PD15 */

  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;

  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;

  GPIO_InitStruct.Pull = GPIO_NOPULL;

  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);



/* USER CODE BEGIN MX_GPIO_Init_2 */

/* USER CODE END MX_GPIO_Init_2 */

}



/* USER CODE BEGIN 4 */

/* High-priority taskACtrl */

void StartTask02(void const * argument) {

  for (;;) {

    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);  // Red LED ON (taskACtrl active)

    osSemaphoreRelease(myBinarySem01Handle);  // Release taskA every 3000 ms



    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);  // Red LED OFF

    osDelay(3000);





  }

}



/* TaskA controlled by taskACtrl */

void StartTask03(void const * argument) {

  for (;;) {

    osSemaphoreWait(myBinarySem01Handle, osWaitForever);  // Wait for release by taskACtrl



    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);  // Blue LED ON (taskA active)

    osDelay(300);  // TaskA execution time of 300 ms

    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);  // Blue LED OFF



  }

}



/* Lower-priority TaskB running every 1000 ms */

void StartTask04(void const * argument) {

  for (;;) {

    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);  // Green LED ON (taskB active)

    osDelay(500);  // TaskB execution time of 100 ms

    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);  // Green LED OFF

    osDelay(900);  // Wait for next 1000 ms period

  }

}

/* USER CODE END 4 */



/* USER CODE BEGIN Header_StartDefaultTask */

/**

  * @brief  Function implementing the defaultTask thread.

  * @param  argument: Not used

  * @retval None

  */

/* USER CODE END Header_StartDefaultTask */

void StartDefaultTask(void const * argument)

{

  /* USER CODE BEGIN 5 */

  /* Infinite loop */

  for(;;)

  {

    osDelay(1);

  }

  /* USER CODE END 5 */

}



/* USER CODE BEGIN Header_StartTask02 */

/**

* @brief Function implementing the Task1 thread.

* @param argument: Not used

* @retval None

*/

/* USER CODE END Header_StartTask02 */



  /* USER CODE END StartTask02 */





/* USER CODE BEGIN Header_StartTask03 */

/**

* @brief Function implementing the Task2 thread.

* @param argument: Not used

* @retval None

*/

/* USER CODE END Header_StartTask03 */





/* USER CODE BEGIN Header_StartTask04 */

/**

* @brief Function implementing the Task3 thread.

* @param argument: Not used

* @retval None

*/

/* USER CODE END Header_StartTask04 */





/* USER CODE BEGIN Header_StartTask05 */

/**

* @brief Function implementing the Task4 thread.

* @param argument: Not used

* @retval None

*/

/* USER CODE END Header_StartTask05 */

void StartTask05(void const * argument)

{

  /* USER CODE BEGIN StartTask05 */

  /* Infinite loop */

  for(;;)

  {

    osDelay(1);

  }

  /* USER CODE END StartTask05 */

}



/**

  * @brief  Period elapsed callback in non blocking mode

  * @note   This function is called  when TIM14 interrupt took place, inside

  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment

  * a global variable "uwTick" used as application time base.

  * @param  htim : TIM handle

  * @retval None

  */

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)

{

  /* USER CODE BEGIN Callback 0 */



  /* USER CODE END Callback 0 */

  if (htim->Instance == TIM14) {

    HAL_IncTick();

  }

  /* USER CODE BEGIN Callback 1 */



  /* USER CODE END Callback 1 */

}



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


