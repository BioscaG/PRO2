#include "vectorIOEstudiant.hh"
#include "Estudiant.hh"
#include <iostream>
#include <vector>
using namespace std; 

int main() {
    int v_size; 
    cin >> v_size;
    vector<Estudiant> v(v_size); 
    leer_vector(v); 
    redondear_vector(v); 
    escribir_vector(v); 
}