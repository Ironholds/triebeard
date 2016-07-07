#include "r_trie.h"

#ifndef __RTRIE_TYPES__
#define __RTRIE_TYPES__

template <typename T>
void finaliseRadix(r_trie <T>* radix_inst){
  delete radix_inst;
}

typedef Rcpp::XPtr<r_trie <std::string>, Rcpp::PreserveStorage, finaliseRadix> XPtrRadixStr;
typedef Rcpp::XPtr<r_trie <int>, Rcpp::PreserveStorage, finaliseRadix> XPtrRadixInt;
typedef Rcpp::XPtr<r_trie <bool>, Rcpp::PreserveStorage, finaliseRadix> XPtrRadixBool;
typedef Rcpp::XPtr<r_trie <double>, Rcpp::PreserveStorage, finaliseRadix> XPtrRadixDouble;

#endif
