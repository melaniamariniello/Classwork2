#include <iostream>
#include "boost/thread.hpp"

using namespace std;

class CONTROLLER {
    public:
        CONTROLLER(float p, float initial_val); // input:
        
        void loop();                //Main loop function        
        void system_start();       //start the system
        void set_xdes(double x);   //member to set the desired value

    private:

        float _p;
        float _initial_val;
        float _cmd;

};
