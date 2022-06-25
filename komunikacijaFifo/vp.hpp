#ifndef VP_HPP
#define VP_HPP

#include <systemc>
#include "module0.hpp"
#include "module1.hpp"

using namespace sc_core;

SC_MODULE(vp)
{
    public:
        SC_HAS_PROCESS(vp);

        vp(sc_module_name, int);

    protected:
        sc_fifo <int> f0;
        module0 m0;
        module1 m1;
};
#endif