#include "vp.hpp"

vp::vp(sc_core::sc_module_name name, int size, int velicina) : sc_module(name),
    m("Module"),
    m0("Module0"), 
    m1("Module1"),
    f0(size),
    f1(velicina)

{
    SC_REPORT_INFO("Virtual Platform", "Constructed.");

    m.module_module0_socket.bind(m0.module0_module_socket);
    m0.pfifo.bind(f0);
    m1.pfifo.bind(f0);
    m1.nfifo.bind(f1);
    m0.nfifo.bind(f1);
}

vp::~vp()
{
    SC_REPORT_INFO("Virtual Platform", "Destructed.");
}