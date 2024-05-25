#include "Estudiant.hh"
using namespace std; 

int main() {
    Estudiant est, est2; 
    est.llegir();
    est2.llegir();  
    cout << est.operator!=(est2) << endl; 
    cout << est.operator==(est2) << endl; 
}