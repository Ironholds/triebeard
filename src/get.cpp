#include "r_trie.h"

template <typename T>
static inline std::vector < std::string > get_keys_generic(SEXP radix){
  r_trie <T>* rt_ptr = (r_trie <T> *) R_ExternalPtrAddr(radix);
  ptr_check(rt_ptr);
  
  return rt_ptr->get_keys();
}

//[[Rcpp::export]]
std::vector < std::string > get_keys_string(SEXP radix){
  return get_keys_generic<std::string>(radix);
}

//[[Rcpp::export]]
std::vector < std::string > get_keys_integer(SEXP radix){
  return get_keys_generic<int>(radix);
}

//[[Rcpp::export]]
std::vector < std::string > get_keys_numeric(SEXP radix){
  return get_keys_generic<double>(radix);
}

//[[Rcpp::export]]
std::vector < std::string > get_keys_logical(SEXP radix){
  return get_keys_generic<bool>(radix);
}



template <typename T>
static inline std::vector < T > get_values_generic(SEXP radix){
  r_trie <T>* rt_ptr = (r_trie <T> *) R_ExternalPtrAddr(radix);
  ptr_check(rt_ptr);
  return rt_ptr->get_values();
}

//[[Rcpp::export]]
std::vector < std::string > get_values_string(SEXP radix){
  return get_values_generic<std::string>(radix);
}

//[[Rcpp::export]]
std::vector < int > get_values_integer(SEXP radix){
  return get_values_generic<int>(radix);
}

//[[Rcpp::export]]
std::vector < double > get_values_numeric(SEXP radix){
  return get_values_generic<double>(radix);
}

//[[Rcpp::export]]
std::vector < bool > get_values_logical(SEXP radix){
  return get_values_generic<bool>(radix);
}
