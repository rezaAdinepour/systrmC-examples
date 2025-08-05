/* tb_fifo.h */


#ifndef __TB_FIFO_H__
#define __TB_FIFO_H__

#include <systemc.h>
#include "fifo_producer.h"
#include "fifo_consumer.h"

SC_MODULE(TB_Fifo) 
{
    sc_clock clk;
    sc_fifo<sc_uint<8> > fifo;

    FifoProducer* producer;
    FifoConsumer* consumer;

    SC_CTOR(TB_Fifo);
    ~TB_Fifo();
};

#endif // __TB_FIFO_H__
