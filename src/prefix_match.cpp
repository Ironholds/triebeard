#include <Rcpp.h>
#include "r_trie.h"
using namespace Rcpp;

//[[Rcpp::export]]
List prefix_string(SEXP radix, CharacterVector to_match){
  r_trie <std::string>* rt_ptr = (r_trie <std::string> *) R_ExternalPtrAddr(radix);
  ptr_check(rt_ptr);

  unsigned int input_size = to_match.size();
  List output(input_size);

  for(unsigned int i = 0; i < input_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    CharacterVector holding;
    std::vector<radix_tree<std::string, std::string>::iterator> vec;
    std::vector<radix_tree<std::string, std::string>::iterator>::iterator it;

    if(to_match[i] == NA_STRING){
      holding.push_back(NA_STRING);
    } else {
      rt_ptr->radix.prefix_match(Rcpp::as<std::string>(to_match[i]), vec);
      for (it = vec.begin(); it != vec.end(); ++it) {
        holding.push_back((*it)->second);
      }
      if(holding.size() == 0){
        holding.push_back(NA_STRING);
      }
    }
    output[i] = holding;
  }
  return output;
}

//[[Rcpp::export]]
List prefix_integer(SEXP radix, CharacterVector to_match){
  r_trie <int>* rt_ptr = (r_trie <int> *) R_ExternalPtrAddr(radix);
  if (rt_ptr == NULL){
    stop("invalid trie object; pointer is NULL");
  }

  unsigned int input_size = to_match.size();
  List output(input_size);

  for(unsigned int i = 0; i < input_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    IntegerVector holding;
    std::vector<radix_tree<std::string, int>::iterator> vec;
    std::vector<radix_tree<std::string, int>::iterator>::iterator it;

    if(to_match[i] == NA_STRING){
      holding.push_back(NA_INTEGER);
    } else {
      rt_ptr->radix.prefix_match(Rcpp::as<std::string>(to_match[i]), vec);
      for (it = vec.begin(); it != vec.end(); ++it) {
        holding.push_back((*it)->second);
      }
      if(holding.size() == 0){
        holding.push_back(NA_INTEGER);
      }
    }
    output[i] = holding;
  }
  return output;
}

//[[Rcpp::export]]
List prefix_numeric(SEXP radix, CharacterVector to_match){
  r_trie <double>* rt_ptr = (r_trie <double> *) R_ExternalPtrAddr(radix);
  if (rt_ptr == NULL){
    stop("invalid trie object; pointer is NULL");
  }

  unsigned int input_size = to_match.size();
  List output(input_size);

  for(unsigned int i = 0; i < input_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    NumericVector holding;
    std::vector<radix_tree<std::string, double>::iterator> vec;
    std::vector<radix_tree<std::string, double>::iterator>::iterator it;

    if(to_match[i] == NA_STRING){
      holding.push_back(NA_REAL);
    } else {
      rt_ptr->radix.prefix_match(Rcpp::as<std::string>(to_match[i]), vec);
      for (it = vec.begin(); it != vec.end(); ++it) {
        holding.push_back((*it)->second);
      }
      if(holding.size() == 0){
        holding.push_back(NA_REAL);
      }
    }
    output[i] = holding;
  }
  return output;
}

//[[Rcpp::export]]
List prefix_logical(SEXP radix, CharacterVector to_match){
  r_trie <bool>* rt_ptr = (r_trie <bool> *) R_ExternalPtrAddr(radix);
  if (rt_ptr == NULL){
    stop("invalid trie object; pointer is NULL");
  }

  unsigned int input_size = to_match.size();
  List output(input_size);

  for(unsigned int i = 0; i < input_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    LogicalVector holding;
    std::vector<radix_tree<std::string, bool>::iterator> vec;
    std::vector<radix_tree<std::string, bool>::iterator>::iterator it;

    if(to_match[i] == NA_STRING){
      holding.push_back(NA_LOGICAL);
    } else {
      rt_ptr->radix.prefix_match(Rcpp::as<std::string>(to_match[i]), vec);
      for (it = vec.begin(); it != vec.end(); ++it) {
        holding.push_back((*it)->second);
      }
      if(holding.size() == 0){
        holding.push_back(NA_LOGICAL);
      }
    }
    output[i] = holding;
  }
  return output;
}
