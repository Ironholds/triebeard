#include <Rcpp.h>
#include "r_trie.h"
using namespace Rcpp;

template <typename Q, typename X, typename Y>
List greedy_generic(SEXP radix, CharacterVector to_match, Y non_match_val){
  r_trie <Q>* rt_ptr = (r_trie <Q> *) R_ExternalPtrAddr(radix);
  ptr_check(rt_ptr);

  unsigned int input_size = to_match.size();
  List output(input_size);

  for(unsigned int i = 0; i < input_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    X holding;
    std::vector<typename radix_tree<std::string, Q>::iterator> vec;
    typename std::vector<typename radix_tree<std::string, Q>::iterator>::iterator it;

    if(to_match[i] == NA_STRING){
      holding.push_back(non_match_val);
    } else {
      rt_ptr->radix.greedy_match(Rcpp::as<std::string>(to_match[i]), vec);
      for (it = vec.begin(); it != vec.end(); ++it) {
        holding.push_back((*it)->second);
      }
      if(holding.size() == 0){
        holding.push_back(non_match_val);
      }
    }
    output[i] = holding;
  }
  return output;
}

//[[Rcpp::export]]
List greedy_string(SEXP radix, CharacterVector to_match){
  return greedy_generic<std::string, CharacterVector, String>(radix, to_match, NA_STRING);

}

//[[Rcpp::export]]
List greedy_integer(SEXP radix, CharacterVector to_match){
  return greedy_generic<int, IntegerVector, int>(radix, to_match, NA_INTEGER);
}

//[[Rcpp::export]]
List greedy_numeric(SEXP radix, CharacterVector to_match){
  return greedy_generic<double, NumericVector, double>(radix, to_match, NA_REAL);
}

//[[Rcpp::export]]
List greedy_logical(SEXP radix, CharacterVector to_match){
  return greedy_generic<bool, LogicalVector, int>(radix, to_match, NA_INTEGER);
}
