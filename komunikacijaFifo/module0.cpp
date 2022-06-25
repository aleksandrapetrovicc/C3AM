#include "module0.hpp"

using namespace sc_core;
using namespace std;

module0::module0(sc_module_name n) : sc_module(n)
{
    cout << name() << "constructed.\n";
    SC_THREAD(process);
}

void module0::process()
{
        
    vector<int> v {7, 5, 1, 3, 4, 5, 3, 3, 4, 5};

    for(int i = 0; i < v.size(); i++)
    {
        
        pfifo -> write(v[i]);

    }
}