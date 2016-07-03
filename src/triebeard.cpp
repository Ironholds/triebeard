#include <Rcpp.h>
#include "typedef.h"
using namespace Rcpp;


XPtrRadix radix_str(std::vector < std::string > key, std::vector < std::string > value){
  radix_tree<std::string, std::string> *radix;
  return XPtrRadix(radix);
}
