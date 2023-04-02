/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : 3 tasks, StartDefaultTask, StartTask02, StartTask03.
  * StartDefaultTask is default task.
  * StartTask02 is used to detect whether the button has been pressed.
  * StartTask03 is that once the button is pressed, the LED will blink 1s.
  *******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "main.h"
#include "cmsis_os.h"
#include "main.h"
#include "gpio.h"
#include <stdio.h>
#include <stdbool.h>
#include "app.h"

/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId press_a_buttonHandle;
osThreadId blink_a_ledHandle;

void StartDefaultTask(void const * argument);
void StartTask02(void const * argument);
void StartTask03(void const * argument);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */


/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {

  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of press_a_button */
  osThreadDef(press_a_button, StartTask02, osPriorityIdle, 0, 128);
  press_a_buttonHandle = osThreadCreate(osThread(press_a_button), NULL);

  /* definition and creation of blink_a_led */
  osThreadDef(blink_a_led, StartTask03, osPriorityIdle, 0, 128);
  blink_a_ledHandle = osThreadCreate(osThread(blink_a_led), NULL);
}




