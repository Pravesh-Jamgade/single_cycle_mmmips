/*
 *  TU Eindhoven
 *  Eindhoven, The Netherlands
 *
 *  Name            :   register.cc
 *
 *  Author          :   Sander Stuijk (sander@ics.ele.tue.nl)
 *
 *  Date            :   July 23, 2002
 *
 *  Function        :   Register
 *
 *  History         :
 *      23-07-02    :   Initial version.
 *
 */
 
#include "register.h"

void REGISTER::reg()
{
    #ifdef VERBOSE
        cerr << "REGISTER" << endl;
    #endif

    if(w.read()) {
        data = in.read();   // Write signal, read data from input

        #ifdef VERBOSE
            cerr << "Reg (write): " << data << endl;
        #endif
    }

    out.write(data);    // Write data to output
    
    #ifdef VERBOSE
        cerr << "Reg (out): " << data << endl;
    #endif   
}
