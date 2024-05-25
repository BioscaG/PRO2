#include "Cjt_estudiants.hh"


void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
    b = false; 
    int dni = est.consultar_DNI(); 
    int pos = cerca_dicot(vest, 0, nest - 1, dni);
    if (vest[pos].consultar_DNI() == dni) b = true;
    else {
        ++nest; 
        for (int i = nest - 1; i > pos + 1; --i) vest[i] = vest[i - 1];
        vest[pos + 1] = est;  
        if (est.te_nota()) {
            ++nest_amb_nota; 
            suma_notes += est.consultar_nota(); 
        } 
    }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
    b = true; 
    int pos = cerca_dicot(vest, 0, nest - 1, dni);
    if (vest[pos].consultar_DNI() != dni) b = false; 
    else {
        if (vest[pos].te_nota()) {
            suma_notes -= vest[pos].consultar_nota(); 
            --nest_amb_nota;
        }
        for (int i = pos; i < nest; ++i) {
            vest[i] = vest[i + 1];
        }
        --nest;
    }
}
