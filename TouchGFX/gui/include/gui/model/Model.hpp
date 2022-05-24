#ifndef MODEL_HPP
#define MODEL_HPP

#include <touchgfx/hal/types.hpp>

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }
    
    int8_t getModelMovie(){
        return movie;
    }

    void setModelMovie(int8_t  value){

    	movie= value;
    }


    void tick();


protected:
    ModelListener* modelListener;
    
    int8_t movie;


};

#endif // MODEL_HPP
