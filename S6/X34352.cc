#include <map>
#include <iostream>
using namespace std; 

int main() {
    map<string, int> m; 
    map<string, int>::iterator it = m.begin(); 
    char op; 
    string n; 
    while (cin >> op) {
        cin >> n;
        it = m.find(n);
        if (op == 'a') {
            if (it == m.end()) m.insert(make_pair(n, 1));
            else it->second += 1; 
        }
        else {
            if (it == m.end()) cout << 0; 
            else cout << it->second; 
            cout << endl; 
        }
    }
}