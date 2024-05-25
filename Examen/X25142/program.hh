  void i_max_suma_cami(node_arbreGen* node, T suma_act, T& suma_max, bool& puesta) {
    if (node == NULL) {
      if (not puesta or suma_act > suma_max) {
        suma_max = suma_act;
        puesta = true; 
      }
      return; 
    }
    suma_act += node->info;
    int size = node->seg.size(); 
    for (int i = 0; i < size; ++i) {
      i_max_suma_cami(node->seg[i], suma_act, suma_max, puesta);
    }
  }


   T max_suma_cami()
 /* Pre: el parametre implicit no es buit */
 /* Post: el resultat es la suma del cami de suma maxima del parametre implicit */
 {
    T suma_max;
    T suma_act = 0; 
    bool puesta = false; 
    i_max_suma_cami(primer_node, suma_act, suma_max, puesta);
    return suma_max;
 }