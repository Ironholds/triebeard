#include "r_trie.h"

//[[Rcpp::export]]
int radix_len_str(SEXP radix){
  r_trie <std::string>* rt_ptr = (r_trie <std::string> *) R_ExternalPtrAddr(radix);
  return rt_ptr->radix_size;
}

//[[Rcpp::export]]
int radix_len_int(SEXP radix){
  r_trie <int>* rt_ptr = (r_trie <int> *) R_ExternalPtrAddr(radix);
  return rt_ptr->radix_size;
}


//[[Rcpp::export]]
int radix_len_bool(SEXP radix){
  r_trie <bool>* rt_ptr = (r_trie <bool> *) R_ExternalPtrAddr(radix);
  return rt_ptr->radix_size;
}

//[[Rcpp::export]]
int radix_len_double(SEXP radix){
  r_trie <double>* rt_ptr = (r_trie <double> *) R_ExternalPtrAddr(radix);
  return rt_ptr->radix_size;
}
