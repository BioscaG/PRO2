#include "BinTreeIOEst.hh"
#include <iostream>
using namespace std; 

bool find(const BinTree<Estudiant>& a, int dni, int& prof, int& nota) {
    if (a.empty()) return false; 
    if (a.value().consultar_DNI() == dni) {
        if (a.value().te_nota()) nota = a.value().consultar_nota();
        return true;
    }
    bool b = false; 
    ++prof; 
    b = find(a.left(), dni, prof, nota);
    if (b) return true; 
    else {
        b = find(a.right(), dni, prof, nota);
        if (not b) --prof; 
        return b; 
    }
}

int main() {
    BinTree<Estudiant> a; 
    read_bintree_est(a);
    int dni; 
    while (cin >> dni) {
        int prof = 0; 
        int nota = -1; 
        cout << dni << ' ';
        if (find(a, dni, prof, nota)) cout << prof << ' ' << nota << endl; 
        else cout << -1 << endl; 
    }
}