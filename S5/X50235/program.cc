#include "BinTree.hh"
#include "BinTreeIOint.hh"
using namespace std; 

bool poda_subarbre(BinTree<int> &a, int x) {
    if (a.empty()) return false; 
    if (a.value() == x) {
        a = BinTree<int>();
        return true; 
    }
    bool b = false; 
    BinTree<int> l = a.left();
    b = poda_subarbre(l, x);
    BinTree<int> r = a.right(); 
    if (not b) b = poda_subarbre(r, x);
    int n = a.value(); 
    a = BinTree<int>(n, l, r);
    return b; 
}

