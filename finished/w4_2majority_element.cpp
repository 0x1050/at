#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
    if (left == right) return -1;
    if (left + 1 == right) return a[left];

    //Find distance to center, position it with left
    int center = (right-left)/2 + left;
    //Split the vector into recursive calls
    int l_majority = get_majority_element(a, left, center);
    int r_majority = get_majority_element(a, center, right);

    if (l_majority != -1 && l_majority == r_majority)
        return l_majority;

    //We should be only checking two numbers at this point
    int l_count = 0;
    int r_count = 0;
    for (int i=left;i<right;i++) {
        if (l_majority == a[i]) {
            l_count++;
            if (l_count > (right-left)/2)
                return l_majority;
        }//There is no need to check the right element if
        else if (r_majority == a[i]) {
            r_count++;
            if (r_count > (right-left)/2)
                return r_majority;
        }
    }

    return -1;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
