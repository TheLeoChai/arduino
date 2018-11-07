#ifndef controlLibrary_h
#define controlLibrary_h

#if (ARDUINO>=100)
    #include"Arduino.h"
#else
    #include"WProgram.h"
#endif



class move{
    public:
    //Construcotor
    move();
    //Methods
    void setupMovement();
    void Forward();
    void Backward();
    void Left();
    void Right();
    void Stop();
    void enableManualChange ();
    private:
    //nothing needed
};
#endif