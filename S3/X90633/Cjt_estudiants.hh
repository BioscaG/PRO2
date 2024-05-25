#ifndef CONJ_EST_HH
#define CONJ_EST_HH

#include "Estudiant.hh"
#include <vector>

class Cjt_estudiants {

private:

  // Representa un conjunt d'estudiants ordenat per DNI.  
  
  vector<Estudiant> vest;
  int nest; 
  static const int MAX_NEST = 10001; // nombre maxim d'elements del conjunt
  int nest_amb_nota;  
  double suma_notes;

  /* 
     Invariant de la representaci�: 
     - vest[0..nest-1] est� ordenat creixentment pel DNI dels estudiants
       i no cont� estudiants repetits
     - 0 <= nest_amb_nota <= nest <= vest.size() = MAX_NEST
     - nest_amb_nota �s el nombres d'estudiants amb nota de vest[0..nest-1]
     - suma_notes �s la suma de les notes (dels estudiants amb nota) de vest[0..nest-1]
  */  
    
  void ordenar_cjt_estudiants();
  /* Pre: cert */
  /* Post: el elements del par�metre impl�cit passen a estar ordenats
     creixentment per DNI. */
     
  static int cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x);
  /* Pre: els elements de vest estan ordenats creixentment per DNI,
     0<=left, right<vest.size(), right>=left-1 */
  /* Post: si x hi �s vest[left..right], el resultat �s la posici� que
     hi ocupa, si no, �s la posici� que hauria d'ocupar */
 
  
public:

  //Constructores

  Cjt_estudiants();
  /* Pre: cert */
  /* Post: crea un conjunt d'estudiants buit */

  //Modificadores

  void afegir_estudiant(const Estudiant &est, bool& b);
  /* Pre: el par�metre impl�cit no est� ple */
  /* Post: b = indica si el p.i. original cont� un estudiant amb el dni d'est;
     si b = fals, s'ha afegit l'estudiant est al par�metre impl�cit */

  void esborrar_estudiant(int dni, bool& b);
  /* Pre: cert */
  /* Post: b indica si el par�metre impl�cit original tenia un estudiant 
     amb el dni dni; si b, aquest estudiant ha quedat eliminat
     del par�metre impl�cit */

  //Consultores
	
  int mida() const;
  /* Pre: cert */
  /* Post: El resultat �s el nombre d'estudiants del par�metre impl�cit */

  static int mida_maxima();
  /* Pre: cert */
  /* Post: el resultat es el nombre maxim d'estudiants que pot arribar
     a tenir el parametre implicit */
  
  double mitjana_estudiants_amb_nota() const;
  /* Pre: cert */
  /* Post: el resultat �s la mitjana de les notes dels estudiants amb nota
     del par�metre impl�cit; si no n'hi ha cap, el resultat �s -1 */ 

  // Lectura i escriptura
	
  void llegir();
  /* Pre: cert */
  /* Post: el par�metre impl�cit cont� el conjunt d'estudiants llegits
     del canal est�ndar d'entrada */

  void escriure() const;
  /* Pre: cert */
  /* Post: s'han escrit pel canal est�ndar de sortida 
     els estudiants del conjunt que cont� el par�metre 
     impl�cit en ordre ascendent per DNI */

};

#endif
