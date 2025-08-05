/* tb_fifo.cpp */


#include "tb_fifo.h"

TB_Fifo::TB_Fifo(sc_module_name name)
    : sc_module(name), clk("clk", 5, SC_NS), fifo(4)  // FIFO depth = 4
{
    producer = new FifoProducer("producer");
    producer->clk(clk);
    producer->out(fifo);

    consumer = new FifoConsumer("consumer");
    consumer->clk(clk);
    consumer->in(fifo);
}

TB_Fifo::~TB_Fifo() 
{
    delete producer;
    delete consumer;
}
