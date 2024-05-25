  
  

  void suma(node_arbre* left, node_arbre* right, int& total) {
    if (left != NULL) {
      total += left->info;
      suma(left->segE, left->segD, total);
    }
    if (right != NULL) {
      total += right->info;
      suma(right->segE, right->segD, total);
    }
  }
  

  void aux_arb_sumes(node_arbre* asum, node_arbre* aux) {
    int total = aux->info;
    suma(aux->segE, aux->segD, total);
    asum->info = total;
    if (aux->segE != NULL) {
      asum->segE = new node_arbre;
      aux_arb_sumes(asum->segE, aux->segE);
    }
    if (aux->segD != NULL) {
      asum->segD = new node_arbre;
      aux_arb_sumes(asum->segD, aux->segD);
    }
  }



  void arb_sumes(Arbre<int>& asum)
    /* Pre: cert */
    /* Post: l'arbre asum Ã©s l'arbre suma del p.i. */
  {
    if (primer_node == NULL) asum.primer_node = NULL;
    else {
        asum.primer_node = new node_arbre;
        aux_arb_sumes(asum.primer_node, primer_node);
    }

  } 
