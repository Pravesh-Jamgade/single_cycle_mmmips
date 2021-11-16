/*
 *  TU Eindhoven
 *  Eindhoven, The Netherlands
 *
 *  Name            :   register.h
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
 
#ifndef REGISTER_H_INCLUDED 
#define REGISTER_H_INCLUDED

#include "mips.h"

SC_MODULE(REGISTER) {
    sc_in<  sc_bv<DWORD> >  in;     // Data input
    sc_in<  bool >          w;      // Write control signal
    sc_out< sc_bv<DWORD> >  out;    // Data output
    sc_in<  bool >          clk;    // Clock
    
    void reg();
    
    sc_bv<DWORD> data;
    
    SC_CTOR(REGISTER) {
        SC_METHOD(reg);
        sensitive_pos << clk;
        data = 0;
    }
};

#endif
