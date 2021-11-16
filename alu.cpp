/*
 *  TU Eindhoven
 *  Eindhoven, The Netherlands
 *
 *  Name            :   alu.cc
 *
 *  Author          :   Sander Stuijk (sander@ics.ele.tue.nl)
 *
 *  Date            :   July 23, 2002
 *
 *  Function        :   Arithmetic  Logic Unit
 *
 *  History         :
 *      23-07-02    :   Initial version.
 *
 */

#include "alu.h"
 
void ALU::alu()
{
    sc_bv<DWORD>    result;
    sc_bv<1>        zero;
    sc_uint<DWORD>  s;
    sc_uint<DWORD>  t;
    sc_uint<3>      ctrl_t;
    
    #ifdef VERBOSE
        cerr << "ALU" << endl;
    #endif
    
    // Read the inputs
    s = a.read();
    t = b.read();
    ctrl_t = ctrl.read();
    
    // Calculate result using selected operation
    switch (ctrl_t) {
        case ALU_AND:// And
                    result = s & t;
                    break;

        case ALU_OR:// Or
                    result = s | t;
                    break;

        case ALU_ADD:// Add
                    result = s + t;
                    break;

        case ALU_SUB:// Subtract
                    result = s - t;
                    break;

        case ALU_SLT:// Set-on-less-than
                    if (s < t)
                        result = 1;
                    else
                        result = 0;
                    break;
    }

    // Calculate the zero output
    if (result == 0)
        zero = 1;
    else
        zero = 0;

    // Write results to output
    r.write(result);
    z.write(zero);
}
