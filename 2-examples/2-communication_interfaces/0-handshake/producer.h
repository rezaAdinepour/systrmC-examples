/* producer.h */


#ifndef __PRODUCER_H__
#define __PRODUCER_H__

#include <systemc.h>

SC_MODULE(Producer) 
{
    sc_in<bool> clk;
    sc_in<bool> ready;
    sc_out<bool> valid;
    sc_out<sc_uint<8> > data;

    void send();

    SC_CTOR(Producer);
};

#endif // __PRODUCER_H__
