#include <Rcpp.h>
#include "r_trie.h"
using namespace Rcpp;

//[[Rcpp::export]]
List greedy_string(SEXP radix, CharacterVector to_match){
  r_trie <std::string>* rt_ptr = (r_trie <std::string> *) R_ExternalPtrAddr(radix);
  List output;

  unsigned int input_size = to_match.size();

  for(unsigned int i = 0; i < input_size; i++){

    CharacterVector holding;
    std::vector<radix_tree<std::string, std::string>::iterator> vec;
    std::vector<radix_tree<std::string, std::string>::iterator>::iterator it;

    if(to_match[i] == NA_STRING){
      holding.push_back(NA_STRING);
      output.push_back(holding);
    } else {
      rt_ptr->radix.greedy_match(Rcpp::as<std::string>(to_match[i]), vec);
      for (it = vec.begin(); it != vec.end(); ++it) {
        holding.push_back((*it)->second);
      }
      if(holding.size() == 0){
        holding.push_back(NA_STRING);
      }
      output.push_back(holding);
    }
  }
  return output;
}

//[[Rcpp::export]]
List greedy_integer(SEXP radix, CharacterVector to_match){
  r_trie <int>* rt_ptr = (r_trie <int> *) R_ExternalPtrAddr(radix);
  List output;

  unsigned int input_size = to_match.size();

  for(unsigned int i = 0; i < input_size; i++){

    IntegerVector holding;
    std::vector<radix_tree<std::string, int>::iterator> vec;
    std::vector<radix_tree<std::string, int>::iterator>::iterator it;

    if(to_match[i] == NA_STRING){
      holding.push_back(NA_INTEGER);
      output.push_back(holding);
    } else {
      rt_ptr->radix.greedy_match(Rcpp::as<std::string>(to_match[i]), vec);
      for (it = vec.begin(); it != vec.end(); ++it) {
        holding.push_back((*it)->second);
      }
      if(holding.size() == 0){
        holding.push_back(NA_INTEGER);
      }
      output.push_back(holding);
    }
  }
  return output;
}

//[[Rcpp::export]]
List greedy_numeric(SEXP radix, CharacterVector to_match){
  r_trie <double>* rt_ptr = (r_trie <double> *) R_ExternalPtrAddr(radix);
  List output;

  unsigned int input_size = to_match.size();

  for(unsigned int i = 0; i < input_size; i++){

    NumericVector holding;
    std::vector<radix_tree<std::string, double>::iterator> vec;
    std::vector<radix_tree<std::string, double>::iterator>::iterator it;

    if(to_match[i] == NA_STRING){
      holding.push_back(NA_REAL);
      output.push_back(holding);
    } else {
      rt_ptr->radix.greedy_match(Rcpp::as<std::string>(to_match[i]), vec);
      for (it = vec.begin(); it != vec.end(); ++it) {
        holding.push_back((*it)->second);
      }
      if(holding.size() == 0){
        holding.push_back(NA_REAL);
      }
      output.push_back(holding);
    }
  }
  return output;
}

//[[Rcpp::export]]
List greedy_logical(SEXP radix, CharacterVector to_match){
  r_trie <bool>* rt_ptr = (r_trie <bool> *) R_ExternalPtrAddr(radix);
  List output;

  unsigned int input_size = to_match.size();

  for(unsigned int i = 0; i < input_size; i++){

    LogicalVector holding;
    std::vector<radix_tree<std::string, bool>::iterator> vec;
    std::vector<radix_tree<std::string, bool>::iterator>::iterator it;

    if(to_match[i] == NA_STRING){
      holding.push_back(NA_LOGICAL);
      output.push_back(holding);
    } else {
      rt_ptr->radix.greedy_match(Rcpp::as<std::string>(to_match[i]), vec);
      for (it = vec.begin(); it != vec.end(); ++it) {
        holding.push_back((*it)->second);
      }
      if(holding.size() == 0){
        holding.push_back(NA_LOGICAL);
      }
      output.push_back(holding);
    }
  }
  return output;
}