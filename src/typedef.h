#include <radix.h>

void finaliseRadixStr(radix_tree <std::string, std::string>* radix_inst){}

typedef Rcpp::XPtr<radix_tree <std::string, std::string>, Rcpp::PreserveStorage, finaliseRadixStr> XPtrRadixStr;

void finaliseRadixInt(radix_tree <std::string, int>* radix_inst){}

typedef Rcpp::XPtr<radix_tree <std::string, int>, Rcpp::PreserveStorage, finaliseRadixInt> XPtrRadixInt;

void finaliseRadixBool(radix_tree <std::string, bool>* radix_inst){}

typedef Rcpp::XPtr<radix_tree <std::string, bool>, Rcpp::PreserveStorage, finaliseRadixBool> XPtrRadixBool;

void finaliseRadixDouble(radix_tree <std::string, double>* radix_inst){}

typedef Rcpp::XPtr<radix_tree <std::string, double>, Rcpp::PreserveStorage, finaliseRadixDouble> XPtrRadixDouble;
