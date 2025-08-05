/* fifo_consumer.cpp */


#include "fifo_consumer.h"

FifoConsumer::FifoConsumer(sc_module_name name) : sc_module(name) 
{
    SC_THREAD(consume);
    sensitive << clk.pos();
}

void FifoConsumer::consume() 
{
    while (true) 
    {
        wait();  // wait for clk

        if (in.num_available() > 0) 
        {
            sc_uint<8> val = in.read();
            std::cout << sc_time_stamp() << " - Consumer read:  " << val << std::endl;
        }
    }
}
