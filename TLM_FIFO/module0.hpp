#ifndef _MODULE0_HPP_
#define _MODULE0_HPP_

#include "module.hpp"
#include <tlm>
#include <tlm_utils/simple_target_socket.h>
#include <vector>

using namespace sc_core;

typedef tlm::tlm_base_protocol_types::tlm_payload_type pl_t;
typedef tlm::tlm_base_protocol_types::tlm_phase_type ph_t;

class module0 : public sc_core::sc_module
{
    public:
        SC_HAS_PROCESS(module0);
        sc_port <sc_fifo_out_if <int>> pfifo;
        sc_port <sc_fifo_in_if <int>> nfifo;
        module0(sc_core::sc_module_name name);
        ~module0();
        

        tlm_utils::simple_target_socket <module0> module0_module_socket;

    protected:
            void upisivanje();
            void citanje();
            void b_transport(pl_t&, sc_core::sc_time&);
            
            int control;
};
#endif