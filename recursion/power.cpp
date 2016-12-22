#include <iostream>

int power(const int a, const int n){
  // basis step
  if (n==0)
    return 1;
  else
    return a*power(a, n-1);
}


int main(){
  int a = 0, n = 0;
  std::cin >> a >> n;

  std::cout << power(a, n) << std::endl;

  return 0;
}
