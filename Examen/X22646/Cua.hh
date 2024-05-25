#ifndef CUA
#define CUA

#include "utils.PRO2"

template <class T> class Cua {
private:
  struct node_cua {
    T info;
    node_cua* seguent;
  }; 
  int longitud;
  node_cua* primer_node;
  node_cua* ultim_node;

static node_cua* copia_node_cua(node_cua* m, node_cua* &u) 
    /* Pre: cert */
    /* Post: si m �s NULL, el resultat i u s�n NULL; en cas contrari, 
       el resultat apunta al primer node d'una cadena de nodes que s�n c�pia de
       de la cadena que t� el node apuntat per m com a primer, i u apunta a 
       l'�ltim node */
  { 
    // op. privada
    node_cua *n;
    if (m == NULL) {n = NULL; u = NULL;}
    else {
      n = new node_cua;
      n->info = m->info;
      n->seguent = NULL;
      node_cua* aux = m->seguent;
      node_cua* prev = n;
      while (aux != NULL) {
        node_cua* n2 = new node_cua;
        n2->info = aux->info;
        prev->seguent = n2;
        prev = n2;
        aux = aux->seguent;
        u = n2;
      }

    }
    return n;
  }



static void esborra_node_cua(node_cua* m) 
    /* Pre: cert */
    /* Post: no fa res si m �s NULL, en cas contrari, allibera espai
       dels nodes de la cadena que t� el node apuntat per m com a
       primer */
  { 
    while (m != NULL) {
      node_cua* aux = m->seguent;
      delete m;
      m = aux;
    }
  }


public:



void i_trenar(node_cua* c1, node_cua* c2, bool& ultim) {
  if (c2 == NULL) return; 
  if (c1 == NULL) {
    c1 = c2;
    ultim = true; 
    return; 
  }
  node_cua* aux_c1 = c1->seguent;
  node_cua* aux_c2 = c2->seguent;
  c1->seguent = c2;
  if (c1->seguent != NULL) c1->seguent->seguent = aux_c1;
  i_trenar(c1->seguent->seguent, aux_c2, ultim);
}


   void trenat(Cua &c)
 /* Pre: p.i. = C1, c = C2 */
 /* Post: el p.i. passa a ser el resultat de trenar C1 i C2; c passa a ser buida */
 {
  longitud += c.longitud;
  c.longitud = 0; 
  bool ultim = false; 
  i_trenar(primer_node, c.primer_node, ultim);
  if (ultim == true) ultim_node = c.ultim_node;
  c.primer_node = NULL; 
  c.ultim_node = NULL; 
 }



  Cua() 
    /* Pre: cert */
    /* Post: El resultat �s una cua sense cap element */
  {
    longitud= 0;
    primer_node= NULL;
    ultim_node= NULL;
  }

  Cua(const Cua& original) 
    /* Pre: cert */
    /* Post: El resultat �s una c�pia d'original */
  {
    longitud= original.longitud;
    primer_node= copia_node_cua(original.primer_node,ultim_node);
 }


  ~Cua() 
    // Destructora: Esborra autom�ticament els objectes locals en
    // sortir d'un �mbit de visibilitat
  {
    esborra_node_cua(primer_node);
  }

  Cua& operator=(const Cua& original) 
    /* Pre: cert */
    /* Post: El p.i. passa a ser una c�pia d'original i qualsevol
       contingut anterior del p.i. ha estat esborrat 
       (excepte si el p.i. i original ja eren el mateix objecte) */
  {
    if (this != &original) {
      longitud= original.longitud;
      esborra_node_cua(primer_node);
      primer_node = copia_node_cua(original.primer_node, ultim_node);
    }
    return *this;
  }

  void c_buida() 
    /* Pre: cert */
    /* Post: El p.i. passa a ser una cua sense elements i qualsevol
       contingut anterior del p.i. ha estat esborrat */
  {
    esborra_node_cua(primer_node);
    longitud= 0;
    primer_node= NULL;
    ultim_node= NULL;
  }
        
  void demanar_torn (const T& x) 
    /* Pre: cert */
    /* Post: El p.i. �s com el p.i. original amb x afegit
       com a darrer element */
  {
    node_cua* aux;
    aux= new node_cua; // reserva espai pel nou element
    aux->info= x;
    aux->seguent= NULL;
    if (primer_node == NULL) primer_node= aux;
    else ultim_node->seguent= aux;
    ultim_node= aux;
    ++longitud;
  }

  void avancar () 
    /* Pre: el p.i. �s una cua no buida (<=> primer_node != NULL) */ 
    /* Post: El p.i. �s com el p.i. original per� sense el primer
       element afegit al p.i. original */
  {
    node_cua* aux;
    aux= primer_node; // conserva l'acc�s al primer node abans d'avan�ar
    if (primer_node->seguent == NULL) {
      primer_node= NULL;  ultim_node= NULL;
    }
    else primer_node= primer_node->seguent; // avan�a
    delete aux; // allibera l'espai de l'antic cim
    --longitud;
  }
    
  void concat(Cua& c)
  {
    if (not c.es_buida()) {
      if (longitud == 0) {
        primer_node = c.primer_node;
        ultim_node = c.ultim_node;
        longitud = c.longitud;
      } else {
        ultim_node->seguent = c.primer_node;
        ultim_node = c.ultim_node;
        longitud += c.longitud;
      }
      c.primer_node = NULL;
      c.ultim_node = NULL;
      c.longitud = 0;
    }
  }

  T primer() const 
    /* Pre: el p.i. �s una cua no buida (<=> primer_node != NULL) */
    /* Post: el resultat �s el primer element afegit al p.i. */ 
  {
    return primer_node->info;
  }

  bool es_buida() const 
    /* Pre: cert */
    /* Post: El resultat indica si el p.i. �s una cua buida o no */
  {
    return longitud==0;
  }

  int mida() const 
    /* Pre: cert */
    /* Post: El resultat �s el nombre d'elements del p.i. */
  {
    return longitud;
  }


  #include "program.hh"

};



#endif
