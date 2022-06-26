#include "vp.hpp"

vp::vp(sc_core::sc_module_name name, int size) : sc_module(name),
    inicijator("Module"),
    cilj("Module0"), 
    m1("Module1"),
    f0(size)

{
    SC_REPORT_INFO("Virtual Platform", "Constructed.");

    inicijator.module_module0_socket.bind(cilj.module0_module_socket);
    cilj.pfifo.bind(f0);
    m1.pfifo.bind(f0);
}

vp::~vp()
{
    SC_REPORT_INFO("Virtual Platform", "Destructed.");
}