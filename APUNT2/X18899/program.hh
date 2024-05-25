int i_arbsuma(node_arbreNari* aux, node_arbreNari*& arb) {
  if (aux == NULL) {
    arb = NULL;
    return 0; 
  } 
  int suma = aux->info;   
  int ari = aux->seg.size();
  arb->seg = vector<node_arbreNari*>(ari);
  for(int i = 0; i < ari; ++i) {  
    node_arbreNari* aux_arb = new node_arbreNari;
    suma += i_arbsuma(aux->seg[i], aux_arb);
    arb->seg[i] = aux_arb;
  }
  arb->info = suma;
  return suma; 
} 



void arbsuma(ArbreNari& asum)
/* Pre: cert */
/* Post: asum és un arbre amb la mateixa estructura que el p.i.
         i cada node és la suma del node corresponent al p.i
         i tots els seus descendents al p.i. */
{
  node_arbreNari* primer = new node_arbreNari;
  i_arbsuma(primer_node, primer);
  asum.primer_node = primer;
}