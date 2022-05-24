#include <gui/lufthansa_home_screen/lufthansa_home_screenView.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>


lufthansa_home_screenView::lufthansa_home_screenView()
{

}

void lufthansa_home_screenView::setupScreen()
{
    lufthansa_home_screenViewBase::setupScreen();

    //default setting of buttons to unclickable when screen first loaded
    abort_button_action();

    presenter->receive_Movie_FromQueue();

    movie= presenter->getMovie();

}

void lufthansa_home_screenView::tearDownScreen()
{
    lufthansa_home_screenViewBase::tearDownScreen();
}



void dark_calibration_screenView::abort_button_action(){

	choose_button.setBitmaps(touchgfx::Bitmap(BITMAP_BUTTON_GREY_240_92_ID), touchgfx::Bitmap(BITMAP_BUTTON_GREY_374_92_ID));
	choose_button.setLabelColor(touchgfx::Color::getColorFromRGB(99, 99, 99));
	choose_button.setTouchable(false);
	choose_button.invalidate();

	abort_button.setBitmaps(touchgfx::Bitmap(BITMAP_BUTTON_GREY_240_92_ID), touchgfx::Bitmap(BITMAP_BUTTON_GREY_240_92_ID));
	abort_button.setLabelColor(touchgfx::Color::getColorFromRGB(99, 99, 99));
	abort_button.setTouchable(false);
	abort_button.invalidate();

}

void dark_calibration_screenView::updateAirPressureSensor(double value)
{
	memset(&air_pressure_sensor_1Buffer, 0, sizeof(air_pressure_sensor_1Buffer));
	Unicode::snprintf(air_pressure_sensor_1Buffer, AIR_PRESSURE_SENSOR_1_SIZE,"%d", value);    //Wildcards from lufthansa_home_ViewBase.hpp
	air_pressure_sensor_1.invalidate();
}
void dark_calibration_screenView::updateMovie(int8_t value)
{
	memset(&movie_id_Buffer, 0, sizeof(movie_id_Buffer));
	Unicode::snprintf(movie_id_Buffer, MOVIE_ID_SIZE,"%d", value);    //Wildcards from Screen1ViewBase.hpp
	//textSensor2.resizeToCurrentText();
	movie_id_.invalidate();
}


