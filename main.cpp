#include "bst.hpp"
#include <iostream>

int main() {
    bst<int> t;
    t.insert(20);
    for (int j = 0; j < 20; ++j) {
        t.insert(j);
    }

    for (int j = 21; j < 40; ++j) {
        t.insert(j);
    }

    for (int i = 0; i < 40; ++i) {
        std::cout << t.contains(i) << std::endl;
    }

    std::cout << t.max_level() << std::endl;
    std::cout << t.is_balanced() << std::endl;
}