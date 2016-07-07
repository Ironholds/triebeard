#include <Rcpp.h>
#include "typedef.h"
using namespace Rcpp;

//[[Rcpp::export]]
SEXP radix_create_string(std::vector < std::string > keys, std::vector < std::string > values){
  r_trie <std::string>* radix = new r_trie <std::string>(keys, values);
  return XPtrRadixStr(radix);
}

//[[Rcpp::export]]
SEXP radix_create_integer(std::vector < std::string > keys, std::vector < int > values){
  r_trie <int>* radix = new r_trie <int>(keys, values);
  return XPtrRadixInt(radix);
}

//[[Rcpp::export]]
SEXP radix_create_numeric(std::vector < std::string > keys, std::vector < double > values){
  r_trie <double>* radix = new r_trie <double>(keys, values);
  XPtrRadixDouble ptr(radix);
  return ptr;
}

//[[Rcpp::export]]
SEXP radix_create_logical(std::vector < std::string > keys, std::vector < bool > values){
  r_trie <bool>* radix = new r_trie <bool>(keys, values);
  return XPtrRadixBool(radix);
}