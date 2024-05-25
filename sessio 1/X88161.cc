#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> Row; 
typedef vector<Row> Matrix; 

Matrix crear_matriu() {
    Matrix m(4, Row(2)); 
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) cin >> m[i][j]; 
    }
    return m; 
}

int main() {
    int n; 
    for (int i = 0; i < n; ++i) {
        Matrix m = crear_matriu(); 
        

        
    }
}