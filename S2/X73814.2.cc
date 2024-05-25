#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

/* LLegir vector d'estudiants */
void leer_vector_est(vector<Estudiant>& vest)
/* Pre: hi ha preparats al canal estandar d'entrada un enter N més gran que 0
   amb les dades dels N estudiants que es volen desar al vector, amb dni >= 0*/
/* Post: vest conte tots el estudiants del canal d'entrada */
{
    {
  int m;
  cin >> m;

  vector<Estudiant> aux_vest(m);
  for (int i = 0; i < m; ++i) {
    aux_vest[i].llegir();
  }

  vest = aux_vest;
}
}

/* Escribir vector estudiantes */
void escribir_vector_est(const vector<Estudiant>& vest)
/* Pre: vest.size >= 1 */
/* Post: S'imprimeixen pel canal estandar de sortida els dni's i notes dels
   estudiants del vector pasat per parametre, fins a trobarse un estudiant amb dni = 0 */
{
    int m = vest.size();
    bool final = false;
    int i = 0;
    while (i < m and not final) {
        if (vest[i].consultar_DNI() == 0) final = true;
        else vest[i].escriure();
        ++i;
    }
}

/* Simplifica un vector de estudiantes*/
vector<Estudiant> simplificar_vector_est(const vector<Estudiant>& vest)
/* Pre: vest contiene almenos un estudiante, y todos los dni's son > 0*/
/* Post: la funcion devuelve un vector con los mismos estudiantes del vector pasado por parametro
    pero, en el caso de estar repetidos, el retornado solo guardara el que tenga la nota mas alta.
    Inicialmente todos los dni's de los estudiantes del vector simplificado se inician a 0,
    de esta manera se pueden utilizar los estudiantes con dni=0 como marca final del vector retornado */
{
    int m = vest.size();
    vector<Estudiant> aux_vest(m, 0);
    int cant_est = 1; // cantidad de estudiantes (cant_est - 1 = pos ultimo estudiante a aux_vest[])
    aux_vest[0] = vest[0];
    for (int i = 1; i < m; ++i) {
        if (vest[i].consultar_DNI() != aux_vest[cant_est - 1].consultar_DNI()) {
            ++cant_est;
            aux_vest[cant_est - 1] = vest[i];
        }
        else if (vest[i].te_nota()) {
            if (not aux_vest[cant_est - 1].te_nota()) aux_vest[cant_est - 1] = vest[i];
            else if (vest[i].consultar_nota() > aux_vest[cant_est - 1].consultar_nota()) aux_vest[cant_est - 1] = vest[i];
        }
    }

    return aux_vest;
}

int main() {
    vector<Estudiant> vest;

    leer_vector_est(vest);
    vector<Estudiant> veste_simplificado = simplificar_vector_est(vest);
    escribir_vector_est(veste_simplificado);
}