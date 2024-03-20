#include <iostream>
#include <cmath>

double Fuction(int n)
{
    double sum = 0.0;
    for (int i = 1; i<=n; i++)
    {
        double elem = pow(-1,i+1)/i;
        sum += elem;
    }
    return sum;
}

int main()
{
    int n;
    std::cin >> n;
    double result = Fuction(n);
    std::cout << result;
}