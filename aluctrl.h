/*
 *  TU Eindhoven
 *  Eindhoven, The Netherlands
 *
 *  Name            :   aluctrl.h
 *
 *  Author          :   Sander Stuijk (sander@ics.ele.tue.nl)
 *
 *  Date            :   July 23, 2002
 *
 *  Function        :   ALU controller
 *
 *  History         :
 *      23-07-02    :   Initial version.
 *
 */
 
#ifndef ALUCTRL_H_INCLUDED
#define ALUCTRL_H_INCLUDED

#include "mips.h"

SC_MODULE(ALUCTRL) {
    sc_in<  sc_bv<6> >  functionCode;   // Bit [0,5] of instruction
    sc_in<  sc_bv<2> >  ALUop;          // ALU operation code
    sc_out< sc_bv<3> >  ALUctrl;        // Control output to ALU
    
    void aluctrl();
    
    // Constructor
    SC_CTOR(ALUCTRL) {
        SC_METHOD(aluctrl);
        sensitive << functionCode << ALUop;
    }
};

#endif
