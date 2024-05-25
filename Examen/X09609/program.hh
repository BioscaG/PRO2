  void i_sub_arrel(node_arbre* primer, node_arbre*& asub, const T& x, bool encontrado) {
    if (primer == NULL or encontrado) return; 
    if (primer->info == x) {
        asub = copia_node_arbre(primer);
        encontrado = true; 
        return;
    }
    i_sub_arrel(primer->segE, asub, x, encontrado);
    i_sub_arrel(primer->segD, asub, x, encontrado);
  }
   void sub_arrel(Arbre& asub, const T& x)
 /* Pre: p.i. = A, asub es buit */
 /* Post: si A conte x, asub es el subarbre d'A resultat de la cerca;
    si A no conte x, asub es buit */
  
    {
        asub.primer_node = NULL;
        bool encontrado = false; 
      i_sub_arrel(primer_node, asub.primer_node, x, encontrado);
    }