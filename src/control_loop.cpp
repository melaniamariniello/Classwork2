#include "control_loop.h"

//We can use the class constructor to set parameters
CONTROLLER::CONTROLLER(float kp_, float kd_, float ki_) {


    _kp = kp_;
    _ki = ki_;
    _kd = kd_;
    
    _eps = 0.001;
    _initial_val = false;

    CONTROLLER::system_start(); 

    //run thread of our system
   
    boost::thread loop_t( &CONTROLLER::loop, this );         //Main control loop

}


//Sense: get input to change the state of our System
void CONTROLLER::set_xdes(double x) {
    _xdes = x; //set desired input

    _initial_val = true; //get out sleep while and start control loop
}


//Random initial value
void CONTROLLER::system_start() {
    
    //Generate a random initial value
    srand((unsigned int)time(NULL)); //start random - initializes random number generation 
    float random = ((float) rand()) / (float) RAND_MAX;
    _xmes = random;
    
}

void CONTROLLER::loop() {
    

    ofstream myfile;

    double err = 0.0;
    double err_p = 0.0;
    double err_d = 0.0;
    double err_i = 0.0;

    double pid = 0.0;
    double output = 0.0;
    double dt = 1.0/100.0;   //sample time - f = 100Hz

 
    while( !_initial_val ) {
        // wait input
        usleep(0.1*1e6);
    }
    
    cout << "LOOP!" << endl;

    myfile.open ("Data.txt");
    myfile << "reference: " << _xdes << "\n";
    myfile.close();

    _xdes == _xmes; //Set the initial value

    //Loop
    while( true ) {

        //PID errors
        err = _xdes - _xmes;
        err_d = (err - err_p) / dt;
        err_i += err*dt;

        //PID action
        pid = _kp*err+ _kd*err_d + _ki*err_i;

        //Output
        output = pid;

        cout << "PID error: " << err << " System output: " << output << endl;
        myfile.open ("Data.txt", ios::app);
        myfile << "PID error: " << err << " System output: " << output << "\n";
        myfile.close();

        if(abs(err)<_eps) break;
        
        usleep(10000); 

        _xmes = output;      //The measured value is updated with the current value (output)
    }
}
