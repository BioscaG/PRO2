#include "Estudiant.hh"
#include <vector>
#include <iostream>
using namespace std; 

vector<bool> vector_bool(const vector<int>& v, int size) {
    vector<bool> b(size, false);
    for (int i = 0; i < v.size(); ++i) b[v[i] - 1] = true; 
    return b; 
}

int main() {
    int m, n, s; 
    cin >> m >> n >> s; 
    vector<int> s_vector(s); 
    for (int i = 0; i < s; ++i) cin >> s_vector[i];   
    vector<bool> b = vector_bool(s_vector, n); 
    for (int i = 0; i < m; ++i) { 
        int dni; 
        cin >> dni; 
        Estudiant est(dni); 
        double mitj = 0; 
        for (int k = 0; k < n; ++k) {
            double nota; 
            cin >> nota; 
            if (b[k]) mitj += nota/s;
        }
        est.afegir_nota(mitj); 
        est.escriure(); 
    }
}