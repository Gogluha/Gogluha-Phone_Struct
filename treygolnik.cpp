#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    if (a <= 0 || b <= 0 || c <= 0) {
        std::cout << "UNDEFINED" << std::endl;
        return 0;
    }

    if (a + b <= c || a + c <= b || b + c <= a) {
        std::cout << "UNDEFINED" << std::endl;
        return 0;
    }

    int a2 = a * a;
    int b2 = b * b;
    int c2 = c * c;

    if (a2 == b2 + c2 || b2 == a2 + c2 || c2 == a2 + b2) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}