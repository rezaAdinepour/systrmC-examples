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
    // === VCD Trace Setup ===
    sc_trace_file* tf = sc_create_vcd_trace_file("waveform");
    tf->set_time_unit(1, SC_NS); // optional: sets time resolution to nanoseconds

    sc_trace(tf, sig_a, "a");
    sc_trace(tf, sig_b, "b");
    sc_trace(tf, sig_sum, "sum");

    // === Stimuli ===
    sig_a.write(10);
    sig_b.write(5);
    wait(1, SC_NS);
    cout << "10 + 5 = " << sig_sum.read() << endl;

    sig_a.write(20);
    sig_b.write(15);
    wait(1, SC_NS);
    cout << "20 + 15 = " << sig_sum.read() << endl;

    // === Close trace file ===
    sc_close_vcd_trace_file(tf);

    sc_stop();  // End simulation
}
