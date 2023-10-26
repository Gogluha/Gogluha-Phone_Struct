#include <iostream>
#include <string>



struct MPhone {
    double weight;
    bool is_broken;
    double price;
};



int main() {
    int num;

    std::cout << "Введите количество мобильных телефонов: ";
    std::cin >> num;

    MPhone* mobiles = new MPhone[num]; 

    for(int i = 0; i < num; ++i) {
        std::cout << "Введите вес, состояние (1 - сломан, 0 - не сломан) и цену телефона №" << i+1 << ": ";
        std::cin >> mobiles[i].weight >> mobiles[i].is_broken >> mobiles[i].price;
    }

    std::cout << "\n<MobilePhones>\n";
    for (int i = 0; i < num; ++i) {
        std::cout << "    <MobilePhone id=\"" << i << "\" weight=\"" << mobiles[i].weight
                  << "\" is_broken=\"" << (mobiles[i].is_broken ? "true" : "false")
                  << "\" price=\"" << mobiles[i].price << "\"/>\n";
    }
    std::cout << "</MobilePhones>\n";

    delete[] mobiles; 

    return 0;
}