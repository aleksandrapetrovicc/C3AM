#include "module1.hpp"
#include "module0.hpp"
#include <vector>

using namespace sc_core;
using namespace std;
using std::vector;

vector<int> v;
vector<int> c {1, 2, 3, 4, 5, 6, 8}; 
module1::module1(sc_module_name n) : sc_module(n)
{

    SC_REPORT_INFO("module1", "Constructed.");
   // cout << name() << "constructed.\n";
    SC_THREAD(upisivanje);
    SC_THREAD(citanje);

}

module1::~module1()
{
    SC_REPORT_INFO("module1", "Destcructed.");
}

void module1::citanje()
{
    cout<<endl;
    wait(1, SC_NS);

    int n = pfifo -> num_available();

    cout<<"module1 citanje-staro: ";
    for(int i = 0; i <= n; i++)
    {
        v.push_back(pfifo -> read());
       cout << v[i] << ' '; //donji niz
    }
}

void module1::upisivanje()
{
    cout<<endl;
    cout<<"module1 upis-novo: ";
    for(int j = 0; j < c.size(); j++)
    {
        c[j] = c[j] * 2;
        nfifo -> write(c[j]);
        cout<<c[j]<<' ';
    }
}

