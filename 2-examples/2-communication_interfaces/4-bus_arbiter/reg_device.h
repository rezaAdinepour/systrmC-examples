/* reg_device.h */


#ifndef __REG_DEVICE_H__
#define __REG_DEVICE_H__

#include <systemc.h>

SC_MODULE(RegDevice) 
{
    sc_in<bool> clk;
    sc_in<bool> write_en;
    sc_in<bool> read_en;
    sc_in<sc_uint<4> > addr;
    sc_in<sc_uint<8> > data_out;  // Data from master (write)
    sc_out<sc_uint<8> > data_in;  // Data to master (read)

    sc_uint<8> registers[4];  // Simple register file

    void process();

    SC_CTOR(RegDevice);
};

#endif // __REG_DEVICE_H__
