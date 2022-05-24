lufthansa_home
#include <gui/lufthansa_home_screen_screen/lufthansa_home_screenView.hpp>
#include <gui/lufthansa_home_screen_screen/lufthansa_home_screenPresenter.hpp>

lufthansa_home_screenPresenter::lufthansa_home_screenPresenter(lufthansa_home_screenView& v)
    : view(v)
{

}

void lufthansa_home_screenPresenter::activate()
{

}

void lufthansa_home_screenPresenter::deactivate()
{

}

void lufthansa_home_screenPresenter::setAirPressureSensor(double value)
{
	view.updateAirPressureSensor(value);
}


void lufthansa_home_screenPresenter::receive_Movie_FromQueue(){
	model->queue_Read_Movie();
}
void lufthansa_home_screenPresenter::Put_Movie_ToQueue(int8_t value){
	model->queue_Put_Movie(value);
}




