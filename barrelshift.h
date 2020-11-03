// COE838 - Lab1 SystemC Intro
// BarrelShift Unit Tutorial. 
//////////////////////////////////

#ifndef BARRELSHIFT_H   
#define BARRELSHIFT_H

#include <systemc.h>       


//void make_barrel();
                                
SC_MODULE(barrel) {

	sc_in <bool> enable;
	sc_in <bool> l_r;
	sc_in <bool> clk;
    sc_in <sc_int<8> > din;
	sc_in <sc_int<3> > shift_amt;
	sc_out <sc_int<8> > dout;
 	
	void barrel_method();   
 
        SC_CTOR(barrel) {

        SC_METHOD(barrel_method);
		dont_initialize();
        sensitive << clk.pos(); //edge sensitive
    }

};
#endif 
