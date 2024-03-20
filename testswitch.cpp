#include <iostream>
#include <cstdint>

int main()
{
    char operation;
    double x, y;
    std::cin>>x>>operation>>y;

    double result;
    switch(operation)
    {
        case '+':
            result = x+y;
            break;
        case '-':
            result = x-y;
            break;
    }

std::cout<<result;
}