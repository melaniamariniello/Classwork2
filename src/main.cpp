#include "control_loop.h"

using namespace std;

//the goal is to implement a simple PID controller, 
//running on input value to reach the desired one

// Sense: read a value from keyboard
// Plan:  generate the correct input
// Act:   set the input

int main(int argc, char** argv) {

    float initial_controller_value;
    if( argc > 1){
        initial_controller_value = float(argv[1]);
    }
    else initial_controller_value = 0.0;

    CONTROLLER c(0.1, initial_controller_value);

    
    return 0;
}
