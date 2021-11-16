/*
 *  TU Eindhoven
 *  Eindhoven, The Netherlands
 *
 *  Name            :   and.cc
 *
 *  Author          :   Sander Stuijk (sander@ics.ele.tue.nl)
 *
 *  Date            :   July 23, 2002
 *
 *  Function        :   Logial AND port
 *
 *  History         :
 *      23-07-02    :   Initial version.
 *
 */
 
#include "and.h"

void AND::and()
{
    sc_bv<1> a_t, b_t, r_t;

    #ifdef VERBOSE
        cerr << "AND" << endl;
    #endif
    
    // Read inputs
    a_t = a.read();
    b_t = b.read();
    
    // Compute result
    r_t = a_t & b_t;
    
    // Set result on output
    r.write(r_t);
}
