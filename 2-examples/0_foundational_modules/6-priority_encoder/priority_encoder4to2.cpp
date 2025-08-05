/* priority_encoder4to2.cpp */


#include "priority_encoder4to2.h"

PriorityEncoder4to2::PriorityEncoder4to2(sc_module_name name) : sc_module(name) 
{
    SC_METHOD(do_encode);
    sensitive << in;
}

void PriorityEncoder4to2::do_encode() 
{
    sc_bv<4> input = in.read();
    valid.write(input != "0000");

    if (input[3] == '1') out.write(3);
    else if (input[2] == '1') out.write(2);
    else if (input[1] == '1') out.write(1);
    else if (input[0] == '1') out.write(0);
    else out.write(0);  // default when all 0
}
