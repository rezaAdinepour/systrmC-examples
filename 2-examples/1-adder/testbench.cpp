/* testbench.cpp */

#include "testbench.h"

Testbench::Testbench(sc_module_name name) : sc_module(name)
{
    adder = new Adder("adder");
    adder->a(sig_a);
    adder->b(sig_b);
    adder->sum(sig_sum);

    SC_THREAD(stimulus);
}

Testbench::~Testbench() 
{
    delete adder;
}

void Testbench::stimulus() 
{
    sig_a.write(10);
    sig_b.write(5);
    wait(1, SC_NS);
    cout << "10 + 5 = " << sig_sum.read() << endl;

    sig_a.write(20);
    sig_b.write(15);
    wait(1, SC_NS);
    cout << "20 + 15 = " << sig_sum.read() << endl;

    sc_stop();
}
