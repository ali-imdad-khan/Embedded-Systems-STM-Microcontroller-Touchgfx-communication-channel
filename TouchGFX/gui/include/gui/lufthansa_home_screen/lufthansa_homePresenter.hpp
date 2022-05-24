#ifndef LUFTHANSA_HOME_SCREENPRESENTER_HPP
#define LUFTHANSA_HOME_SCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class lufthansa_home_screenView;

class lufthansa_home_screenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    lufthansa_home_screenPresenter(lufthansa_home_screenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~lufthansa_home_screenPresenter() {};

    //Movie Queue Read calls to  main - > model - > View 
    void receive_Movie_FromQueue();
    //Movie Queue Put calls to view - > model - > main
    void Put_Movie_ToQueue();
    

    //Receive Air Pressure periodically read value main - > model - > View
    void setAirPressure(double value);



///Get Set methods to receive and set values in model data
    int8_t getMovie(){
    	return model->getModelMovie();
    }

    void setMovie(int8_t value){
    	model->setModelMovie(value);
    }

private:
    lufthansa_home_screenPresenter();

    lufthansa_home_screenView& view;
};

#endif // LUFTHANSA_HOME_SCREENPRESENTER_HPP
