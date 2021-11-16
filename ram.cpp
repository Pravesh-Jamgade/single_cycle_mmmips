/*
 *  TU Eindhoven
 *  Eindhoven, The Netherlands
 *
 *  Name            :   ram.cc
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
 
#include "ram.h"

void RAM::read()
{
    sc_uint<DWORD>  addr_t, data_t;
    sc_uint<1>      r_t;
    sc_uint<DWORD>  data;
    
    #ifdef VERBOSE
        cerr << "RAM" << endl;
    #endif
    
    // Check that data must be read from mem
    r_t = r.read();

    if(r_t == 1) {
        addr_t = a_read.read();
        
        if (addr_t < RAMSIZE) {
            data = 0;
            #ifdef BIG_ENDIAN
            for (int i = 0; i < (DWORD / 8); i++) {
            #else // Little-endian
            for (int i = (DWORD / 8) - 1; i >= 0; i--) {
            #endif
                data = data << 8;
                data_t = ramfile[addr_t + i];
                data = data | data_t; 
            }
            d_read.write(data);
        }
    }
}

void RAM::write()
{
    sc_uint<DWORD>  addr_t, data_t;
    sc_uint<1>      w_t;
    sc_uint<DWORD>  data;
    
    #ifdef VERBOSE
        cerr << "RAM" << endl;
    #endif
    
    // Check that data must be written to mem
    w_t = w.read();

    if(w_t == 1) {
        addr_t = a_write.read();
        data = d_write.read();
        
        if (addr_t < RAMSIZE) {
            #ifdef BIG_ENDIAN
            for (int i = (DWORD / 8); i > 0; i--) {
                ramfile[addr_t + i - 1] = data & 0xff;
            #else // Little-endian
            for (int i = 0; i < (DWORD / 8); i++) {
                ramfile[addr_t + i] = data & 0xff;
            #endif
                data = data >> 8;
            }
        }
        else {
            cerr << "WARNING: writting to invalid memory location." << endl;
        }
    } 
}

void RAM::init(const char *filename)
{
    sc_uint<DWORD>  word;
    int  addr = 0;
    char c;
    
    ifstream ramf(filename, ios::binary);
    
    while (!ramf.eof()) {
        word = 0;
        
        ramf.get(c);
        if(ramf.eof()) break;
        word = c;
        
        ramfile[addr] = word;
        addr++;
        
        if (addr >= RAMSIZE)
            break; 
    }
}

void RAM::dump(const char *filename)
{
    ofstream ramf(filename, ios::binary);
    char c;
    sc_uint<8> a;
    
    for (unsigned int i = 0; i < RAMSIZE; i++)
    {
        a = ramfile[i];
        c = (char)(a);
        ramf.put(c);
    }
    
    ramf.close();
}

