/* fifo_producer.h */


#ifndef __FIFO_PRODUCER_H__
#define __FIFO_PRODUCER_H__

#include <systemc.h>

SC_MODULE(FifoProducer) 
{
    sc_in<bool> clk;
    sc_fifo_out<sc_uint<8> > out;

    void produce();

    SC_CTOR(FifoProducer);
};

#endif // FIFO_PRODUCER_H
