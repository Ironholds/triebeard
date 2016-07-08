#include "r_trie.h"

template <typename T>
static inline Rcpp::List trie_to_list(SEXP radix){
  r_trie <T>* rt_ptr = (r_trie <T> *) R_ExternalPtrAddr(radix);
  ptr_check(rt_ptr);
  
  return Rcpp::List::create(
    Rcpp::Named("keys") = rt_ptr->get_keys(),
    Rcpp::Named("values") = rt_ptr->get_values()
  );
}



//[[Rcpp::export]]
Rcpp::List trie_to_list_string(SEXP radix){
  return trie_to_list<std::string>(radix);
}

//[[Rcpp::export]]
Rcpp::List trie_to_list_integer(SEXP radix){
  return trie_to_list<int>(radix);
}

//[[Rcpp::export]]
Rcpp::List trie_to_list_numeric(SEXP radix){
  return trie_to_list<double>(radix);
}

//[[Rcpp::export]]
Rcpp::List trie_to_list_logical(SEXP radix){
  return trie_to_list<bool>(radix);
}
