/*
 *  TU Eindhoven
 *  Eindhoven, The Netherlands
 *
 *  Name            :   rom.cc
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
 
#include "rom.h"

void ROM::read()
{
    sc_uint<DWORD> addr_t;
    sc_uint<1> w_t, r_t;
    sc_uint<DWORD> data, data_t;
    
    #ifdef VERBOSE
        cerr << "ROM" << endl;
    #endif

    addr_t = a_read.read();

    if (addr_t < RAMSIZE) {
        data = 0;
            #ifdef BIG_ENDIAN
            for (int i = 0; i < (DWORD / 8); i++) {
            #else   // Little-endian
            for (int i = (DWORD / 8) - 1; i >= 0; i--) {
            #endif
            data = data << 8;
            data_t = romfile[addr_t + i];
            data = data | data_t; 
        }
        d_read.write(data);
    }
}

void ROM::init(const char *filename)
{
    sc_uint<DWORD>  word;
    int  addr = 0;
    char c;
    
    ifstream romf(filename, ios::binary);
    
    while (!romf.eof()) {
        word = 0;
        
        romf.get(c);
        if(romf.eof()) break;
        word = c & 0xff;
        
        romfile[addr] = word;
        addr++;
        
        #ifdef VERBOSE
        cerr << "loaded " << word << " @ " << (addr - 1) << endl;
        #endif
         
        if (addr >= ROMSIZE)
            break; 
    }
}
