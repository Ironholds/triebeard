#include <Rcpp.h>
#include <radix.h>
using namespace Rcpp;

#ifndef __RTRIE_CORE__
#define __RTRIE_CORE__
template <class T>
class r_trie {

  public:

    int size(){
      return std::distance(radix.begin(), radix.end());
    }

    radix_tree<std::string, T> radix;

    int radix_size;

    r_trie(std::vector < std::string > keys, std::vector < T > values){
      for(unsigned int i = 0; i < keys.size(); i++){
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
      for(unsigned int i = 0; i < keys.size(); i++){
        if(keys[i] != NA_STRING){
          radix.erase(Rcpp::as<std::string>(keys[i]));
        }
      }
      radix_size = size();
    }
};

#endif