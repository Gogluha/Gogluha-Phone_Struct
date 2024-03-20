#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::string s = "Some string";

    s += ' ';
    s += "functions";
    std::cout << s << "\n";

    std::string sub1 = s.substr(5,6);
    std::string sub2 = s.substr(12);

    size_t pos1 = s.find(' ');
    size_t pos2 = s.find(' ',pos1 + 1);
    size_t pos3 = s.find("str");
    size_t pos4 = s.find("#");
    std::cout << pos1 << "\n" << pos2 << "\n" << pos3 << "\n" << pos4;
}