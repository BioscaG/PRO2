#include "vectorIOEstudiant.hh"
using namespace std; 

void leer_vector(vector<Estudiant>& v) {
    int v_size = v.size(); 
    for (int i = 0; i < v_size; ++i) {
        v[i].llegir(); 
    }
}

void redondear_vector(vector<Estudiant>& v) {
    int v_size = v.size(); 
    for (int i = 0; i < v_size; ++i) {
        if (v[i].te_nota()) v[i].modificar_nota(((int) (10. * (v[i].consultar_nota() + 0.05))) / 10.0);
    }
}

void escribir_vector(vector<Estudiant>& v) {
    int v_size = v.size(); 
    for (int i = 0; i < v_size; ++i) {
        v[i].escriure(); 
    }
} 