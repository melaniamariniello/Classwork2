#include "control_loop.h"

//We can use the class constructor to set parameters
CONTROLLER::CONTROLLER(float p, float initial_val) {
    _p = p;
    _initial_val = initial_val;

    //Thread here!
    boost::thread loop_t (&CONTROLLER::loop,this); //this means we're using the contents of this function init_val is the same in loopfunction
}


//Sense: get input to change the state of our System
void CONTROLLER::set_xdes(double x) {
 
}


//Random initial value
void CONTROLLER::system_start() {
    _cmd = _initial_val;
    
}

void CONTROLLER::loop() {

    cout << "LOOP!" << endl;

    float e = 0.0; //Controller error
    float c = 0.0; //Current command value (feed-forward )

    while( true ){

        e = _cmd - c;

        usleep(0.01*1e6); //Pause, takes input arguments in microsec
    }

}


