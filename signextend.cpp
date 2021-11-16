/*
 *  TU Eindhoven
 *  Eindhoven, The Netherlands
 *
 *  Name            :   signextend.h
 *
 *  Author          :   Sander Stuijk (sander@ics.ele.tue.nl)
 *
 *  Date            :   July 23, 2002
 *
 *  Function        :   Sign extension
 *
 *  History         :
 *      23-07-02    :   Initial version.
 *
 */

#include "signextend.h"

void SIGNEXTEND::signextend()
{
    sc_bv<SIGNEXTENDBIT> a;
    sc_bv<DWORD> b;
    
    #ifdef VERBOSE
        cerr << "SIGNEXTEND" << endl;
    #endif
    
    a = in.read();
    
    b = a;
    
    for (unsigned int i = SIGNEXTENDBIT; i < DWORD; i++)
        b[i] = a[SIGNEXTENDBIT - 1];
    
    out.write(b);
}
