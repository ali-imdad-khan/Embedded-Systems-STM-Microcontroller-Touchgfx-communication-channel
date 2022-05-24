#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>



#ifndef SIMULATOR


#include "cmsis_os2.h"                  // ::CMSIS:RTOS2
#include "cmsis_compiler.h"

extern DATA_STRUCT dataStruct;
uint8_t data_addr=0;

#endif

#ifndef SIMULATOR
extern "C"
{
	//New TGFX_DATA Queue
	osMessageQueueId_t QueueData_Read_Handle;//Queue to receive Data
	const osMessageQueueAttr_t QueueData_Read_attributes = {.name = "QueueRead"};

	osMessageQueueId_t QueueData_Write_Handle;//Queue to send Data
	const osMessageQueueAttr_t QueueData_Write_attributes = {.name = "QueueWrite"};



}
#endif

Model::Model() : modelListener(0)
{

#ifndef SIMULATOR
		//Start Queue main<->TGFX
		QueueData_Write_Handle = osMessageQueueNew (1, sizeof(uint8_t), &QueueData_Write_attributes);
		QueueData_Read_Handle = osMessageQueueNew (1, sizeof(uint8_t), &QueueData_Read_attributes);
		

#endif
}

void Model::tick()
{


#ifndef SIMULATOR

	//check for changes in unit value
	///////////////MAIN->TGFX Example Dummy////////////////////
	if(osMessageQueueGet(QueueTGFXHandle,&dataStruct, 0, 100)==osOK)
	{
      //Handle constant air pressure reading
		if(data_addr==CAL_AIR_PRESSURE)
		{
			if(dataStruct.air_presssure.all != old_air_pressure)
			{
				old_air_pressure=dataStruct.air_pressure.all;
				modelListener->setAirPressure(dataStruct.air_pressure.all);
			}
		}
	}

#endif

}





void Model::queue_Put_Movie(uint8_t value)
{

#ifndef SIMULATOR


	dataStruct.mvie.all=value;

	data_addr=CAL_MOVIE
	osMessageQueuePut(QueueData_Write_Handle,&data_addr, 0, 100);

#endif

void Model::queue_Read_Movie()
{
#ifndef SIMULATOR

	data_addr=CAL_MOVIE
	osMessageQueuePut(QueueData_Read_Handle,&data_addr, 0, 100);
  
	modelListener->setMovie(dataStruct.movie.all);
  
#endif

}


}


