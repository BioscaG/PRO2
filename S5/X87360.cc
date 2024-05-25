#include <list>
using namespace std; 

bool lista(const list<int>& a, int x) {
    list<int>::const_iterator it = a.begin();
    list<int>::const_iterator it_end = a.end();  
    --it_end;
    if (x < *it and x > *it_end) return false; 
    while (it != a.end()) {
        if (x < *it) return false; 
        if (x == *it) return true; 
        ++it; 
    } 
    return false; 
}

void inter(list<int>& uno, const list<int>& dos)
/* Pre: uno = U */
/* Post: uno pasa a ser la interseccion de U y dos */
{
    list<int> inters; 
    list<int>::iterator it_inters = inters.end(); 
    list<int>::iterator it = uno.begin(); 
    while (not uno.empty() and not dos.empty() and it != uno.end()) {
        list<int>::const_iterator it2 = dos.begin(); 
        if (lista(dos, *it)) inters.insert(it_inters, *it); 
        ++it;
    }
    uno = inters; 
}