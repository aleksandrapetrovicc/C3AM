#include "module1.hpp"

using namespace sc_core;
using namespace std;

module1::module1(sc_module_name n) : sc_module(n)
{

    cout << name() << "constructed.\n";
    SC_THREAD(process);

}

void module1::process()
{
    
    wait(1, SC_NS);


    //if(pfifo -> num_available())
    //{
        
        vector<int> v;

        int n = pfifo -> num_available();

        for(int i = 0; i <= n; i++)
        {

            v.push_back(i);
            pfifo -> read(v[i]);
            cout << v[i] << ' ';

        }
    //}
}