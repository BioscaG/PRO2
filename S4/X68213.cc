#include <iostream>
#include <stack>
#include <vector>
using namespace std; 

void escriure_stack(stack<string> s) {
    while (not s.empty()) {
        cout << s.top() << endl; 
        s.pop(); 
    }
}

int main() {
    int n; 
    cin >> n; 
    vector<stack<string>> v(n);
    cin >> n; 
    while (n != -4) {
        if (n == -1) {
            string s; 
            int cat; 
            cin >> s >> cat;
            --cat; 
            v[cat].push(s);
        }
        else if (n == -2) {
            int num, cat; 
            cin >> num >> cat;
            --cat; 
            for (int i = 0; i < num; ++i) v[cat].pop();
        }
        else {
            int cat; 
            cin >> cat; 
            cout << "Pila de la categoria " << cat << endl; 
            --cat;
            escriure_stack(v[cat]); 
            cout << endl; 
        }
        cin >> n; 
    }
}