#include "BinTreeIOEst.hh"
using namespace std; 

void read_bintree_est(BinTree<Estudiant>& a)
// Pre: a és buit; el canal estandar d’entrada conté una seqüència
// de parells <int, double> que representa un arbre binari d’estudiants
// en preordre, on un parell amb l’int = ‘‘marca’’ representa
// un arbre buit
// Post: a conté l’arbre que hi havia al canal estandar d’entrada
{
    Estudiant n;
    n.llegir(); 
    if (n.consultar_DNI() != 0) {
        BinTree<Estudiant> l;
        read_bintree_est(l);
        BinTree<Estudiant> r; 
        read_bintree_est(r);
        a = BinTree<Estudiant>(n, l, r);
    }
}
