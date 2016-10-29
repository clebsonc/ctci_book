#include <iostream>
#include <string>
#include <map>

bool is_permutation(std::string s1, std::string s2){
  std::map<char, int> chars_in_s1;
  std::map<char,int>::iterator it;
  for(int i = 0; i < s1.size(); i++){
    it = chars_in_s1.find(s1.at(i));
    if(it != chars_in_s1.end()){ // element was found
      it->second++;
    }
    else{
      chars_in_s1.insert(std::pair<char, int>(s1.at(i), 1));
    }
  }

  for(int i = 0; i < s2.size(); i++){
    it = chars_in_s1.find(s2.at(i));
    if(it == chars_in_s1.end()){
      return false;
    } else{
      it->second--;
      if(it->second == 0)
        chars_in_s1.erase(it);
    }
  }
  
  if(chars_in_s1.empty())
    return true;
  else
    return false;
}


int main(){
  std::string s1, s2;
  std::getline(std::cin, s1);
  std::getline(std::cin, s2);
  bool is_perm = is_permutation(s1, s2);
  if(is_perm)
    std::cout << "s1 and s2 are permutation of each other" << std::endl;
  else
    std::cout << "s1 and s2 aren't permutation" << std::endl;
  return 0;
}


