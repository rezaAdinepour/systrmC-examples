/* multi_fifo_producer.c */


#include "multi_fifo_producer.h"

MultiFifoProducer::MultiFifoProducer(sc_module_name name) : sc_module(name) 
{
    SC_THREAD(produce);
    sensitive << clk.pos();
}

void MultiFifoProducer::produce() 
{
    sc_uint<8> val = 0;
    while (true) {
        wait();
        out.write(val++);
    }
}
