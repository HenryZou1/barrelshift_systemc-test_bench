// COE838 - Lab1 SystemC Intro
// BarrelShift Unit Tutorial. 
//////////////////////////////////

#ifndef ALU_H   
#define ALU_H

#include <systemc.h>       


                                
SC_MODULE(ALU) {
	
    sc_in< sc_int<8> > DinA;
	sc_in< sc_int<8> > DinB;
	sc_in <bool> clk;
	sc_in < bool > op ;  
	sc_out < sc_int<8> > Dout;
 
	void alu_method();   
 
        SC_CTOR(ALU) {

        SC_METHOD(alu_method);
		dont_initialize();

         sensitive << clk.neg(); //edge sensitive
    }

};
#endif 
