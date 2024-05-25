#include <iostream>
using namespace std; 
 
int main() {
    int n, x; 
    cin >> n >> x; 
    for (int i = 1; i <= n; ++i) {
        int c; 
        int suma = 0; 
        cin >> c; 
        while (c != x) {
            suma += c;  
            cin >> c; 
        }
        string s; 
        getline(cin,s); 
        cout << "La suma de la secuencia " << i << " es " << suma << endl;  
    }
}