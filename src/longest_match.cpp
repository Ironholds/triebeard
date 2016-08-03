#include <Rcpp.h>
#include "r_trie.h"
using namespace Rcpp;

template <typename X, typename Y, typename Z>
X longest_generic(SEXP radix, CharacterVector to_match, Z missing_val){
  r_trie <Y>* rt_ptr = (r_trie <Y> *) R_ExternalPtrAddr(radix);
  ptr_check(rt_ptr);
  typename radix_tree<std::string, Y>::iterator it;

  unsigned int input_size = to_match.size();
  X output(input_size);

  for(unsigned int i = 0; i < input_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    if(to_match[i] == NA_STRING){
      output[i] = missing_val;
    } else {
      it = rt_ptr->radix.longest_match(Rcpp::as<std::string>(to_match[i]));
      if(it != rt_ptr->radix.end()){
        output[i] = it->second;
      } else {
        output[i] = missing_val;
      }
    }
  }
  return output;
}

//[[Rcpp::export]]
CharacterVector longest_string(SEXP radix, CharacterVector to_match){
  return longest_generic<CharacterVector, std::string, String>(radix, to_match, NA_STRING);
}

//[[Rcpp::export]]
IntegerVector longest_integer(SEXP radix, CharacterVector to_match){
  return longest_generic<IntegerVector, int, int>(radix, to_match, NA_INTEGER);
}

//[[Rcpp::export]]
NumericVector longest_numeric(SEXP radix, CharacterVector to_match){
  return longest_generic<NumericVector, double, double>(radix, to_match, NA_REAL);
}

//[[Rcpp::export]]
LogicalVector longest_logical(SEXP radix, CharacterVector to_match){
  return longest_generic<LogicalVector, bool, int>(radix, to_match, NA_INTEGER);
}
