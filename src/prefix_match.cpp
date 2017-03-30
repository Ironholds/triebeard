#include <Rcpp.h>
#include "r_trie.h"
using namespace Rcpp;

template <typename X, typename Y, typename Z>
List prefix_generic(SEXP radix, CharacterVector to_match, Z missing_val){
  r_trie <Y>* rt_ptr = (r_trie <Y> *) R_ExternalPtrAddr(radix);
  ptr_check(rt_ptr);
  typename radix_tree<std::string, Y>::iterator it;

  unsigned int input_size = to_match.size();
  List output(input_size);

  for(unsigned int i = 0; i < input_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    X holding;
    std::vector<typename radix_tree<std::string, Y>::iterator> vec;
    typename std::vector<typename radix_tree<std::string, Y>::iterator>::iterator it;

    if(to_match[i] == NA_STRING){
      holding.push_back(missing_val);
    } else {
      rt_ptr->radix.prefix_match(Rcpp::as<std::string>(to_match[i]), vec);
      for (it = vec.begin(); it != vec.end(); ++it) {
        holding.push_back((*it)->second);
      }
      if(holding.size() == 0){
        holding.push_back(missing_val);
      }
    }
    output[i] = holding;
  }
  return output;
}

template <typename X, typename Y, typename Z>
List prefix_generic_df(SEXP radix, CharacterVector to_match, Z missing_val){
  r_trie <Y>* rt_ptr = (r_trie <Y> *) R_ExternalPtrAddr(radix);
  ptr_check(rt_ptr);
  typename radix_tree<std::string, Y>::iterator it;

  unsigned int input_size = to_match.size();
  List output(input_size);

  for(unsigned int i = 0; i < input_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    X holding_vals;
    CharacterVector holding_keys;

    std::vector<typename radix_tree<std::string, Y>::iterator> vec;
    typename std::vector<typename radix_tree<std::string, Y>::iterator>::iterator it;

    if(to_match[i] == NA_STRING){
      holding_vals.push_back(missing_val);
      holding_keys.push_back(NA_STRING);
    } else {
      rt_ptr->radix.prefix_match(Rcpp::as<std::string>(to_match[i]), vec);
      for (it = vec.begin(); it != vec.end(); ++it) {
        holding_vals.push_back((*it)->second);
        holding_keys.push_back((*it)->first);
      }
      if(holding_vals.size() == 0){
        holding_vals.push_back(missing_val);
        holding_keys.push_back(NA_STRING);
      }
    }
    output[i] = Rcpp::DataFrame::create(_["match_key"] = holding_keys,
                                        _["match_value"] = holding_vals,
                                        _["stringsAsFactors"] = false);
  }
  return output;
}

//[[Rcpp::export]]
List prefix_string(SEXP radix, CharacterVector to_match, bool include_keys){
  if(include_keys){
    return prefix_generic_df<CharacterVector, std::string, String>(radix, to_match, NA_STRING);
  }
  return prefix_generic<CharacterVector, std::string, String>(radix, to_match, NA_STRING);
}

//[[Rcpp::export]]
List prefix_integer(SEXP radix, CharacterVector to_match, bool include_keys){
  if(include_keys){
    return prefix_generic_df<IntegerVector, int, int>(radix, to_match, NA_INTEGER);
  }
  return prefix_generic<IntegerVector, int, int>(radix, to_match, NA_INTEGER);
}

//[[Rcpp::export]]
List prefix_numeric(SEXP radix, CharacterVector to_match, bool include_keys){
  if(include_keys){
    return prefix_generic_df<NumericVector, double, double>(radix, to_match, NA_REAL);
  }
  return prefix_generic<NumericVector, double, double>(radix, to_match, NA_REAL);
}

//[[Rcpp::export]]
List prefix_logical(SEXP radix, CharacterVector to_match, bool include_keys){
  if(include_keys){
    return prefix_generic_df<LogicalVector, bool, int>(radix, to_match, NA_INTEGER);
  }
  return prefix_generic<LogicalVector, bool, int>(radix, to_match, NA_INTEGER);
}