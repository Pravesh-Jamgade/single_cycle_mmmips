/*
 *  TU Eindhoven
 *  Eindhoven, The Netherlands
 *
 *  Name            :   and.h
 *
 *  Author          :   Sander Stuijk (sander@ics.ele.tue.nl)
 *
 *  Date            :   July 23, 2002
 *
 *  Function        :   Logial AND port
 *
 *  History         :
 *      23-07-02    :   Initial version.
 *
 */
 
#ifndef AND_H_INCLUDED
#define AND_H_INCLUDED

#include "mips.h"

SC_MODULE(AND) {
    sc_in<  sc_bv<1> > a;   // First operand
    sc_in<  sc_bv<1> > b;   // Second operand
    sc_out< sc_bv<1> > r;   // Result
    
    void and();
    
    // Constructor
    SC_CTOR(AND) {
        SC_METHOD(and);
        sensitive << a << b;
    }
};

#endif
