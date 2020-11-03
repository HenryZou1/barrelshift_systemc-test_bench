// COE838 - Lab1 SystemC Intro
// BarrelShift Unit Tutorial. 
//////////////////////////////////
//Testbench driver for barrelshift

#include <systemc.h>
#include "barrelshift.h"
#include "alu.h"


int sc_main(int argc, char* argv[]){
	sc_trace_file *tf; 
	sc_signal <sc_int<8> > a, b, shiftout, out ;

	sc_clock clk("clk",10,SC_NS,0.5);
	sc_signal <bool> en,direction,oper; 
	sc_signal <sc_int<3> > shift;
	ALU alu("alu");
	alu.DinA(a);
	alu.DinB(shiftout);
	alu.op(oper);
	alu.Dout(out);
	alu.clk(clk);

	barrel barrelshift("barrel");
	barrelshift.enable(en);
	barrelshift.l_r(direction);
	barrelshift.shift_amt(shift);
	barrelshift.din(b);
	barrelshift.dout(shiftout);
	barrelshift.clk(clk);

	tf = sc_create_vcd_trace_file("trace_file"); 
	tf->set_time_unit(1, SC_NS);
	sc_trace(tf, clk, "clk");
	sc_trace(tf, a, "a");
	sc_trace(tf, b, "b");
	sc_trace(tf, shiftout, "shiftout");
	sc_trace(tf, en, "enable");
	sc_trace(tf, direction, "direction");
	sc_trace(tf, oper, "operation");
	sc_trace(tf, shift, "shift");

	sc_trace(tf, out, "data_out");

	a.write(5);
	b.write(3);
	en.write(0);
	direction.write(0);
	oper.write(0);
	shift.write(1);
	sc_start(10, SC_NS);

	oper.write(1);
	sc_start(10, SC_NS);

	en.write(1);
	sc_start(10, SC_NS);
	direction.write(1);
	sc_start(10, SC_NS);
	sc_start(10, SC_NS);
	
   	sc_close_vcd_trace_file(tf);




	return 0;                         
}
