#include "CuaIOParInt.hh"
#include "ParInt.hh"
using namespace std; 

int main() {
    int temps_q1, temps_q2; 
    temps_q1 = temps_q2 = 0; 
    queue<ParInt> q, q1, q2;
    llegirCuaParInt(q);
    while (not q.empty()) {
        if (temps_q1 <= temps_q2) {
            q1.push(q.front()); 
            temps_q1 += q.front().segon(); 
        }
        else {
            q2.push(q.front()); 
            temps_q2 += q.front().segon(); 

        }
        q.pop();
    }
    while (not q1.empty()) {
        q1.front().escriure(); 
        q1.pop();
    }
    cout << endl; 
    while (not q2.empty()) {
        q2.front().escriure(); 
        q2.pop();
    }
}