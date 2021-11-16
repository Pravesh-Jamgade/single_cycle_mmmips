/*
 *  TU Eindhoven
 *  Eindhoven, The Netherlands
 *
 *  Name            :   registerfile.h
 *
 *  Author          :   Sander Stuijk (sander@ics.ele.tue.nl)
 *
 *  Date            :   July 23, 2002
 *
 *  Function        :   Registerfile
 *
 *  History         :
 *      23-07-02    :   Initial version.
 *
 */
 
#ifndef REGISTERFILE_H_INCLUDED
#define REGISTERFILE_H_INCLUDED

#include "systemc.h"
#include "mips.h"

SC_MODULE(REGFILE) {
    sc_in<  sc_bv<AWORDREG> >   r_addr_reg1;
    sc_out< sc_bv<DWORD>    >   r_data_reg1;

    sc_in<  sc_bv<AWORDREG> >   r_addr_reg2;
    sc_out< sc_bv<DWORD>    >   r_data_reg2;
    
    sc_in<  sc_bv<AWORDREG> >   w_addr_reg;
    sc_in<  sc_bv<DWORD>    >   w_data_reg;
    sc_in<  sc_bv<1>        >   w;
    
    sc_in<  bool > clk;
    
    sc_bv<DWORD> rfile[REGSIZE];
    
    void read();
    void write();
    void init();
    
    SC_CTOR(REGFILE) {
        SC_METHOD(read);
        sensitive << r_addr_reg1 << r_addr_reg2;

        SC_METHOD(write);
        sensitive_pos << clk;
        
        init();
    } 
};

#endif
