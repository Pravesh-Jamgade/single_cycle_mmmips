/*
 *  TU Eindhoven
 *  Eindhoven, The Netherlands
 *
 *  Name            :   ram.h
 *
 *  Author          :   Sander Stuijk (sander@ics.ele.tue.nl)
 *
 *  Date            :   July 23, 2002
 *
 *  Function        :   RAM
 *
 *  History         :
 *      23-07-02    :   Initial version.
 *
 */
 
#ifndef RAM_H_INCLUDED
#define RAM_H_INCLUDED

#include "mips.h"

SC_MODULE(RAM) {
    sc_in < sc_bv<DWORD> > a_read;
    sc_out< sc_bv<DWORD> > d_read;
    sc_in<  sc_bv<DWORD> > a_write;
    sc_in<  sc_bv<DWORD> > d_write;
    sc_in<  sc_bv<1>     > w;
    sc_in<  sc_bv<1>     > r;
    sc_in<  bool         > clk;
    
    sc_bv<8> ramfile[RAMSIZE];
    
    void read();
    void write();
    void init(const char *filename);
    void dump(const char *filename);

    SC_CTOR(RAM) {
        SC_METHOD(read);
        sensitive << a_read << r;

        SC_METHOD(write);
        sensitive_pos << clk;
    };
};

#endif
