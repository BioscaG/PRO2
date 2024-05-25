#include <queue>
#include <iostream>
using namespace std; 


int minim (queue<int> q) {
    int min = 1001; 
    while (not q.empty()) {
        if (q.front() < min) min = q.front();
        q.pop(); 
    }
    return min; 
}

int maxim (queue<int> q) {
    int max = -1001;
    while (not q.empty()) {
        if (q.front() > max) max = q.front();
        q.pop();
    } 
    return max; 
}

int main() {
    int n; 
    queue<int> q; 
    cin >> n; 
    int max = -1001; 
    int min = 1001;
    double suma = 0; 
    double mitj = 0; 
    while (n >= -1001 and n <= 1000) {
        if (n == -1001) {
            int k;
            if (not q.empty()) {
                k = q.front();
                suma -= k;
                q.pop();
                if (k == max) max = maxim(q);
                if (k == min) min = minim(q); 
                mitj = suma/q.size(); 
            }  
        }
        else {
            q.push(n);
            if (n > max) max = n; 
            if (n < min) min = n;
            suma += n;
            mitj = suma/q.size();
        }

        if (not q.empty()) {
            cout << "min " << min << "; max " << max << "; media " << mitj << endl;
        } 
        else cout << 0 << endl; 
        cin >> n; 
    }
}