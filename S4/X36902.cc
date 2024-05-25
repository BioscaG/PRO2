#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<char> s;
    char c;
    int count = 0; 
    cin >> c; 
    bool correcte = true; 
    while (c != '.' and correcte) {
        ++count; 
        if (c == '(' or c == '[') s.push(c);
        else if (c == ')' and not s.empty() and s.top() == '(') s.pop();
        else if (c == ']' and not s.empty() and s.top() == '[') s.pop(); 
        else correcte = false; 
        cin >> c; 
    }
    if (s.empty() and correcte) cout << "Correcte" << endl; 
    else cout << "Incorrecte " << count << endl; 
}