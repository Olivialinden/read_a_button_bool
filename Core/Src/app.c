/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : app.c
  * Description        : Code for app applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "app.h"
#include "FreeRTOS.h"
#include "main.h"
#include "cmsis_os.h"
#include <stdbool.h>

bool button_status = false;


void press_a_button(void)
{
	//When the button is pressed, button_status will become true.
  if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET)
	    {
        button_status = true;
	    }
}


void blink_a_led(void)
{   // if button_status is true then LED will turn on 1 second, then button_status will become false
  if (button_status == true)
	        {
	     	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
	          osDelay(1000);
	          HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
	          osDelay(50);
	          button_status = false;
	         }
}



