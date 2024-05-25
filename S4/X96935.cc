#include <iostream>
#include <stack>
using namespace std;

int main() {

    stack<int> s;
    int n;
    cin  >> n;
    int x;
    for (int i = 0; i < n/2; ++i) {
        cin >> x;
        s.push(x);
    }
    if (n%2 != 0) cin >> x; 
    bool diferent = false; 
    for (int i = 0; i < n/2 and not diferent; ++i) {
        cin >> x; 
        if (x != s.top()) diferent = true;
        s.pop(); 
    }
    if (diferent) cout << "NO" << endl; 
    else cout << "SI" << endl; 
}

