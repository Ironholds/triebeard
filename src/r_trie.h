#include <Rcpp.h>
#include <radix.h>
using namespace Rcpp;

#ifndef __RTRIE_CORE__
#define __RTRIE_CORE__

static inline void ptr_check(void *ptr){
  if (ptr == NULL){
    stop("invalid trie object; pointer is NULL");
  }
}

template <class T>
class r_trie {

  public:

    int size(){
      return radix.size();
    }

    radix_tree<std::string, T> radix;

    int radix_size;

    r_trie(std::vector < std::string > keys, std::vector < T > values){
      unsigned int in_size = keys.size();
      for(unsigned int i = 0; i < in_size; i++){
        if((i % 10000) == 0){
          Rcpp::checkUserInterrupt();
        }
        radix[keys[i]] = values[i];
      }
      radix_size = size();
    }

    std::vector < std::string > get_keys(){
      int input_size = size();
      int iter = 0;
      std::vector < std::string > output(input_size);

      typename radix_tree< std::string, T >::iterator it;
      for (it = radix.begin(); it != radix.end(); ++it) {
        output[iter] = it->first;
        iter++;
      }
      return output;
    }

    std::vector < T > get_values(){
      int input_size = size();
      int iter = 0;
      std::vector < T > output(input_size);

      typename radix_tree< std::string, T >::iterator it;
      for (it = radix.begin(); it != radix.end(); ++it) {
        output[iter] = it->second;
        iter++;
      }
      return output;
    }

    void insert_value(std::string key, T value){
      radix[key] = value;
    }

    void remove_values(CharacterVector keys){
      unsigned int in_size = keys.size();
      for(unsigned int i = 0; i < in_size; i++){
        if((i % 10000) == 0){
          Rcpp::checkUserInterrupt();
        }
        if(keys[i] != NA_STRING){
          radix.erase(Rcpp::as<std::string>(keys[i]));
        }
      }
      
      radix_size = size();
    }
};

#endif
