/*
 *  TU Eindhoven
 *  Eindhoven, The Netherlands
 *
 *  Name            :   mux.h
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
 
#ifndef MUX_H_INCLUDED
#define MUX_H_INCLUDED

#include "mips.h"

SC_MODULE(MUX2) {
    sc_in<  sc_bv<DWORD> >  in0;    // First input
    sc_in<  sc_bv<DWORD> >  in1;    // Second input
    sc_in<  sc_bv<1> >      sel;    // Selection bit
    sc_out< sc_bv<DWORD> >  out;    // Output
    
    void mux();
    
    SC_CTOR(MUX2) {
        SC_METHOD(mux);
        sensitive << in0 <<in1 << sel;
    }
};

SC_MODULE(MUX2_AWORDREG) {
    sc_in<  sc_bv<AWORDREG> >   in0;    // First input
    sc_in<  sc_bv<AWORDREG> >   in1;    // Second input
    sc_in<  sc_bv<1> >          sel;    // Selection bit
    sc_out< sc_bv<AWORDREG> >   out;    // Output
    
    void mux();
    
    SC_CTOR(MUX2_AWORDREG) {
        SC_METHOD(mux);
        sensitive << in0 << in1 << sel;
    }
};

#endif
