#include "r_trie.h"

#define PRINTMAX 75

template <typename T>
static inline int numlen(T num){
  return ((int)std::log10(num))+1;
}

// TODO NA's
static inline int printsize(std::string x){
  return x.length();
}

static inline int printsize(int x){
  if (x == NA_INTEGER)
    return 2;
  else
    return numlen(x);
}

static inline int printsize(double x){
  if (ISNA(x))
    return 2;
  else
    return numlen(x);
}

static inline int printsize(bool x){
  if (x == NA_LOGICAL)
    return 2;
  else
    return 1;
}

// TODO NA's
static inline void valprinter(std::string val){
  Rcout << "\"";
  Rcout << val;
  Rcout << "\"" << " ";
}

static inline void valprinter(int val){
  if (val == NA_INTEGER)
    Rcout << "NA";
  else
    Rcout << val;
}

static inline void valprinter(double val){
  if (ISNA(val))
    Rcout << "NA";
  else
    Rcout << val;
}

static inline void valprinter(bool val){
  if (val == NA_INTEGER)
    Rcout << "NA";
  else
  {
    if (val)
      Rcout << "TRUE";
    else
      Rcout << "FALSE";
  }
}

template <typename T>
static inline void trie_str_generic(SEXP radix, std::string type_str){
  r_trie <T>* rt_ptr = (r_trie <T> *) R_ExternalPtrAddr(radix);
  ptr_check(rt_ptr);
  
  int input_size = rt_ptr->size();
  int iter;
  int printed = 0;
  
  Rcout << "  Keys:   chr [1:" << input_size << "] ";
  printed += 19 + numlen(input_size);
  
  typename radix_tree< std::string, T >::iterator it;
  
  iter = 0;
  for (it = rt_ptr->radix.begin(); it != rt_ptr->radix.end() && printed < PRINTMAX; ++it) {
    printed += it->first.length();
    if (iter > 0 && printed > PRINTMAX)
      break;
    
    Rcout << "\"" << it->first << "\"" << " ";
    
    iter++;
  }
  
  if (iter < input_size)
    Rcout << "...";
  Rcout << std::endl;
  printed = 0;
  Rcout << "  Values: " << type_str << " [1:" << input_size << "] ";
  printed += 15 + type_str.length() + numlen(input_size);
  
  iter = 0;
  for (it = rt_ptr->radix.begin(); it != rt_ptr->radix.end() && iter < 5; ++it) {
    printed += printsize(it->second);
    if (iter > 0 && printed > PRINTMAX)
      break;
    
    valprinter(it->second);
    Rcout << " ";
    
    iter++;
  }
  
  if (iter < input_size)
    Rcout << "...";
  Rcout << std::endl;
}



//[[Rcpp::export]]
void trie_str_string(SEXP radix){
  trie_str_generic<std::string>(radix, "str");
}

//[[Rcpp::export]]
void trie_str_integer(SEXP radix){
  trie_str_generic<int>(radix, "int");
}

//[[Rcpp::export]]
void trie_str_numeric(SEXP radix){
  trie_str_generic<double>(radix, "num");
}

//[[Rcpp::export]]
void trie_str_logical(SEXP radix){
  trie_str_generic<bool>(radix, "logi");
}
