#include "Estudiant.hh"
#include <vector>
using namespace std; 

 pair<int,int>  max_min_vest(const vector<Estudiant>& v)
 /* Pre: v no conte repeticions de dni  */
 /* Post: si existeix a v algun estudiant amb nota, la primera component del
    resultat es la posicio de l'estudiant de nota maxima de v i la segona
    component es la posicio de l'estudiant de nota minima de v (si hi ha
    empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
    hi ha cap estudiant amb nota, totes dues components valen -1 */
    {
        pair<int,int> par; 
        par.first = par.second = -1; 
        bool first = false; 
        for (int i = 0; i < v.size(); ++i) {
            if (v[i].te_nota() and not first) {
                par.first = par.second = i; 
                first = true; 
            } 
            else if (v[i].te_nota()) {
                if (v[i].consultar_nota() > v[par.first].consultar_nota()) par.first = i; 
                else if (v[i].consultar_nota() == v[par.first].consultar_nota() and v[i].consultar_DNI() < v[par.first].consultar_DNI()) par.first = i;  
                else if (v[i].consultar_nota() < v[par.second].consultar_nota()) par.second = i;
                else if (v[i].consultar_nota() == v[par.second].consultar_nota() and v[i].consultar_DNI() < v[par.second].consultar_DNI()) par.second = i; 
            }
        }
        return par; 
    }