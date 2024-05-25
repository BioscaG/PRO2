#include "LlistaIOParInt.hh"
using namespace std;

int main() {
    list<ParInt> l; 
    LlegirLlistaParInt(l);
    int n, n_veg, n_suma; 
    cin >> n; 
    n_veg = n_suma = 0; 
    list<ParInt>::const_iterator it = l.begin(); 
    while (it != l.end()) {
        if ((*it).primer() == n) {
            ++n_veg; 
            n_suma += (*it).segon(); 
        }
        ++it; 
    }
    cout << n << ' ' << n_veg << ' ' << n_suma << endl; 
}