/* multi_fifo_consumer.h */


#ifndef __MULTI_FIFO_CONSUMER_H__
#define __MULTI_FIFO_CONSUMER_H__

#include <systemc.h>

SC_MODULE(MultiFifoConsumer) 
{
    sc_in<bool> clk;
    sc_fifo_in<sc_uint<8> > in;
    sc_out<sc_uint<8> > data_out;  // For tracing

    void consume();

    SC_CTOR(MultiFifoConsumer);
};

#endif // __MULTI_FIFO_CONSUMER_H__
