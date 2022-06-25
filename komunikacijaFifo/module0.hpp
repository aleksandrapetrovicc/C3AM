#ifndef _MODULE0_HPP_
#define _MODULE0_HPP_

#include <systemc>
#include <vector>

using namespace sc_core;

SC_MODULE(module0)
{
    public:
        SC_HAS_PROCESS(module0);

        module0(sc_module_name);

        sc_port <sc_fifo_out_if <int>> pfifo;            

    protected:
        void process();
};
#endif