#include <list>
#include <iostream>
using namespace std; 

void afegir(list<int>& l, int n) {
    list<int>::iterator it = l.end(); 
    l.insert(it, n);
}

bool eliminar(list<int>& l, int n) {
    list<int>::iterator it = l.begin(); 
    while (it != l.end()) {
        if (*it == n) {
            it = l.erase(it);
            return true; 
        }
        ++it; 
    }
    return false; 
}

int max_list(const list<int>& l) {
    list<int>::const_iterator it = l.begin(); 
    int max = -1;
    bool inici = true; 
    while (it != l.end()) {
        if (inici) {
            max = *it;
            inici = false; 
        }
        else {
            if (*it > max) max = *it;
        }
        ++it; 
    }
    return max; 
}

int min_list(const list<int>& l) {
    list<int>::const_iterator it = l.begin(); 
    int min = -1;
    bool inici = true; 
    while (it != l.end()) {
        if (inici) {
            min = *it;
            inici = false; 
        }
        else {
            if (*it < min) min = *it;
        }
        ++it; 
    }
    return min; 
}

void write(bool empty, int max, int min, double mitj) {
    if (empty) cout << 0; 
    else {
        cout << min << ' ' << max << ' ' << mitj; 
    }
    cout << endl; 
}

int main() {
    int codi, n, max, min; 
    max = min = 0; 
    double suma, mitj; 
    mitj = suma = 0; 
    bool inici = true; 
    list<int> l; 
    cin >> codi >> n; 
    while (codi != 0) {  
        if (codi == -1) {
            if (inici) {
                max = min = n;
                inici = false;
            }
            afegir(l, n);
            if (n > max) max = n; 
            if (n < min) min = n; 
            suma += n; 
        }
        else if (eliminar(l, n) and not l.empty()) {
            if (max == n) max = max_list(l);
            if (min == n) min = min_list(l);
            suma -= n;
        }
        mitj = suma/l.size();
        if (l.empty()) inici = true; 
        write(l.empty(), max, min, mitj);
        cin >> codi >> n; 
    }
}