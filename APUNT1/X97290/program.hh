  node_llista* copia_node_llista_it (node_llista* m, node_llista* oact, node_llista* &u, node_llista* &a)
    /* Pre: cert */
    /* Post: si m és NULL, el resultat, u i a són NULL; en cas
       contrari, el resultat apunta al primer node d'una cadena de
       nodes que són còpia de la cadena que té el node apuntat per m
       com a primer, u apunta a l'últim node, a és o bé NULL si oact
       no apunta a cap node de la cadena que comença amb m o bé apunta
       al node còpia del node apuntat per oact */
  { 
    u = NULL;
    a = NULL;
    if (m == NULL) return NULL;
    node_llista* primer = new node_llista;
    node_llista* aux = primer;
    node_llista* aux_ant = NULL;
    while (m != NULL) {
      aux->ant = aux_ant;
      aux->info = m->info;
      aux->seg = new node_llista;
      if (oact == m) a = aux;
      m = m->seg;
      u = aux;
      aux_ant = aux;
      aux = aux->seg;
    }
    aux_ant->seg = NULL;
    return primer;
  }

  Llista& operator=(const Llista& original) 
    /* Pre: cert */
    /* Post: El p.i. passa a ser una còpia d'original i qualsevol
       contingut anterior del p.i. ha estat esborrat (excepte si el
       p.i. i original ja eren el mateix objecte) */
  {
    if (this != &original) {
      esborra_node_llista_it(primer_node);
      primer_node = copia_node_llista_it(original.primer_node, original.act, ultim_node, act);
      longitud = original.longitud;
    }
    return *this;
  }