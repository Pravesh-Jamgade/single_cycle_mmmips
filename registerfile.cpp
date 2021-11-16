/*
 *  TU Eindhoven
 *  Eindhoven, The Netherlands
 *
 *  Name            :   registerfile.cc
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
 
#include "registerfile.h"

void REGFILE::read()
{
    sc_uint<AWORDREG> a_wreg, a_reg1, a_reg2;
    sc_uint<DWORD> d_wreg;
    
	#ifdef VERBOSE
	   cerr << "REGFILE" 
	   << " Time is:" << sc_get_curr_simcontext()->time_stamp() << endl;
	#endif

	a_reg1 = r_addr_reg1.read();
	a_reg2 = r_addr_reg2.read();
	r_data_reg1.write(rfile[(int)(a_reg1)]);
	r_data_reg2.write(rfile[(int)(a_reg2)]);

	#ifdef VERBOSE
  	   cerr << "...reading $" << a_reg1 << " = " << rfile[a_reg1] << " $"
	   << a_reg2 << " = " << rfile[a_reg2] << endl;
	#endif
}
void REGFILE::write()
{
    sc_uint<AWORDREG> a_wreg, a_reg1, a_reg2;
    sc_uint<DWORD> d_wreg;
    sc_uint<1> w_t;

	#ifdef VERBOSE
	cerr << "REGFILE write" << endl;
	#endif

	w_t = w.read();
	if (w_t == 1) 
	{
		a_wreg = w_addr_reg.read();
		d_wreg = w_data_reg.read();

		#ifdef VERBOSE
		cerr << "...writing $" << a_wreg << " = " << d_wreg<< endl;
		#endif

		if (a_wreg < REGSIZE && a_wreg != 0)
		{
		rfile[(int)(a_wreg)] = d_wreg;
		}
	}
}

void REGFILE::init()
{
    rfile[0] = 0;
}
