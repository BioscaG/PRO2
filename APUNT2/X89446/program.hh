  Llista  reorganitzar_out(const T& x) const
  /* Pre: cert */
  /* Post: el resultat és una llista que conté els mateixos 
  elements que el p.i. tal que tots els més petits o iguals 
  que x al p.i. precedeixen als més grans que x al p.i. però 
  sempre respectant l'ordre que hi havia entre ells al p.i. 
  L'element actual de la llista retornada és el primer dels 
  més grans que x, si existeix, sinó es situa a la detra del 
  tot. El p.i. no es modifica */
  { 
    Llista l;
    if (longitud == 0) return l; 
    l.primer_node = new node_llista;
    l.longitud = longitud;
    node_llista* l_node = l.primer_node;
    node_llista* node_act = primer_node; 
    node_llista* l_node_ant = NULL; 
    while (node_act != NULL) {
      if (node_act->info < x) {
        if (l.act != NULL) {
          node_llista* aux = l.act->ant;
          node_llista* aux_ant = aux->ant;
          if (aux_ant != NULL) {
            aux_ant->seg = new node_llista;
            node_llista* aux_ant_ant = aux_ant->seg;
            aux_ant_ant->ant = aux_ant;
            aux_ant = aux_ant->seg;
            aux_ant->info = node_act->info;
            aux_ant->seg = aux; 
            aux->ant = aux_ant;
          }
          aux_ant = new node_llista;
          aux_ant->info = node_act->info;
          aux_ant->seg = aux; 
          aux->ant = aux_ant;
        }
        else {
          l_node->info = node_act->info;
          l_node->ant = l_node_ant;
          l_node->seg = new node_llista;
          l_node_ant = l_node;
          l_node = l_node->seg;
        }
      }
      else if (node_act->info > x) {
        if (l.act == NULL) {
          l_node->ant = l_node_ant;
          l_node->info = x;
          l_node->seg = new node_llista;
          node_llista* aux = l_node->seg;
          l.act = aux;
          aux->ant = l_node->seg;
          aux->info = node_act->info;
          aux->seg = new node_llista;
          l_node_ant = aux;
          l_node = aux->seg;
        }
        else {
          l_node->ant = l_node_ant;
          l_node->info = node_act->info;
          l_node->seg = new node_llista;
          l_node_ant = l_node;
          l_node = l_node->seg;
        }
      }
      node_act = node_act->seg;
    }
    return l;
  }