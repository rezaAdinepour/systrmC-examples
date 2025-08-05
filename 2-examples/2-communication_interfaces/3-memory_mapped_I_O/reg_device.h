/* reg_device.h */


#ifndef __REG_DEVICE_H__
#define __REG_DEVICE_H__

#include <systemc.h>

SC_MODULE(RegDevice) 
{
    sc_in<bool> clk;
    sc_in<sc_uint<4> > addr;
    sc_in<sc_uint<8> > data_out;
    sc_out<sc_uint<8> > data_in;
    sc_in<bool> write_en;
    sc_in<bool> read_en;

    void process();

    SC_CTOR(RegDevice);

private:
    sc_uint<8> registers[4]; // REG_A - REG_D
};

#endif // __REG_DEVICE_H__
