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

template <typename Q, typename X, typename Y>
List greedy_generic_df(SEXP radix, CharacterVector to_match, Y non_match_val){
  r_trie <Q>* rt_ptr = (r_trie <Q> *) R_ExternalPtrAddr(radix);
  ptr_check(rt_ptr);

  unsigned int input_size = to_match.size();
  List output(input_size);

  for(unsigned int i = 0; i < input_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    X holding;
    CharacterVector holding_keys;

    std::vector<typename radix_tree<std::string, Q>::iterator> vec;
    typename std::vector<typename radix_tree<std::string, Q>::iterator>::iterator it;

    if(to_match[i] == NA_STRING){
      holding.push_back(non_match_val);
      holding_keys.push_back(NA_STRING);

    } else {
      rt_ptr->radix.greedy_match(Rcpp::as<std::string>(to_match[i]), vec);
      for (it = vec.begin(); it != vec.end(); ++it) {
        holding.push_back((*it)->second);
        holding_keys.push_back((*it)->first);
      }
      if(holding.size() == 0){
        holding.push_back(non_match_val);
        holding_keys.push_back(NA_STRING);

      }
    }
    output[i] = Rcpp::DataFrame::create(_["match_key"] = holding_keys,
                                        _["match_value"] = holding,
                                        _["stringsAsFactors"] = false);
  }
  return output;
}

//[[Rcpp::export]]
List greedy_string(SEXP radix, CharacterVector to_match, bool include_keys){
  if(include_keys){
    return greedy_generic_df<std::string, CharacterVector, String>(radix, to_match, NA_STRING);
  }
  return greedy_generic<std::string, CharacterVector, String>(radix, to_match, NA_STRING);

}

//[[Rcpp::export]]
List greedy_integer(SEXP radix, CharacterVector to_match, bool include_keys){
  if(include_keys){
    return greedy_generic_df<int, IntegerVector, int>(radix, to_match, NA_INTEGER);
  }
  return greedy_generic<int, IntegerVector, int>(radix, to_match, NA_INTEGER);
}

//[[Rcpp::export]]
List greedy_numeric(SEXP radix, CharacterVector to_match, bool include_keys){
  if(include_keys){
    return greedy_generic_df<double, NumericVector, double>(radix, to_match, NA_REAL);
  }
  return greedy_generic<double, NumericVector, double>(radix, to_match, NA_REAL);
}

//[[Rcpp::export]]
List greedy_logical(SEXP radix, CharacterVector to_match, bool include_keys){
  if(include_keys){
    return greedy_generic_df<bool, LogicalVector, int>(radix, to_match, NA_INTEGER);
  }
  return greedy_generic<bool, LogicalVector, int>(radix, to_match, NA_INTEGER);
}
