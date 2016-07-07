#include "r_trie.h"

//[[Rcpp::export]]
std::vector < std::string > get_keys_string(SEXP radix){
  r_trie <std::string>* rt_ptr = (r_trie <std::string> *) R_ExternalPtrAddr(radix);
  if (rt_ptr == NULL){
    stop("invalid trie object; pointer is NULL");
  }
  return rt_ptr->get_keys();
}

//[[Rcpp::export]]
std::vector < std::string > get_keys_integer(SEXP radix){
  r_trie <int>* rt_ptr = (r_trie <int> *) R_ExternalPtrAddr(radix);
  if (rt_ptr == NULL){
    stop("invalid trie object; pointer is NULL");
  }
  return rt_ptr->get_keys();
}

//[[Rcpp::export]]
std::vector < std::string > get_keys_numeric(SEXP radix){
  r_trie <double>* rt_ptr = (r_trie <double> *) R_ExternalPtrAddr(radix);
  if (rt_ptr == NULL){
    stop("invalid trie object; pointer is NULL");
  }
  return rt_ptr->get_keys();
}

//[[Rcpp::export]]
std::vector < std::string > get_keys_logical(SEXP radix){
  r_trie <bool>* rt_ptr = (r_trie <bool> *) R_ExternalPtrAddr(radix);
  if (rt_ptr == NULL){
    stop("invalid trie object; pointer is NULL");
  }
  return rt_ptr->get_keys();
}

//[[Rcpp::export]]
std::vector < std::string > get_values_string(SEXP radix){
  r_trie <std::string>* rt_ptr = (r_trie <std::string> *) R_ExternalPtrAddr(radix);
  if (rt_ptr == NULL){
    stop("invalid trie object; pointer is NULL");
  }
  return rt_ptr->get_values();
}

//[[Rcpp::export]]
std::vector < int > get_values_integer(SEXP radix){
  r_trie <int>* rt_ptr = (r_trie <int> *) R_ExternalPtrAddr(radix);
  if (rt_ptr == NULL){
    stop("invalid trie object; pointer is NULL");
  }
  return rt_ptr->get_values();
}

//[[Rcpp::export]]
std::vector < double > get_values_numeric(SEXP radix){
  r_trie <double>* rt_ptr = (r_trie <double> *) R_ExternalPtrAddr(radix);
  if (rt_ptr == NULL){
    stop("invalid trie object; pointer is NULL");
  }
  return rt_ptr->get_values();
}

//[[Rcpp::export]]
std::vector < bool > get_values_logical(SEXP radix){
  r_trie <bool>* rt_ptr = (r_trie <bool> *) R_ExternalPtrAddr(radix);
  if (rt_ptr == NULL){
    stop("invalid trie object; pointer is NULL");
  }
  return rt_ptr->get_values();
}