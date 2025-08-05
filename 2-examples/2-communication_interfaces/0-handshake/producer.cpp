/* producer.cpp */


#include "producer.h"

Producer::Producer(sc_module_name name) : sc_module(name) 
{
    SC_THREAD(send);
    sensitive << clk.pos();
}

void Producer::send() 
{
    sc_uint<8> value = 0;

    while (true) {
        wait();  // wait for clock

        if (ready.read()) 
        {
            valid.write(1);
            data.write(value++);
        } 
        else 
        {
            valid.write(0);
        }
    }
}
