#include "r_trie.h"

#ifndef __RTRIE_TYPES__
#define __RTRIE_TYPES__

void finaliseRadixStr(r_trie <std::string>* radix_inst){}

typedef Rcpp::XPtr<r_trie <std::string>, Rcpp::PreserveStorage, finaliseRadixStr> XPtrRadixStr;

void finaliseRadixInt(r_trie <int>* radix_inst){}

typedef Rcpp::XPtr<r_trie <int>, Rcpp::PreserveStorage, finaliseRadixInt> XPtrRadixInt;

void finaliseRadixBool(r_trie <bool>* radix_inst){}

typedef Rcpp::XPtr<r_trie <bool>, Rcpp::PreserveStorage, finaliseRadixBool> XPtrRadixBool;

void finaliseRadixDouble(r_trie <double>* radix_inst){}

typedef Rcpp::XPtr<r_trie <double>, Rcpp::PreserveStorage, finaliseRadixDouble> XPtrRadixDouble;

#endif