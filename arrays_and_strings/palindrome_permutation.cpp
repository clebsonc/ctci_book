#include <iostream>
#include <string>
#include <map>

std::map<char, int> count_letters(const std::string &s){
  std::map<char, int> letters;
  std::map<char, int>::iterator it;
  for(int i = 0; i < s.size(); i++){
    it = letters.find(s.at(i));
    if(it!=letters.end()){
      it->second++;
    } else{
      letters.insert(std::pair<char, int>(s.at(i), 1));
    }
  }
  return letters;
}


bool palindrome_permutation(const std::string s){
  std::map<char, int> letters;
  std::map<char, int>::iterator it;
  letters = count_letters(s);
  int  odd=0, even=0;
  it = letters.begin();
  while(it != letters.end()){
    if(it->second%2 == 0){
      even++;
    } else {
      odd++;
    }
    it++;
  }
  
  if(s.size()%2 != 0 && odd == 1)
    return true;
  else if(s.size()%2 == 0 && odd == 0)
    return true;
  else
    return false;
}



int main(){
  std::string s;
  std::getline(std::cin, s);
  bool pal_perm = palindrome_permutation(s);
  if(pal_perm)
    std::cout << "True" << std::endl;
  else
    std::cout << "False" << std::endl;

  return 0;
}
