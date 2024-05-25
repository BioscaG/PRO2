#include "LlistaIOEstudiant.hh"

void LlegirLlistaEstudiant(list<Estudiant>& l)
// Pre: l és buida; el canal estandar d’entrada conté parelles
// de valors <enter, double>, acabat per un parell 0 0
// Post: s’han afegit al final de l els estudiants llegits fins al 0 0 (no inclòs)
{
    list<Estudiant>::iterator it = l.end();
    Estudiant est;
    est.llegir(); 
    while (est.consultar_DNI() != 0) {
        l.insert(it, est);
        est.llegir(); 
    }
}