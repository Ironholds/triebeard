#include <Rcpp.h>
#include "r_trie.h"
using namespace Rcpp;

//[[Rcpp::export]]
CharacterVector longest_string(SEXP radix, CharacterVector to_match){
  r_trie <std::string>* rt_ptr = (r_trie <std::string> *) R_ExternalPtrAddr(radix);
  ptr_check(rt_ptr);
  radix_tree<std::string, std::string>::iterator it;

  unsigned int input_size = to_match.size();
  CharacterVector output(input_size);

  for(unsigned int i = 0; i < input_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    if(to_match[i] == NA_STRING){
      output[i] = NA_STRING;
    } else {
      it = rt_ptr->radix.longest_match(Rcpp::as<std::string>(to_match[i]));
      if(it != rt_ptr->radix.end()){
        output[i] = it->second;
      } else {
        output[i] = NA_STRING;
      }
    }
  }
  return output;
}

//[[Rcpp::export]]
IntegerVector longest_integer(SEXP radix, CharacterVector to_match){
  r_trie <int>* rt_ptr = (r_trie <int> *) R_ExternalPtrAddr(radix);
  if (rt_ptr == NULL){
    stop("invalid trie object; pointer is NULL");
  }
  radix_tree<std::string, int>::iterator it;

  unsigned int input_size = to_match.size();
  IntegerVector output(input_size);

  for(unsigned int i = 0; i < input_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    if(to_match[i] == NA_STRING){
      output[i] = NA_INTEGER;
    } else {
      it = rt_ptr->radix.longest_match(Rcpp::as<std::string>(to_match[i]));
      if(it != rt_ptr->radix.end()){
        output[i] = it->second;
      } else {
        output[i] = NA_INTEGER;
      }
    }
  }
  return output;
}

//[[Rcpp::export]]
NumericVector longest_numeric(SEXP radix, CharacterVector to_match){
  r_trie <double>* rt_ptr = (r_trie <double> *) R_ExternalPtrAddr(radix);
  if (rt_ptr == NULL){
    stop("invalid trie object; pointer is NULL");
  }
  radix_tree<std::string, double>::iterator it;

  unsigned int input_size = to_match.size();
  NumericVector output(input_size);

  for(unsigned int i = 0; i < input_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    if(to_match[i] == NA_STRING){
      output[i] = NA_REAL;
    } else {
      it = rt_ptr->radix.longest_match(Rcpp::as<std::string>(to_match[i]));
      if(it != rt_ptr->radix.end()){
        output[i] = it->second;
      } else {
        output[i] = NA_REAL;
      }
    }
  }
  return output;
}

//[[Rcpp::export]]
LogicalVector longest_logical(SEXP radix, CharacterVector to_match){
  r_trie <bool>* rt_ptr = (r_trie <bool> *) R_ExternalPtrAddr(radix);
  if (rt_ptr == NULL){
    stop("invalid trie object; pointer is NULL");
  }
  radix_tree<std::string, bool>::iterator it;

  unsigned int input_size = to_match.size();
  LogicalVector output(input_size);

  for(unsigned int i = 0; i < input_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    if(to_match[i] == NA_STRING){
      output[i] = NA_LOGICAL;
    } else {
      it = rt_ptr->radix.longest_match(Rcpp::as<std::string>(to_match[i]));
      if(it != rt_ptr->radix.end()){
        output[i] = it->second;
      } else {
        output[i] = NA_LOGICAL;
      }
    }
  }
  return output;
}
