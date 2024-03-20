#include <iostream>
#include <cmath>

int main(){
    int P, V, Q, M;
    std::cin>> P >> V >> Q >> M;
    int totalcntV = 0;
    int totalcntM = 0;
    int P0= 1;
    int M0 = 1;
    totalcntV = abs(P0+V) + abs(P0-V);
    totalcntM = abs(M0+Q) + abs(M-Q);
    std::cout<< totalcntV+totalcntM;

}

