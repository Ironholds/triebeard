#include "r_trie.h"

//[[Rcpp::export]]
void add_trie_string(SEXP trie, CharacterVector keys, CharacterVector values){
  r_trie <std::string>* rt_ptr = (r_trie <std::string> *) R_ExternalPtrAddr(trie);
  ptr_check(rt_ptr);
  unsigned int in_size = keys.size();
  for(unsigned int i = 0; i < in_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    if(keys[i] != NA_STRING && values[i] != NA_STRING){
      rt_ptr->insert_value(Rcpp::as<std::string>(keys[i]), Rcpp::as<std::string>(values[i]));
    }
  }
  rt_ptr->radix_size = rt_ptr->size();
}

//[[Rcpp::export]]
void add_trie_integer(SEXP trie, CharacterVector keys, IntegerVector values){
  r_trie <int>* rt_ptr = (r_trie <int> *) R_ExternalPtrAddr(trie);
  ptr_check(rt_ptr);
  unsigned int in_size = keys.size();
  for(unsigned int i = 0; i < in_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    if(keys[i] != NA_STRING && values[i] != NA_INTEGER){
      rt_ptr->insert_value(Rcpp::as<std::string>(keys[i]), values[i]);
    }
  }
  rt_ptr->radix_size = rt_ptr->size();
}

//[[Rcpp::export]]
void add_trie_numeric(SEXP trie, CharacterVector keys, NumericVector values){
  r_trie <double>* rt_ptr = (r_trie <double> *) R_ExternalPtrAddr(trie);
  ptr_check(rt_ptr);
  unsigned int in_size = keys.size();
  for(unsigned int i = 0; i < in_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    if(keys[i] != NA_STRING && values[i] != NA_REAL){
      rt_ptr->insert_value(Rcpp::as<std::string>(keys[i]), values[i]);
    }
  }
  rt_ptr->radix_size = rt_ptr->size();
}

//[[Rcpp::export]]
void add_trie_logical(SEXP trie, CharacterVector keys, LogicalVector values){
  r_trie <bool>* rt_ptr = (r_trie <bool> *) R_ExternalPtrAddr(trie);
  ptr_check(rt_ptr);
  unsigned int in_size = keys.size();
  for(unsigned int i = 0; i < in_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    if(keys[i] != NA_STRING && values[i] != NA_LOGICAL){
      rt_ptr->insert_value(Rcpp::as<std::string>(keys[i]), values[i]);
    }
  }
  rt_ptr->radix_size = rt_ptr->size();
}

//[[Rcpp::export]]
void remove_trie_string(SEXP trie, CharacterVector keys){
  r_trie <std::string>* rt_ptr = (r_trie <std::string> *) R_ExternalPtrAddr(trie);
  ptr_check(rt_ptr);
  rt_ptr->remove_values(keys);
}

//[[Rcpp::export]]
void remove_trie_integer(SEXP trie, CharacterVector keys){
  r_trie <int>* rt_ptr = (r_trie <int> *) R_ExternalPtrAddr(trie);
  ptr_check(rt_ptr);
  rt_ptr->remove_values(keys);
}

//[[Rcpp::export]]
void remove_trie_numeric(SEXP trie, CharacterVector keys){
  r_trie <double>* rt_ptr = (r_trie <double> *) R_ExternalPtrAddr(trie);
  ptr_check(rt_ptr);
  rt_ptr->remove_values(keys);
}

//[[Rcpp::export]]
void remove_trie_logical(SEXP trie, CharacterVector keys){
  r_trie <bool>* rt_ptr = (r_trie <bool> *) R_ExternalPtrAddr(trie);
  ptr_check(rt_ptr);
  rt_ptr->remove_values(keys);
}
