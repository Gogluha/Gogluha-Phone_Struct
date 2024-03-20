#include <iostream>
#include <string>
#include <cctype>

std::string checkPassword(const std::string& password) {
    if (password.size() < 8 || password.size() > 14) {
        return "NO";
    }

    int classes[4] = {0, 0, 0, 0};
    for (char c : password) {
        if (c >= 33 && c <= 126) {
            if (isupper(c)) {
                classes[0] = 1;
            } else if (islower(c)) {
                classes[1] = 1;
            } else if (isdigit(c)) {
                classes[2] = 1;
            } else {
                classes[3] = 1;
            }
        }
    }

    if (classes[0] + classes[1] + classes[2] + classes[3] >= 3) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    std::string password;
    std::cin >> password;
    std::cout << checkPassword(password) << std::endl;

    return 0;
}
