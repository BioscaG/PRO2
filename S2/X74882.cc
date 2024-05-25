#include "Estudiant.hh"
#include "Cjt_estudiants.hh"
using namespace std; 

int main() {
    Cjt_estudiants a, b; 
    a.llegir(); 
    b.llegir(); 
    for (int i = 1; i <= a.mida(); ++i) {
        if (a.consultar_iessim(i).te_nota() and b.consultar_iessim(i).te_nota()) {
            if (a.consultar_iessim(i).consultar_nota() < b.consultar_iessim(i).consultar_nota()) {
                a.modificar_iessim(i, b.consultar_iessim(i)); 
            }
        }
        else if (not a.consultar_iessim(i).te_nota()) a.modificar_iessim(i, b.consultar_iessim(i));
    } 
    a.escriure(); 
}