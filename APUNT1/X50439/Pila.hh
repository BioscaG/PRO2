#ifndef PILA
#define PILA

#include "utils.PRO2"


template <class T> class Pila {

private:
  struct node_pila {
    T info;
    node_pila* seguent;
  }; 
 
  int altura;
  node_pila* primer_node;


static void esborra_node_pila_it(node_pila* m)
 /* Pre: cert */
 /* Post: no fa res si m �s NULL, en cas contrari, allibera espai
    dels nodes de la cadena que t� el node apuntat per m com a primer */
  {
    while (m!=NULL){
      node_pila* n=m->seguent;
      delete m;
      m=n;
    }
  }

public:

  Pila() 
    /* Pre: cert */
    /* Post: El resultat �s una pila sense cap element */
  {
    altura= 0;
    primer_node= NULL;
  }

  
  Pila(const Pila& original) 
    /* Pre: cert */
    /* Post: El resultat �s una c�pia d'original */
  {
    altura= original.altura;
    primer_node = copia_node_pila_it(original.primer_node);
  }
  

  ~Pila() 
    // Destructora: Esborra autom�ticament els objectes locals en
    // sortir d'un �mbit de visibilitat
  {
    esborra_node_pila_it(primer_node);
  }


  void p_buida() 
    /* Pre: cert */
    /* Post: El p.i. passa a ser una pila sense elements i qualsevol
       contingut anterior del p.i. ha estat esborrat */
{
    esborra_node_pila_it(primer_node);
    altura= 0;
    primer_node= NULL;
  }
        
  void empilar (const T& x) 
    /* Pre: cert */
    /* Post: El p.i. �s com el p.i. original amb x afegit
       com a darrer element */
  {
    node_pila* aux;
    aux= new node_pila; // reserva espai pel nou element
    aux->info= x;
    aux->seguent= primer_node;
    primer_node= aux;
    ++altura;
  }

  void desempilar () 
    /* Pre: el p.i. �s una pila no buida (<=> primer_node != NULL) */ 
    /* Post: El p.i. �s com el p.i. original per� sense el darrer
       element afegit al p.i. original */
  {
    node_pila* aux;
    aux= primer_node; // conserva l'acc�s al primer node abans
    //   d'avan�ar
    primer_node= primer_node->seguent; // avan�a
    delete aux; // allibera l'espai de l'antic cim
    --altura;
  }

  T cim() const 
    /* Pre: el p.i. �s una pila no buida (<=> primer_node != NULL) */
    /* Post: el resultat �s el darrer element afegit al p.i. */ 
  { 
    return primer_node->info;
  }

  bool es_buida() const 
    /* Pre: cert */
    /* Post: El resultat indica si el p.i. �s una pila buida o no */
  {
    return primer_node==NULL;
  }

  int mida() const 
    /* Pre: cert */
    /* Post: El resultat �s el nombre d'elements del p.i. */
  {
    return altura;
  }

  node_pila* copia_node_pila_it(node_pila* m) {
    /* Pre: cert */
    /* Post: si m és NULL, el resultat és NULL; en cas contrari, el
       resultat apunta al primer node d'una cadena de nodes que són
       còpia de de la cadena que té el node apuntat per m com a primer */

     if (m == NULL) return NULL;
    node_pila* primer;
    node_pila* n = new node_pila;
    primer = n;
    while (m != NULL) {
      n->seguent = new node_pila;
      n->info = m->info;
      m = m->seguent;
      if (m != NULL) n = n->seguent;
      else n->seguent = NULL;
    }

    return primer;
}
Pila& operator=(const Pila& original) { 
    /* Pre: cert */
    /* Post: El p.i. passa a ser una còpia d'original i qualsevol
       contingut anterior del p.i. ha estat esborrat (excepte si el
       p.i. i original ja eren el mateix objecte) */
    if (this != &original) {
        esborra_node_pila_it(primer_node);
        primer_node = copia_node_pila_it(original.primer_node);
        altura = original.altura;
    }
    return *this;


}



 #include "program.hh"
};

#endif
