// COE838 - Lab1 SystemC Intro
// BarrelShift Unit Tutorial. 
//////////////////////////////////
#include "barrelshift.h"

void barrel :: barrel_method(){
	sc_int<8> data;
	sc_int <8> shift;
	sc_int<8> temp;
	int i,x ;

	if(enable.read() == 1){
		data = din.read();
		shift = shift_amt.read();
		if(l_r.read() == 0){ //shift left
			cout << "[left]  Data = " << data.to_string(SC_BIN) << endl;
			for (x = 0; shift > x; x++){
				for(i = 7; i > 0; i--)
					temp[i] = data[i-1];
				temp[0] = 0;
				data = temp;
			}
			
 
		}else if(l_r.read() == 1){
		cout << "[right]  Data = " << data.to_string(SC_BIN) << endl;
			for (x = 0; shift > x; x++){
				for(i = 0; 7 > i; i++)
					temp[i] = data[i+1];
				temp[7] = 0;
				data = temp;
			}	
		}
		dout.write(temp);
		cout << "[out]  Data = " << temp.to_string(SC_BIN) << endl;
	}
	else 
		dout.write(din.read());
		cout << "Not enabled "<<endl;
}


