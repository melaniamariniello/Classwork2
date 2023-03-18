#include <iostream>
#include "boost/thread.hpp"
#include <fstream>
#include <cstdlib> 
#include <ctime>

using namespace std;

class CONTROLLER {
    public:
        CONTROLLER(float, float, float);
        
        void loop();                //Main loop function
        
        void system_start();       //start the system
        void set_xdes(double x);   //member to set the desired value

    private:
        double _xdes; //desired value to reach
        double _xmes; //current value of my system
        float _eps;   //error threshold

        //PID gains
        float  _kp; // P gain 
        float  _ki; // I gain 
        float  _kd; // D gain 

        bool _initial_val; 
};