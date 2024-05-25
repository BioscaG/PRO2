#include <set>
#include <list>
#include <map>
#include <iostream>
using namespace std; 

set<string> inters(const set<string>& a, const set<string>& b) {
    set<string> inters; 
    set<string>::const_iterator it = a.begin();
    while (it != a.end()) {
        if (b.find(*it) != b.end()) inters.insert(*it);
        ++it; 
    }
    return inters; 
}

set<string> rep(const set<string>& a, const set<string>& b) {
    set<string> rep;
    set<string>::const_iterator it = a.begin();
    while (it != a.end()) {
        if (b.find(*it) == b.end()) rep.insert(*it);
        ++it; 
    }
    return rep; 
}

int main() {
    string cognom;
    set<string> s_cogn; 
    cin >> cognom; 
    while (cognom != ".") {
        s_cogn.insert(cognom);
        cin >> cognom; 
    }
    int n; 
    cin >> n; 
    list<set<string>> l; 
    list<set<string>>::iterator it = l.end(); 
    for (int i = 0; i < n; ++i) {
        set<string> s; 
        string act; 
        cin >> act;
        while (act != ".") { 
            s.insert(act);
            cin >> act; 
        }
        l.insert(it, s);
    }
    set<string> inters_set; 
    it = l.begin(); 
    inters_set = s_cogn; 
    for (int i = 0; i < l.size(); ++i) {
        inters_set = inters(*it, inters_set);
        ++it; 
    }
    cout << "Totes les activitats:"; 
    set<string>::const_iterator it_inters = inters_set.begin(); 
    while (it_inters != inters_set.end()) {
        cout << ' ' << *it_inters;
        ++it_inters;
    }
    cout << endl; 
    cout << "Cap activitat:";
    it = l.begin(); 
    set<string> rep_set; 
    rep_set = s_cogn; 
    for (int i = 0; i < l.size(); ++i) {
        rep_set = rep(rep_set, *it);
        ++it; 
    }
    set<string>::const_iterator it_rep = rep_set.begin(); 
    while (it_rep != rep_set.end()) {
        cout << ' ' << *it_rep;
        ++it_rep;
    }
    cout << endl; 
}