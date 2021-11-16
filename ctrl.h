/*
 *  TU Eindhoven
 *  Eindhoven, The Netherlands
 *
 *  Name            :   ctrl.h
 *
 *  Author          :   Sander Stuijk (sander@ics.ele.tue.nl)
 *
 *  Date            :   July 23, 2002
 *
 *  Function        :   Single cycle controller
 *
 *  History         :
 *      23-07-02    :   Initial version.
 *
 */
 
#ifndef CTRL_H_INCLUDED
#define CTRL_H_INCLUDED

#include "mips.h"

SC_MODULE(CTRL) {
    sc_in<  sc_bv<6> >      Opcode; // Instruction bits [31-26]
    sc_out< sc_bv<1> >      RegDst;
    sc_out< sc_bv<1> >      Branch;
    sc_out< sc_bv<1> >      MemRead;
    sc_out< sc_bv<1> >      MemtoReg;
    sc_out< sc_bv<2> >      ALUop;
    sc_out< sc_bv<1> >      MemWrite;
    sc_out< sc_bv<1> >      ALUSrc;
    sc_out< sc_bv<1> >      RegWrite;
    sc_out< sc_bv<DWORD> >  c4; // Constant value 4
    
    void ctrl();
    
    // Constructor
    SC_CTOR(CTRL) {
        SC_METHOD(ctrl);
        sensitive << Opcode;
    }
};
#endif
