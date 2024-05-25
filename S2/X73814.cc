#include "Estudiant.hh"
#include <vector>
#include <iostream>
using namespace std; 

void leer_vector(vector<Estudiant>& v) {
    int v_size = v.size(); 
    for (int i = 0; i < v_size; ++i) {
        v[i].llegir(); 
    }
}

void escribir_vector(vector<Estudiant>& v, int pos) { 
    for (int i = 0; i < pos; ++i) {
        v[i].escriure(); 
    }
} 

vector<Estudiant> simplificar_vector(const vector<Estudiant>& v, int& pos) {
    int vsize = v.size(); 
    vector<Estudiant> v_aux(vsize, 0); 
    pos = 0; 
    for (int i = 0; i < vsize; ++i) {
        int j = i; 
        bool encontrado = false; 
        ++j; 
        while (not encontrado and i != (vsize - 1)) {
            if (v[i].consultar_DNI() == v[j].consultar_DNI()) {
                if (not v[i].te_nota() or v[j].consultar_nota() > v[i].consultar_nota()) i = j;
                ++j; 
            }
            else encontrado = true;  
        }
        v_aux[pos] = v[i]; 
        ++pos; 
        i = j - 1; 
    }
    return v_aux; 
}

int main() {
    int n; 
    cin >> n;
    vector<Estudiant> v(n);
    leer_vector(v); 
    int pos; 
    vector<Estudiant> v_simpl = simplificar_vector(v, pos); 
    escribir_vector(v_simpl, pos); 
}