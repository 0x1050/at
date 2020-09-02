#include <iostream>

int get_change(int m) {
    int n = 0;
    int dimes = m/10;
    m %= 10;
    int nickels = m/5;
    m %= 5;
    return dimes + nickels + m;
}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
