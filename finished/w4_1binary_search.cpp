#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x) {
    int left = 0, right = (int)a.size() - 1;
    int center;
    bool found = false;

    while (left <= right && !found) {
        center = (left + right) / 2;
        if (a[center] == x)
            found = true;
        else if (a[center] > x)
            right = center - 1;
        else
            left = center + 1;
    }

    if (found)
        return center;
    else
        return -1;
}

int linear_search(const vector<int> &a, int x) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == x) return i;
    }
    return -1;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cout << binary_search(a, b[i]) << ' ';
        //std::cout << linear_search(a, b[i]) << ' ';
    }
    std::cout << std::endl;
}
