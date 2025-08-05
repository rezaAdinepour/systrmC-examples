/* multi_fifo_producer.h */


#ifndef __MULTI_FIFO_PRODUCER_H__
#define __MULTI_FIFO_PRODUCER_H__

#include <systemc.h>

SC_MODULE(MultiFifoProducer) 
{
    sc_in<bool> clk;
    sc_fifo_out<sc_uint<8> > out;

    void produce();

    SC_CTOR(MultiFifoProducer);
};

#endif // __MULTI_FIFO_PRODUCER_H__
