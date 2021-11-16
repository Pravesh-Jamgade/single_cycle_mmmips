/*
 *  TU Eindhoven
 *  Eindhoven, The Netherlands
 *
 *  Name            :   mux.cc
 *
 *  Author          :   Sander Stuijk (sander@ics.ele.tue.nl)
 *
 *  Date            :   July 23, 2002
 *
 *  Function        :   Multiplexer
 *
 *  History         :
 *      23-07-02    :   Initial version.
 *
 */
 
#include "mux.h"

void MUX2::mux()
{
    sc_bv<DWORD> data;
    
    #ifdef VERBOSE
        cerr << "MUX" << endl;
    #endif
    
    // Read correct input
    if(sel.read() == 0)
        data = in0.read();
    else
        data = in1.read();
    
    // Write output
    out.write(data);
}

void MUX2_AWORDREG::mux()
{
    sc_bv<AWORDREG> data;
    
    #ifdef VERBOSE
        cerr << "MUX" << endl;
    #endif
    
    if(sel.read() == 0)
        data = in0.read();
    else
        data = in1.read();
    
    out.write(data);
}
