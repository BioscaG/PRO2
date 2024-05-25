  void i_freq(node_arbreGen* node, const T& x, int& total) {
    if (node == NULL) return;
    if (node->info == x) ++total; 
    int size = node->seg.size(); 
    for (int i = 0; i < size; ++i) i_freq(node->seg[i], x, total);
  }


  int freq(const T& x)
    /* Pre: cert */
    /* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
  {
    int total = 0; 
    i_freq(primer_node, x, total);
    return total; 
  }