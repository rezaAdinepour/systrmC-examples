/* consumer.cpp */


#include "consumer.h"

Consumer::Consumer(sc_module_name name) : sc_module(name) 
{
    SC_THREAD(receive);
    sensitive << clk.pos();
}

void Consumer::receive() 
{
    while (true) 
    {
        wait();  // wait for clock

        // simulate readiness 50% of the time
        ready.write(rand() % 2);

        if (valid.read() && ready.read()) 
        {
            std::cout << sc_time_stamp() << " - Received: " << data.read() << std::endl;
        }
    }
}
