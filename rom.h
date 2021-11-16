/*
 *  TU Eindhoven
 *  Eindhoven, The Netherlands
 *
 *  Name            :   rom.h
 *
 *  Author          :   Sander Stuijk (sander@ics.ele.tue.nl)
 *
 *  Date            :   July 23, 2002
 *
 *  Function        :   ROM
 *
 *  History         :
 *      23-07-02    :   Initial version.
 *
 */
 
#ifndef ROM_H_INCLUDED
#define ROM_H_INCLUDED

#include "mips.h"

SC_MODULE(ROM) {
    sc_in < sc_bv<DWORD> > a_read;
    sc_out< sc_bv<DWORD> > d_read;
    
    sc_bv<DWORD> romfile[ROMSIZE];
    
    void read();
    void init(const char *filename);

    SC_CTOR(ROM) {
        SC_METHOD(read);
        sensitive << a_read;
    };
};

#endif
