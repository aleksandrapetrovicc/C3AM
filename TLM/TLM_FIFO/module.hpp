#ifndef _MODULE_HPP_
#define _MODULE_HPP_

#include "module0.hpp"
#include <systemc>
#include <tlm_utils/simple_initiator_socket.h>
#include <tlm_utils/simple_target_socket.h>
#include <vector>
#include <tlm>
#include <iostream>
#include <string>

using namespace sc_core;
using namespace sc_dt;
using namespace tlm;
using namespace std;
//using namespace cv;

typedef tlm::tlm_base_protocol_types::tlm_payload_type pl_t;
typedef tlm::tlm_base_protocol_types::tlm_phase_type ph_t;

class module : public sc_core::sc_module
{
    public:
        module(sc_core::sc_module_name name);
        ~module();
        tlm_utils::simple_initiator_socket <module> module_module0_socket;

    protected:
        pl_t pl;
        sc_core::sc_time offset;

        void komunikacija();
};
#endif
