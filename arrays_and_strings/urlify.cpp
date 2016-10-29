#include <iostream>
#include <string>

#define ls 100

/**
* Return the number of spaces and characters in the string.
* pair.first  is the amount of spaces
* pair.second is the amount of characters in the string
*/
std::pair<int, int> get_amount_spaces(char * s1){
  int i = 0;
  int count = 0;
  while(*(s1+i) != '\0'){
    if(*(s1+i) == ' ')
      count++;
    i++;
  }
  return std::pair<int,int>(count, i);
}

/**
* Replaces the spaces in s1 with the characters "%20".
*/
void insert_special_characters_in_space(char * s1){
  std::pair<int, int> sp_and_ch = get_amount_spaces(s1);
  int j = sp_and_ch.second + sp_and_ch.first * 2;
  for(int i = sp_and_ch.second; i > 0; i--){
    if(s1[i] != ' '){
      s1[j] = s1[i];
      j--;
    } else {
      s1[j] = '0';
      s1[j-1] = '2';
      s1[j-2] = '%';
      j = j-3;
    }
  }
}

int main(){
  char s1[ls];
  std::cin.getline(s1, ls, '\n');
  std::pair<int, int> spaces = get_amount_spaces(s1); 
  insert_special_characters_in_space(s1);
  std::cout << s1 << std::endl;

  return 0;
}
