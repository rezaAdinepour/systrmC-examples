/* tb_multi_fifo.h */


#ifndef __TB_MULTI_FIFO_H__
#define __TB_MULTI_FIFO_H__

#include <systemc.h>
#include "multi_fifo_producer.h"
#include "stage1.h"
#include "stage2.h"
#include "multi_fifo_consumer.h"

SC_MODULE(TB_MultiFifo) 
{
    sc_clock clk;
    sc_fifo<sc_uint<8> > fifo1, fifo2, fifo3;
    sc_signal<sc_uint<8> > consumer_data;

    MultiFifoProducer* producer;
    Stage1* stage1;
    Stage2* stage2;
    MultiFifoConsumer* consumer;

    void trace();

    SC_CTOR(TB_MultiFifo);
    ~TB_MultiFifo();
};

#endif // __TB_MULTI_FIFO_H__
