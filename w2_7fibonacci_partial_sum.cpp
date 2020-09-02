#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int main() {
    int last_digit_period[] = {1, 2, 3, 5, 8, 3, 1, 4, 5, 9,
                               4, 3, 7, 0, 7, 7, 4, 1, 5, 6,
                               1, 7, 8, 5, 3, 8, 1, 9, 0, 9,
                               9, 8, 7, 5, 2, 7, 9, 6, 5, 1,
                               6, 7, 3, 0, 3, 3, 6, 9, 5, 4,
                               9, 3, 2, 5, 7, 2, 9, 1, 0, 1};
    long long from, to;
    std::cin >> from >> to;
    from--;
    to--;

    if (from == to) {
        std::cout << last_digit_period[from%60];
        return 0;
    }
//    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';

    int sum = last_digit_period[from%60];
    for (int i = from + 1; i <= to; i++)
        sum = (sum + last_digit_period[i%60])%10;

    std::cout << sum << std::endl;

}
