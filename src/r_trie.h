#include <Rcpp.h>
#include <radix.h>
using namespace Rcpp;

#ifndef __RTRIE_CORE__
#define __RTRIE_CORE__
template <class T>
class r_trie {

  private:
    radix_tree<std::string, T> radix;

    int size(){
      return std::distance(radix.begin(), radix.end());
    }

  public:

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

    std::vector < T > get_values();

    bool insert_values(std::vector < std::string > keys, std::vector < T > values){
      try{
        for(unsigned int i = 0; i < keys.size(); i++){
          radix[keys[i]] = values[i];
        }
      } catch(...){
        return false;
        radix_size = size();

      }
      return true;
      radix_size = size();
    }

    bool remove_values(std::vector < std::string > keys){
      try{
        for(unsigned int i = 0; i < keys.size(); i++){
          radix.erase(keys[i]);
        }
      } catch(...){
        radix_size = size();
        return false;
      }
      radix_size = size();
      return true;
    }
};

#endif