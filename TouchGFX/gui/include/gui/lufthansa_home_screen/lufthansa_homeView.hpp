
#ifndef LUFTHANSA_HOME_SCREENVIEW_HPP
#define LUFTHANSA_HOME_SCREENVIEW_HPP

#include <gui_generated/lufthansa_home_screen_screen/lufthansa_home_screenViewBase.hpp>
#include <gui/lufthansa_home_screen/lufthansa_home_screenPresenter.hpp>

class lufthansa_home_screenView : public lufthansa_home_screenViewBase
{
public:
    lufthansa_home_screenView();
    virtual ~lufthansa_home_screenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void updateAirPressureSensor(double value);

    void updateMovieSelection(int8_t value);
    
    void abort_button_action();
    
    void scroll_state_button_actions();
    virtual void increment_scroll_state();
    virtual void decrement_scroll_state();

    void buttons_group_1(int8_t appear);//@param appear: 0 invisible, 1 visible
    void buttons_group_2(int8_t appear);//@param appear: 0 invisible, 1 visible



protected:

    int8_t movie_id;


};

#endif // LUFTHANSA_HOME_SCREENVIEW_HPP
