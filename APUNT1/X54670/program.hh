void concat(Cua &c) {
    /* Pre: c=C */
    /* Post: el p.i. passa a ser la concatenació de C al paràmetre implícit, c és buida */
      if (c.longitud > 0) {
        if (longitud == 0) {
          primer_node = copia_node_cua(c.primer_node, ultim_node);
          longitud = c.longitud;
        }
        else if (longitud > 0) {
          node_cua* aux;
          ultim_node->seguent = copia_node_cua(c.primer_node, aux);
          ultim_node = aux;
          longitud += c.longitud;
        }
      }
      esborra_node_cua(c.primer_node);
      c.longitud = 0;
      c.primer_node = c.ultim_node = NULL;
}