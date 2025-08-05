/* stage1.cpp */


#include "stage1.h"

Stage1::Stage1(sc_module_name name) : sc_module(name) 
{
    SC_THREAD(process);
    sensitive << clk.pos();
}

void Stage1::process() 
{
    while (true) {
        wait();
        sc_uint<8> val = in.read();
        val += 1;  // stage1 modifies data
        out.write(val);
    }
}
