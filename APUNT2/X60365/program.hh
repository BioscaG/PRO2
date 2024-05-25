  bool i_buscar(node_arbreGen* node, const T& x) {
    if (node == NULL) return false; 
    if (node->info == x) return true; 
    int size = node->seg.size(); 
    for (int i = 0; i < size; ++i) if (i_buscar(node->seg[i], x) == true) return true;
    return false; 
  }

  bool buscar(const T& x)
    /* Pre: cert */
    /* Post: el resultat indica si x es troba al p.i. o no */
  {
    return i_buscar(primer_node, x); 
  }
