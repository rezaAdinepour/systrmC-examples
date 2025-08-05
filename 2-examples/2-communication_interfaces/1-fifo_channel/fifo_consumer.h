/* fifo_consumer.h */


#ifndef __FIFO_CONSUMER_H__
#define __FIFO_CONSUMER_H__

#include <systemc.h>

SC_MODULE(FifoConsumer) 
{
    sc_in<bool> clk;
    sc_fifo_in<sc_uint<8> > in;

    void consume();

    SC_CTOR(FifoConsumer);
};

#endif // __FIFO_CONSUMER_H__
