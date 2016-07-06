#include "r_trie.h"

//[[Rcpp::export]]
std::vector < std::string > get_keys_str(SEXP radix){
  r_trie <std::string>* rt_ptr = (r_trie <std::string> *) R_ExternalPtrAddr(radix);
  return rt_ptr->get_keys();
}

//[[Rcpp::export]]
std::vector < std::string > get_keys_int(SEXP radix){
  r_trie <int>* rt_ptr = (r_trie <int> *) R_ExternalPtrAddr(radix);
  return rt_ptr->get_keys();
}

//[[Rcpp::export]]
std::vector < std::string > get_keys_bool(SEXP radix){
  r_trie <bool>* rt_ptr = (r_trie <bool> *) R_ExternalPtrAddr(radix);
  return rt_ptr->get_keys();
}

//[[Rcpp::export]]
std::vector < std::string > get_keys_double(SEXP radix){
  r_trie <double>* rt_ptr = (r_trie <double> *) R_ExternalPtrAddr(radix);
  return rt_ptr->get_keys();
}

//[[Rcpp::export]]
std::vector < std::string > get_values_str(SEXP radix){
  r_trie <std::string>* rt_ptr = (r_trie <std::string> *) R_ExternalPtrAddr(radix);
  return rt_ptr->get_values();
}

//[[Rcpp::export]]
std::vector < int > get_values_int(SEXP radix){
  r_trie <int>* rt_ptr = (r_trie <int> *) R_ExternalPtrAddr(radix);
  return rt_ptr->get_values();
}

//[[Rcpp::export]]
std::vector < bool > get_values_bool(SEXP radix){
  r_trie <bool>* rt_ptr = (r_trie <bool> *) R_ExternalPtrAddr(radix);
  return rt_ptr->get_values();
}

//[[Rcpp::export]]
std::vector < double > get_values_double(SEXP radix){
  r_trie <double>* rt_ptr = (r_trie <double> *) R_ExternalPtrAddr(radix);
  return rt_ptr->get_values();
}