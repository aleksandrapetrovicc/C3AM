#include "module.hpp"

SC_HAS_PROCESS(module);

module::module(sc_module_name name) : sc_module(name), offset(sc_core::SC_ZERO_TIME)
{
    SC_THREAD(komunikacija);
    SC_REPORT_INFO("module", "Constructed.");
}

module::~module()
{
    SC_REPORT_INFO("module", "Destructed.");
}

void module::komunikacija()
{
    vector<int> v {7, 5, 1, 3, 8};

    for(int i = 0; i < v.size(); i++)
    {
        //int v = 5;
        pl_t p1;
        p1.set_command(TLM_WRITE_COMMAND);
        //p1.set_address();
        p1.set_data_ptr((unsigned char*)&v[i]);
        p1.set_data_length(1);
        p1.set_response_status(TLM_INCOMPLETE_RESPONSE);

        module_module0_socket -> b_transport(p1, offset);
    }
}

