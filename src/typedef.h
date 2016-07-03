#include <radix.h>

inline void finaliseRadix(radix_tree <std::string, std::string>* radix_inst) {
  // do nothing
}

typedef Rcpp::XPtr<radix_tree <std::string, std::string>,Rcpp::PreserveStorage,finaliseRadix> XPtrRadix;
