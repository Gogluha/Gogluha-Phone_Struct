#include <iostream>

int main()
{
    int n = 1;
    while(n<=10)
    {
        std::cout<< n << "\t" << n*n << "\n";
        ++n;
    }
}