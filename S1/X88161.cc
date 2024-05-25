#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

struct par{
    int x; 
    int y; 
}; 

typedef vector<par> Rowpar; 
typedef vector<Rowpar> Matrixpar; 

struct equip{
    int num; 
    int punts; 
    int marcats; 
    int rebuts; 
}; 

Matrixpar crear_matrix_par(int n) {
    Matrixpar m(n, Rowpar(n)); 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cin >> m[i][j].x >> m[i][j].y; 
    }
    return m; 
}

bool cmp(equip a, equip b) {
    int a_gols = a.marcats - a.rebuts; 
    int b_gols = b.marcats - b.rebuts; 
    if (a.punts == b.punts) {
        if (a_gols == b_gols) return (a.num < b.num); 
        return (a_gols > b_gols); 
    }
    return (a.punts > b.punts); 
}

void informacio(vector<equip>& v, Matrixpar& m, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            v[i].marcats += m[i][j].x; 
            v[i].rebuts += m[i][j].y; 
            v[j].rebuts += m[i][j].x; 
            v[j].marcats += m[i][j].y; 
            if (m[i][j].x > m[i][j].y) v[i].punts += 3; 
            else if (m[i][j].x < m[i][j].y) v[j].punts += 3; 
            else if (i != j) {
                v[i].punts += 1; 
                v[j].punts += 1; 
            } 
        }
    }
}

void write_vector(const vector<equip>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].num + 1 << ' ' << v[i].punts << ' ' <<  v[i].marcats << ' ' << v[i].rebuts << endl; 
    }
}

int main() {
    int n; 
    cin >> n; 
    Matrixpar m = crear_matrix_par(n);
    vector<equip> v(n);
    for (int i = 0; i < n; ++i) v[i].num = i; 
    informacio(v, m, n); 
    sort(v.begin(), v.end(), cmp); 
    write_vector(v);
}

