#include "r_trie.h"

template <typename T>
static inline int radix_len(SEXP radix){
  r_trie <T>* rt_ptr = (r_trie <T> *) R_ExternalPtrAddr(radix);
  ptr_check(rt_ptr);

  return rt_ptr->radix_size;
}

//[[Rcpp::export]]
int radix_len_string(SEXP radix){
  return radix_len<std::string>(radix);
}

//[[Rcpp::export]]
int radix_len_integer(SEXP radix){
  return radix_len<int>(radix);
}

//[[Rcpp::export]]
int radix_len_numeric(SEXP radix){
  return radix_len<double>(radix);
}


//[[Rcpp::export]]
int radix_len_logical(SEXP radix){
  return radix_len<bool>(radix);
}
