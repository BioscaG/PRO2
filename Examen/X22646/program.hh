void i_trenar(node_cua* c1, node_cua* c2, bool& ultim) {
  if (c2 == NULL) return; 
  if (c1 == NULL) {
    c1 = c2;
    ultim = true; 
    return; 
  }
  node_cua* aux_c1 = c1->seguent;
  node_cua* aux_c2 = c2->seguent;
  c1->seguent = c2;
  if (c1->seguent != NULL) c1->seguent->seguent = aux_c1;
  i_trenar(c1->seguent->seguent, aux_c2, ultim);
}


   void trenat(Cua &c)
 /* Pre: p.i. = C1, c = C2 */
 /* Post: el p.i. passa a ser el resultat de trenar C1 i C2; c passa a ser buida */
 {
  longitud += c.longitud;
  c.longitud = 0; 
  bool ultim = false; 
  i_trenar(primer_node, c.primer_node, ultim);
  if (ultim == true) ultim_node = c.ultim_node;
  c.primer_node = NULL; 
  c.ultim_node = NULL; 
 }