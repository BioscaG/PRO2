   void esborrar_tots(const T& x)
 /* Pre: parametre implicit = P */
 /* Post: s'han eliminat del parametre implicit totes les aparicions d'x (la
    resta d'elements queda en el mateix ordre que a P); si el punt d'interes de P
    referenciava a una aparicio d'x, passa a referenciar al primer element
    diferent d'x posterior a aquesta (si no hi ha cap element diferent d'x, passa
    a la dreta el tot); en cas contrari, el punt d'interes no canvia */
    {
      node_llista* aux = primer_node; 
      node_llista* anterior = NULL; 
      bool cambiar_anterior = false; 
      bool posar_act = false; 
      bool act_posat = false; 
      while (aux != NULL) {
        if (aux->info == x) {
          if (act == aux) posar_act = true;
          anterior = aux->ant;
          cambiar_anterior = true; 
        }
        else {
          if (cambiar_anterior) {
            if (posar_act) {
              act = aux;
              posar_act = false; 
              act_posat = true; 
            }
            act->ant = anterior; 
            if (anterior != NULL) {
              anterior->seg = act; 
            } 
            cambiar_anterior = false; 
          } 
        }
        aux = aux->seg; 
      }
      if (not act_posat) act = NULL; 
    }
