#ifndef _VP_HPP_
#define _VP_HPP_

#include "module.hpp"
#include "module0.hpp"
#include "module1.hpp"

class vp : public sc_core::sc_module
{
    public:
        SC_HAS_PROCESS(vp);
        vp(sc_core::sc_module_name name, int, int);
        ~vp();
    
    protected:
        module m;
        module0 m0;
        sc_fifo <int> f0;
        sc_fifo <int> f1;
        module1 m1;
};
#endif