#include <iostream>
#include <queue>
#include "BinTreeIOParInt.hh"
using namespace std; 

bool find(const BinTree<ParInt>& a, int& prof, int& parella, int n) {
    if (a.empty()) return false; 
    ParInt p = a.value(); 
    if (p.primer() == n) {
        parella = p.segon(); 
        return true; 
    }

    else {
        bool b = false; 
        ++prof; 
        b = find(a.left(), prof, parella, n);
        if (b) return true; 
        else {
            b = find(a.right(), prof, parella, n);
            if (not b) --prof; 
            return b; 
        }
    }
}

int main() {
    BinTree<ParInt> a; 
    read_bintree_parint(a);
    int n; 
    while (cin >> n) {
        int prof = 0; 
        int parella = -1;
        find(a, prof, parella, n);
        if (parella != -1) cout << n << ' ' << parella << ' ' << prof << endl; 
        else cout << -1 << endl; 
    }
}