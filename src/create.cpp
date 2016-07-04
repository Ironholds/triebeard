#include <Rcpp.h>
#include "typedef.h"
using namespace Rcpp;

//[[Rcpp::export]]
SEXP radix_create_str(std::vector < std::string > key, std::vector < std::string > value){
  radix_tree<std::string, std::string> radix;
  for(unsigned int i = 0; i < key.size(); i++){
    radix[key[i]] = value[i];
  }

  XPtrRadixStr ptr(&radix);
  return ptr;
}

//[[Rcpp::export]]
SEXP radix_create_int(std::vector < std::string > key, std::vector < int > value){
  radix_tree<std::string, int> radix;

  for(unsigned int i = 0; i < key.size(); i++){
    radix[key[i]] = value[i];
  }

  XPtrRadixInt ptr(&radix);
  return ptr;
}

//[[Rcpp::export]]
SEXP radix_create_double(std::vector < std::string > key, std::vector < double > value){
  radix_tree<std::string, double> radix;

  for(unsigned int i = 0; i < key.size(); i++){
    radix[key[i]] = value[i];
  }

  XPtrRadixDouble ptr(&radix);
  return ptr;
}

//[[Rcpp::export]]
SEXP radix_create_bool(std::vector < std::string > key, std::vector < bool > value){
  radix_tree<std::string, bool> radix;

  for(unsigned int i = 0; i < key.size(); i++){
    radix[key[i]] = value[i];
  }

  XPtrRadixBool ptr(&radix);
  return ptr;
}