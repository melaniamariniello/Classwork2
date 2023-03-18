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

    double e = 0.0;
    double ep = 0.0;
    double de = 0.0;
    double ie = 0.0;

    double pid = 0.0;
    double c = 0.0;
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
        e = _xdes - _xmes;
        de = (e - ep) / dt;
        ie += e*dt;

        //PID action
        pid = _kp*e+ _kd*de + _ki*ie;

        //Output
        //we assume that the system is an integrator
        c += pid*dt;

        cout << "PID error: " << e << " System output: " << c << endl;
        myfile.open ("Data.txt", ios::app);
        myfile << "PID error: " << e << " System output: " << c << "\n";
        myfile.close();

        if(abs(e)<_eps) break;
        
        usleep(10000); 

        _xmes = c;      //The measured value is updated with the current value (output)
    }
}
