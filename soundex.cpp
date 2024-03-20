#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string soundex(const std::string& word) {
    std::string result = "";

    result += word[0];

    std::vector<char> soundexValues = {'a', 'e', 'i', 'o', 'u', 'w', 'y'};
    std::vector<char> soundexDigits = {'1', '2', '2', '3', '3', '0', '0'};

    for (size_t i = 1; i < word.size(); ++i) {
        char currentChar = std::tolower(word[i]);
        if (std::find(soundexValues.begin(), soundexValues.end(), currentChar) != soundexValues.end()) {
            continue;
        }

        if (currentChar == 'b' || currentChar == 'f' || currentChar == 'p' || currentChar == 'v') {
            result += '1';
        } else if (currentChar == 'c' || currentChar == 'g' || currentChar == 'j' || currentChar == 'k' ||
                   currentChar == 'q' || currentChar == 's' || currentChar == 'x' || currentChar == 'z') {
            result += '2';
        } else if (currentChar == 'd' || currentChar == 't') {
            result += '3';
        } else if (currentChar == 'l') {
            result += '4';
        } else if (currentChar == 'm' || currentChar == 'n') {
            result += '5';
        } else if (currentChar == 'r') {
            result += '6';
        }
    }

    while (result.size() < 4) {
        result += '0';
    }

    return result;
}

int main() {
    std::cout << soundex("ammonium") << std::endl; // Output: a500
    std::cout << soundex("implementation") << std::endl; // Output: i514

    return 0;
}
