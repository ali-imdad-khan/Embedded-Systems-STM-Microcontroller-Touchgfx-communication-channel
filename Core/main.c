/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/

#include "main.h"
#include "cmsis_os.h"
#include "libjpeg.h"
#include "app_touchgfx.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "../mx25l512/mx25l512.h"
#include "../otm8009a/otm8009a.h"
#include "string.h"
#include <stdio.h>


/* USER CODE END Includes */

/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN 5 */
  uint16_t time_count=0;

  for(;;)
  {
	  if(time_count>=5)
	  {
		  time_count=0;
		  if(dataStruct.led==0)
		  {
			  dataStruct.led=1;
		  }
		  else
		  {
			  dataStruct.led=0;
		  }
		  if(HAL_I2C_IsDeviceReady(&hi2c1, I2C_SLAVE_ADDR<<1, 2, 100)==HAL_OK)
		  {
			  write_ledb(&dataStruct, dataStruct.led);
			  read_dataStruct(&dataStruct);
			  read_led(&dataStruct);

			  data_addr =DATA_ALL;
			  osMessageQueuePut(QueueTGFXHandle,&data_addr, 0, 100);
		  }
		  else
		  {
	  			  ////communication error////////////
	  			  I2C1->CR1 |= (1<<15);  // reset the I2C
	  			  I2C1->CR1 &= ~(1<<15);  // Normal operation
	  			  MX_I2C1_Init();//Reinit I2C

		  }
	  }
	  else
	  {
	  		  time_count++;
	  }



	  	  ////////example to use with TGFX: receive some data from TGFX
	  if(osMessageQueueGet(QueueData_Write_Handle,&data_addr, 0, 100)==osOK)
	  {
		  if(HAL_I2C_IsDeviceReady(&hi2c1, I2C_SLAVE_ADDR<<1, 2, 100)==HAL_OK)
		  {
			  if(data_addr==CAL_MOVIE)
			  {
				  write_movie(&uvdata, dataStruct.movie.all);
          HAL_GPIO_TogglePin(GPIOJ, GPIO_PIN_5);//green LED
			  }
		  }
	  }



	
    osDelay(100);
  }
  /* USER CODE END 5 */
}

