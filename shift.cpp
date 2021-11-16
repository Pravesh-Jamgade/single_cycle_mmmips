/*
 *  TU Eindhoven
 *  Eindhoven, The Netherlands
 *
 *  Name            :   shift.cc
 *
 *  Author          :   Sander Stuijk (sander@ics.ele.tue.nl)
 *
 *  Date            :   July 23, 2002
 *
 *  Function        :   Shifter
 *
 *  History         :
 *      23-07-02    :   Initial version.
 *
 */
 
#include "shift.h"

void SHIFTRIGHT::shiftright()
{
    sc_bv<DWORD> a;
    sc_bv<DWORD> b;
    
    #ifdef VERBOSE
        cerr << "SHIFTRIGHT" << endl;
    #endif
    
    a = in.read();
    b = a >> SHIFTBIT;
    out.write(b);

    #ifdef VERBOSE
        cerr << "Shifter: " << a;
        cerr << " -> ";
        cerr << b << endl;
    #endif
}

void SHIFTLEFT::shiftleft()
{
    sc_bv<DWORD> a;
    sc_bv<DWORD> b;
    
    #ifdef VERBOSE
        cerr << "SHIFT" << endl;
    #endif
    
    a = in.read();
    b = a << SHIFTBIT;
    out.write(b);
    
    #ifdef VERBOSE
        cerr << "Shifter: " << a;
        cerr << " -> ";
        cerr << b << endl;
    #endif
}
