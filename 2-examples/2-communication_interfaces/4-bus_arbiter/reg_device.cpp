/* reg_device.cpp */


#include "reg_device.h"

RegDevice::RegDevice(sc_module_name name) : sc_module(name) 
{
    SC_METHOD(process);
    sensitive << clk.pos();
    dont_initialize();
}

void RegDevice::process() 
{
    if (write_en.read()) 
    {
        if (addr.read() < 4) 
        {
            registers[addr.read()] = data_out.read();
            std::cout << sc_time_stamp() << " [DEVICE] Write: addr=" 
                      << addr.read() << ", data=" << data_out.read() << std::endl;
        }
    } 
    else if (read_en.read()) 
    {
        if (addr.read() < 4) 
        {
            data_in.write(registers[addr.read()]);
            std::cout << sc_time_stamp() << " [DEVICE] Read: addr=" 
                      << addr.read() << ", data=" << registers[addr.read()] << std::endl;
        }
    } 
    else 
    {
        data_in.write(0);  // Default value when not reading
    }
}
