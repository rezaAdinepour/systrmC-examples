/* consumer.h */


#ifndef __CONSUMER_H__
#define __CONSUMER_H__

#include <systemc.h>

SC_MODULE(Consumer) 
{
    sc_in<bool> clk;
    sc_in<bool> valid;
    sc_in<sc_uint<8> > data;
    sc_out<bool> ready;

    void receive();

    SC_CTOR(Consumer);
};

#endif // __CONSUMER_H__
