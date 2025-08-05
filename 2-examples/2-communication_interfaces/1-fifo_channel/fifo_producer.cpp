/* fifo_producer.cpp */


#include "fifo_producer.h"

FifoProducer::FifoProducer(sc_module_name name) : sc_module(name) 
{
    SC_THREAD(produce);
    sensitive << clk.pos();
}

void FifoProducer::produce() 
{
    sc_uint<8> val = 0;

    while (true) 
    {
        wait();  // wait for clk

        if (out.num_free() > 0) 
        {
            out.write(val);
            std::cout << sc_time_stamp() << " - Producer wrote: " << val << std::endl;
            val++;
        }
    }
}
