#include "alu.h"
void ALU :: alu_method(){
	sc_int<8> dataa;
	sc_int<8> datab;
	dataa = DinA.read();
	datab = DinB.read();
	if(op.read() == 0){
		Dout.write(dataa-datab); 
	}
	else 
		Dout.write(dataa+datab); 	 
	
}

