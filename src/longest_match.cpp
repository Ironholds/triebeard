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

template <typename X, typename Y, typename Z>
DataFrame longest_generic_df(SEXP radix, CharacterVector to_match, Z missing_val){
  r_trie <Y>* rt_ptr = (r_trie <Y> *) R_ExternalPtrAddr(radix);
  ptr_check(rt_ptr);
  typename radix_tree<std::string, Y>::iterator it;

  unsigned int input_size = to_match.size();
  X output(input_size);
  CharacterVector output_keys(input_size);

  for(unsigned int i = 0; i < input_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    if(to_match[i] == NA_STRING){
      output[i] = missing_val;
      output_keys[i] = NA_STRING;
    } else {
      it = rt_ptr->radix.longest_match(Rcpp::as<std::string>(to_match[i]));
      if(it != rt_ptr->radix.end()){
        output[i] = it->second;
        output_keys[i] = it->first;
      } else {
        output[i] = missing_val;
        output_keys[i] = NA_STRING;
      }
    }
  }
  return Rcpp::DataFrame::create(_["match_key"] = output_keys,
                                 _["match_value"] = output,
                                 _["stringsAsFactors"] = false);
}

//[[Rcpp::export]]
SEXP longest_string(SEXP radix, CharacterVector to_match, bool include_keys){
  if(include_keys){
    return Rcpp::wrap(longest_generic_df<CharacterVector, std::string, String>(radix, to_match, NA_STRING));
  }
  return Rcpp::wrap(longest_generic<CharacterVector, std::string, String>(radix, to_match, NA_STRING));
}

//[[Rcpp::export]]
SEXP longest_integer(SEXP radix, CharacterVector to_match, bool include_keys){
  if(include_keys){
    return Rcpp::wrap(longest_generic_df<IntegerVector, int, int>(radix, to_match, NA_INTEGER));
  }
  return Rcpp::wrap(longest_generic<IntegerVector, int, int>(radix, to_match, NA_INTEGER));
}

//[[Rcpp::export]]
SEXP longest_numeric(SEXP radix, CharacterVector to_match, bool include_keys){
  if(include_keys){
    return Rcpp::wrap(longest_generic_df<NumericVector, double, double>(radix, to_match, NA_REAL));
  }
  return Rcpp::wrap(longest_generic<NumericVector, double, double>(radix, to_match, NA_REAL));
}

//[[Rcpp::export]]
SEXP longest_logical(SEXP radix, CharacterVector to_match, bool include_keys){
  if(include_keys){
    return Rcpp::wrap(longest_generic_df<LogicalVector, bool, int>(radix, to_match, NA_INTEGER));
  }
  return Rcpp::wrap(longest_generic<LogicalVector, bool, int>(radix, to_match, NA_INTEGER));
}
