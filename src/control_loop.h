#include <iostream>
#include "boost/thread.hpp"
#include <fstream>

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
        float _eps; //error threshold

        double _kp; // PID gains costante di controllo proporzionale
        double _kd; // PID gains costante di controllo derivativo
        double _ki; // PID gains costante di controllo integrale

        bool _initial_val; 
};