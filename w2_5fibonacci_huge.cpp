#include <iostream>

//find the length of the pisano period
unsigned int find_pisano_length(unsigned long long n, unsigned long long m) {
    unsigned long prev = 1;
    unsigned long current = 1;
    unsigned long tmp;

    unsigned int pos = 3;
    for (;pos < n;pos++) {
        tmp = prev;
        prev = current;
        current = (tmp + prev)%m;

        if (tmp == 0 && prev == 1 && current == 1)
                break;
    }

    return pos-2;
}

void fill_pisano(unsigned int * pis, int size, unsigned long long n, unsigned long long m) {
    for (int i = 0; i < 2; i++)
        pis[i] = i;
    pis[2] = 1;

    unsigned long long prev = 1;
    unsigned long long curr = 1;
    unsigned long long tmp;

    for (int i = 3; i<size;i++) {
        tmp = prev;
        prev = curr;
        curr += tmp;

        pis[i] = curr%m;
    }
}



int main() {
    unsigned long long n, m;
    std::cin >> n >> m;

    unsigned int pisano[find_pisano_length(n, m)];
    fill_pisano(pisano, sizeof(pisano)/sizeof(pisano[0]), n, m);

    unsigned int pos = m%sizeof(pisano);

    for (int i = 0; i < static_cast<int>(sizeof(pisano)/sizeof(pisano[1])); i++)
        std::cout << pisano[i] << " ";
    std::cout << std::endl << pisano[pos-1] << std::endl;

    return 0;
}

