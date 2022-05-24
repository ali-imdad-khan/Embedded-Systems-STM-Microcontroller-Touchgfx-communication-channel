# STM PLC Display Front-ent and Back-end communication between TouchGFX Layer View -> Presenter -> Model -> Main Communication 

Embedded C / STM CUDE IDE, TouchGFX data transfer and input handle along with keypad implementation

This is an implementation of the following tasks as 
defined below:

As a user, who accesses this service through a user interface, ...
1. A Keypad on the microcontroller display to input numbers.
2. Input entered (@Param Movie) should be saved and loaded according to user.
3. Data from sensor @Param Air_pressure should be read periodically after ever 500ms.
The user interface is not part of this assignment, altough elements handles are imeplemented 
just as they would be if a user interface such as TouchGFX were to used.

###############################################

This project is build over the following requirements:

-Embedded C 
-STM Cube IDE
-TouchGFX UI
-STM32F769i Board

##########################################
Endpoints according to user requirement tasks:

1. A Keypad on the microcontroller display to input numbers.

Keypad is implemented in the following header and body files respectively:

TouchGFX/gui/include/gui/luthansa_home_screen.hpp (header)

TouchGFX/gui/src/gui/luthansa_home_screen.cpp (body)


------------------------------- 
2. Input entered (@Param Movie) should be saved and loaded according to user.

The communication between the view and the main file to write to the register is described as below:

Source Button handled -> View Method Called
                             -> Presenter get method -> 
                                        Model method to receive input from queue called -> 
                                                         Main StartDefaultTask reads/writes value from Queue and sets in defined struct

------------------------------- 
3. Data from sensor @Param Air_pressure should be read periodically after ever 500ms.

The Air pressure is read from the sensor into the Data_Struct and read by the Main StartDefaultTask not at each tick (60ms) 
but after every half second (500ms) and periodically sent to the model controller using "extern Queue" as follows:

Main Tick read_air_pressure() - >
       Data written to Queue_hanlde - >
                  Queue_hanlde declared as extern variable in model class - >
                          ModelListerner used to call set air_pressure method periodically - >
                                     Screen Presenter calls View Update method - >
                                                     View sets values either on Screen_SetUp or periodically on calls
                                                     
######################################

