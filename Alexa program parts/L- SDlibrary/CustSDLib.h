#ifndef CustSDLib_h
#define CustSDLib_h

#if (ARDUINO>=100)
    #include"Arduino.h"
#else
    #include"WProgram.h"
#endif
#include <SD.h>



class CSDL{
    public:
    //Construcotor
    CSDL();
    //Methods
    void setupSD();
    bool FileExist(int fileName);
    void 

