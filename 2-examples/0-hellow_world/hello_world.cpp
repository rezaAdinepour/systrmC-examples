/* All systemC modules should include systemc.h header file */
#include "systemc.h"


/* hello_world is the module name */
SC_MODULE(hello_world)
{
    SC_CTOR(hello_world)
    {
        SC_THREAD(print_message);
    }
    void print_message()
    {
        cout << "=== Hello World from SystemC environment ===" << endl;
    }
};

/* sc_main in top level function like in C++ main */
int sc_main(int argc, char* argv[])
{
    hello_world hello("hello_instance");
    sc_start();  // Start the simulation
    return 0;
}