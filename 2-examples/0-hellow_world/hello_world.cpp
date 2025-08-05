/* All systemC modules should include systemc.h header file */
#include "systemc.h"


/* hello_world is the module name */
SC_MODULE(hello_world)
{
    SC_CTOR(hello_world)
    {
        /* nothing in constructor */
    }
    void start()
    {
        cout << "=== Hello World from SystemC environment === \n";
    }
};

/* sc_main in top level function like in C++ main */
int sc_main(int argc, char* argv[])
{
    hello_world hello("HELLO");

    /* Print the hello world */
    hello.start();
    return 0;
}