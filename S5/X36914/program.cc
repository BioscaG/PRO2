#include "LlistaIOEstudiant.hh"
using namespace std; 

int main() {
    list<Estudiant> l; 
    LlegirLlistaEstudiant(l);
    int n, n_vegades; 
    cin >> n; 
    n_vegades = 0; 
    list<Estudiant>::const_iterator it = l.begin(); 
    while (it != l.end()) {
        if ((*it).consultar_DNI() == n) ++n_vegades; 
        ++it; 
    }
    cout << n << ' ' << n_vegades << endl; 
}