#include "BinTree.hh"
#include "ParInt.hh"

void sumak(BinTree<ParInt>& a, int k)
/*Pre: a = A */
/*Post: a es com a A amb k sumat al segon component de cada node */
{
    if (not a.empty()) {
        ParInt p(a.value().primer(), a.value().segon() + k);
        BinTree<ParInt> l = a.left(); 
        sumak(l, k);
        BinTree<ParInt> r = a.right();
        sumak(r, k);
        a = BinTree<ParInt>(p, l, r);
    }
}