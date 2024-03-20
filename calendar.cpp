#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;

    int day = 1;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            if (i == 0 && j < n)
            {
                std::cout << "   ";
            } else if (day <= k)
            {
                if (day < 10)
                {
                    std::cout << " ";
                }
                std::cout << day << " ";
                day++;
            } else {
                break;
            }
        }
        std::cout << std::endl;
        if (day > k) {
            break;
        }
    }

    return 0;
}