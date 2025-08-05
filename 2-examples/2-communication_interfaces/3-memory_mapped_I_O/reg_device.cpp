/* reg_device.cpp */


#include "reg_device.h"

RegDevice::RegDevice(sc_module_name name) : sc_module(name) 
{
    SC_METHOD(process);
    sensitive << clk.pos();
    for (int i = 0; i < 4; i++) registers[i] = 0;
}

void RegDevice::process() 
{
    if (write_en.read()) 
    {
        if (addr.read() < 4) 
        {
            registers[addr.read()] = data_out.read();
            std::cout << sc_time_stamp() << " - Wrote " << data_out.read()
                      << " to REG[" << addr.read() << "]" << std::endl;
        }
    }

    if (read_en.read()) 
    {
        if (addr.read() < 4) 
        {
            data_in.write(registers[addr.read()]);
        } 
        else 
        {
            data_in.write(0);
        }
    }
}
