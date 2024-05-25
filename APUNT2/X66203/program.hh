void i_maxim(vector<node_arbreNari*> v, T& max) const {
  for (int i = 0; i < N; ++i) {
    node_arbreNari* aux = v[i];
    if (aux != NULL) {
      i_maxim(aux->seg, max);
      if (aux->info > max) max = aux->info;
    }
  }
}


T maxim() const
/* Pre: el p.i. no és buit */
/* Post: el resultat indica el valor més gran que conté el p.i. */
{
  T max = primer_node->info;
  i_maxim(primer_node->seg, max);
  return max;
}