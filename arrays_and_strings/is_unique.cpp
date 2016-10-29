#include <iostream>
#include <algorithm>
#include <string>

bool is_unique(std::string s){
  std::sort(s.begin(), s.end());
  for(int i = 0; i<s.size()-1; i++){
    if(s.at(i) == s.at(i+1))
      return false;
  }
  return true;
}


int main(){
  std::string s;
  std::getline(std::cin, s);

  bool unique = is_unique(s);
  if(unique)
    std::cout << "is unique" << std::endl;
  else
    std::cout << "is not unique" << std::endl;

  return 0;
}
