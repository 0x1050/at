#include <iostream>

unsigned long long int lcm(int a, int b) {
    //ensure larger number is in a
    if (a < b)
        std::swap(a, b);

    //multiply larger number by incrementing multiples
    //starting at 1, check if it is a multiple of smaller
    //number, return if it is, increment multiple if not
    int multiple = 1;
    while (1) {
        if ((static_cast<unsigned long long int>(a*multiple)) % b == 0)
            return a*multiple;
        else
            multiple++;
    }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;

  return 0;
}
