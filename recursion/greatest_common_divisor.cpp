#include <iostream>

int gcd(const int a, const int b){
  if((a%b) == 0)
    return b;
  else
    return gcd(b, a%b);
}

int main(){
  int a=0, b=0;
  std::cin >> a >> b;

  std::cout << gcd(a, b) << std::endl;

  return 0;
}

