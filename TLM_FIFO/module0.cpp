#include "module0.hpp"
#include "module1.hpp"
#include <vector>

using namespace std;
using namespace sc_core;
using std::vector;

vector<int> a;
vector<int> b;

module0::module0(sc_module_name name) : sc_module(name)
{
    module0_module_socket.register_b_transport(this, &module0::b_transport);

    SC_REPORT_INFO("module0", "Constructed.");
    SC_THREAD(upisivanje);
    SC_THREAD(citanje);
}

module0::~module0()
{
    SC_REPORT_INFO("module0", "Destcructed.");
}

void module0::b_transport(pl_t& p1, sc_time& offset)
{   
    tlm_command cmd     = p1.get_command();
    //uint64 addr         = p1.get_address();
    unsigned char *data = p1.get_data_ptr();
    unsigned int length = p1.get_data_length();


    switch(cmd)
    {
        case TLM_WRITE_COMMAND:
            control = *((int*)data);
            a.push_back(control);
            cout << control << ' '; 
//            cout << endl;
            p1.set_response_status(TLM_OK_RESPONSE);
        break;

        case TLM_READ_COMMAND: 
        
        break;

        default:
            p1.set_response_status(TLM_COMMAND_ERROR_RESPONSE);
            SC_REPORT_ERROR("MODULE0", "TLM_wrong_address");
        break;
    }
}

void module0::upisivanje()
{
    cout<<endl;
    cout<<"module0 upis-staro: ";
    for(int i = 0; i < a.size(); i++)
    {
        pfifo -> write(a[i]);
        cout<<a[i] << ' ';
    }
}

void module0::citanje()
{
    cout<<endl;
    wait(1, SC_NS);
    
    int k = nfifo -> num_available();

    cout<<"module0 citanje-novo: ";
    for(int j = 0; j < k; j++)
    {
        b.push_back(nfifo -> read());
        cout << b[j]<<' ';
    }
}
