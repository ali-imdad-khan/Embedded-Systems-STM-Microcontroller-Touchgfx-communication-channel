#include <gui/lufthansa_home_screen/lufthansa_home_screenView.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>


lufthansa_home_screenView::lufthansa_home_screenView():buttonCallback(this, &lufthansa_home_screenView::buttonCallbackHandler)
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



void lufthansa_home_screenView::abort_button_action(){

	choose_button.setBitmaps(touchgfx::Bitmap(BITMAP_BUTTON_GREY_240_92_ID), touchgfx::Bitmap(BITMAP_BUTTON_GREY_374_92_ID));
	choose_button.setLabelColor(touchgfx::Color::getColorFromRGB(99, 99, 99));
	choose_button.setTouchable(false);
	choose_button.invalidate();

	abort_button.setBitmaps(touchgfx::Bitmap(BITMAP_BUTTON_GREY_240_92_ID), touchgfx::Bitmap(BITMAP_BUTTON_GREY_240_92_ID));
	abort_button.setLabelColor(touchgfx::Color::getColorFromRGB(99, 99, 99));
	abort_button.setTouchable(false);
	abort_button.invalidate();

}

void lufthansa_home_screenView::updateAirPressureSensor(double value)
{
	memset(&air_pressure_sensor_1Buffer, 0, sizeof(air_pressure_sensor_1Buffer));
	Unicode::snprintf(air_pressure_sensor_1Buffer, AIR_PRESSURE_SENSOR_1_SIZE,"%d", value);    //Wildcards from lufthansa_home_ViewBase.hpp
	air_pressure_sensor_1.invalidate();
}
void lufthansa_home_screenView::updateMovieSelection(int8_t value)
{
	presenter->Put_Movie_ToQueue(value);
}

void lufthansa_home_screenView::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{

    if (&src == &abort)
    {
	    abort_button_action();
	    application().gotocustom_ScreenNoTransition();
    }
	
    if (&src == &update_movie)
    {
    	updateMovieSelection(getInputInField());
    }



}
void lufthansa_home_screenView::keyboard_pressed_key(char* pressed){


	Unicode::UnicodeChar txtBuffer[12];

	Unicode::strncpy(txtBuffer, pressed, 12);

	uint8_t existing_text[12];

	Unicode::toUTF8	(textAreaClickedInputBuffer,existing_text,12);

	//touchgfx_printf(strcat((char*)existing_text,pressed));
	strcat((char*)existing_text,pressed);

	Unicode::strncpy(textAreaClickedInputBuffer, (char*)existing_text, 12);

	textAreaClickedInput.invalidate();


}
void lufthansa_home_screenView::keyboard_backspace_key(){

	uint8_t backspace_temp_text[12];
	Unicode::toUTF8	(textAreaClickedInputBuffer,backspace_temp_text,12);

	int pos = get_last_position(backspace_temp_text);

	//touchgfx_printf("%i",pos);

	backspace_temp_text[pos-1]=-1;

	char* str = (char*)backspace_temp_text;

	str[pos-1]='\0';

	Unicode::strncpy(textAreaClickedInputBuffer, str, 11+1);

	textAreaClickedInput.invalidate();

}

int lufthansa_home_screenView::get_last_position(uint8_t existing_text[12])
{
	int pos=0;

	 int a;
	 char *arr = (char*)existing_text;

	 for( a = 0; a < 12; a = a + 1 ){


		   if(arr[a]=='\0'){
			   //touchgfx_printf("null");
			   pos=a;
			   break;
		   }else{
			   //touchgfx_printf("%c",arr[a]);
		   }

	   }

	return pos;

}

void lufthansa_home_screenView::initialize_keyboard_buttons(){

	ButtonClose.setAction(buttonCallback);

	ButtonZero.setAction(buttonCallback);
	ButtonOne.setAction(buttonCallback);
	ButtonTwo.setAction(buttonCallback);
	ButtonThree.setAction(buttonCallback);
	ButtonFour.setAction(buttonCallback);
	ButtonFive.setAction(buttonCallback);
	ButtonSix.setAction(buttonCallback);
	ButtonSeven.setAction(buttonCallback);
	ButtonEight.setAction(buttonCallback);
	ButtonNine.setAction(buttonCallback);

	ButtonDot.setAction(buttonCallback);
	ButtonEnter.setAction(buttonCallback);
	ButtonBackSpace.setAction(buttonCallback);
}


void lufthansa_home_screenView::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &ButtonClose)
    {
        //CloseScreen
        //When ButtonClose clicked change screen to home_screen
        //Go to home_screen with no screen transition
        keyboard_close();
    }

    if (&src == &ButtonZero)
    	    {
    	    	char c[] = "0";
    	    	keyboard_pressed_key(c);

    	    }
    	    else if (&src == &ButtonOne)
    	    {
    	    	char c[] = "1";
    	    	keyboard_pressed_key(c);
    	    }
    	      else if (&src == &ButtonTwo)
    	    {
    	    	char c[] = "2";
    	    	keyboard_pressed_key(c);
    	    }

    	    else if (&src == &ButtonThree)
    	    {
    	    	char c[] = "3";
    	    	keyboard_pressed_key(c);
    	    }

    	    else if (&src == &ButtonFour)
    	    {
    	    	char c[] = "4";
    	    	keyboard_pressed_key(c);
    	    }

    	    else if (&src == &ButtonFive)
    	    {
    	    	char c[] = "5";
    	    	keyboard_pressed_key(c);
    	    }

    	    else if (&src == &ButtonSix)
    	    {
    	    	char c[] = "6";
    	    	keyboard_pressed_key(c);	    }

    	    else if (&src == &ButtonSeven)
    	    {
    	    	char c[] = "7";
    	    	keyboard_pressed_key(c);
    	    }

    	    else if (&src == &ButtonEight)
    	    {
    	    	char c[] = "8";
    	    	keyboard_pressed_key(c);
    	    }

    	    else if (&src == &ButtonNine)
    	    {
    	    	char c[] = "9";
    	    	keyboard_pressed_key(c);	    }


    	    else if (&src == &ButtonDot)
    	    {
    	    	char c[] = ".";
    	    	keyboard_pressed_key(c);	    }


    	    else if (&src == &ButtonBackSpace)
    	    {
    	    	keyboard_backspace_key();
    	    }

    	    else if (&src == &ButtonEnter)
    	    {

    	    }

}

void lufthansa_home_screenView::keyboard_pressed_key(char* pressed){


	Unicode::UnicodeChar txtBuffer[12];

	Unicode::strncpy(txtBuffer, pressed, 11+1);

	uint8_t existing_text[12];

	Unicode::toUTF8	(textAreaClickedInputBuffer,existing_text,12);

	//touchgfx_printf(strcat((char*)existing_text,pressed));
	strcat((char*)existing_text,pressed);

	Unicode::strncpy(textAreaClickedInputBuffer, (char*)existing_text, 11+1);

	textAreaClickedInput.invalidate();


}

char* lufthansa_home_screenView::getInputInField(){
	uint8_t temp_password_text[12];
	Unicode::toUTF8	(textAreaClickedInputBuffer,temp_password_text,12);

	char* str = (char*)temp_password_text;

	return str;

}




void lufthansa_home_screenView::scroll_state_button_actions(){

	switch(scroll_state){

	case 0:{
		buttons_group_1(1);
		buttons_group_2(0);
		buttons_group_3(0);
	}break;

	case 1:{
		buttons_group_1(0);
		buttons_group_2(1);
		buttons_group_3(0);
	}break;

	case 2:{
		buttons_group_1(0);
		buttons_group_2(0);
		buttons_group_3(1);
	}break;

	case 3:{

	}break;


	}

}
void lufthansa_home_screenView::buttons_group_1(int8_t appear){

	switch(appear){
	case 0:{

		button1.moveTo(0,-200);
		button1_caption.moveTo(0,-200);

		button2_button.moveTo(0,-200);
		button2_value.moveTo(0,-200);
		button2_caption.moveTo(0,-200);


	}break;

	case 1:{
		button1_button.moveTo(0,0);
		button1_caption.moveTo(3,63);

		button2_button.moveTo(0,165);
		button2_caption.moveTo(3,243);
		button2_value.moveTo(157,213);


	}break;
	}

}
void lufthansa_home_screenView::buttons_group_2(int8_t appear){

	switch(appear){
	case 0:{

		button3_button.moveTo(0,-200);
		button3_caption.moveTo(0,-200);
		button3_value.moveTo(0,-200);

		button4_button.moveTo(0,-200);
		button4_caption.moveTo(0,-200);
		button4_value.moveTo(0,-200);


	}break;

	case 1:{
		button3_button.moveTo(0,0);
		button3_caption.moveTo(3,63);
		button3_value.moveTo(157,33);

		button4_button.moveTo(0,165);
		button4_caption.moveTo(3,243);
		button4_value.moveTo(157,213);


	}break;
	}

}


void lufthansa_home_screenView::decrement_scroll_state(){
	if(scroll_state>0){
		scroll_state=scroll_state-1;
	}
	scroll_state_button_actions();
}
void lufthansa_home_screenView::increment_scroll_state(){
	if(scroll_state<=1){
		scroll_state=scroll_state+1;
	}
	scroll_state_button_actions();
}



