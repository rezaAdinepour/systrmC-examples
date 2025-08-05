/* stage2.cpp */


#include "stage2.h"

Stage2::Stage2(sc_module_name name) : sc_module(name) 
{
    SC_THREAD(process);
    sensitive << clk.pos();
}

void Stage2::process() 
{
    while (true) 
    {
        wait();
        sc_uint<8> val = in.read();
        val += 2;  // stage2 modifies data
        out.write(val);
    }
}
