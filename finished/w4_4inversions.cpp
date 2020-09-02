#include <iostream>
#include <vector>

using std::vector;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
    long long number_of_inversions = 0;
    if (right <= left + 1) return number_of_inversions;
    size_t ave = left + (right - left) / 2;//ave = center of section
    number_of_inversions += get_number_of_inversions(a, b, left, ave);
    number_of_inversions += get_number_of_inversions(a, b, ave, right);

    //Copy vector to be if not done yet
    if (b[0] == 0) {
        for (size_t i = 0; i<a.size();i++)
            b[i] = a[i];
    }

    //Create temporary vector to operate on
    vector<int> tmp(right);
    for (size_t i=left;i<right;i++)
        tmp[i] = b[i];

    //Keep track of locations
    size_t l_pos = left;
    size_t r_pos = ave;
    for (size_t i=left;i<right;i++) {
        if (l_pos == ave)//if the left subarray is exhausted...
            b[i] = tmp[r_pos++];
        else if (r_pos == right)//same for right
            b[i] = tmp[l_pos++];
        else {//Both subvectors have elements
            if (tmp[l_pos] <= tmp[r_pos])//No swap
                b[i] = tmp[l_pos++];
            else {//swap
                b[i] = tmp[r_pos++];
                number_of_inversions += ave-l_pos;
            }
        }
    }


    return number_of_inversions;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    vector<int> b(a.size());
    std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
