//
// Created by dyf on 18-10-21.
//

#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

double myPow(double x, int n) {
    if(n == 0) return 1;
    if(n == 1) return x;
    int m= n / 2;
    if(n < 0) {
        m = -m;
        x = 1 / x;
    }
    double result = myPow(x, m);
    if(n % 2 == 0) return result * result;
    return result* result* x;
}

int main() {
    //std::cout << "Hello, World!" << std::endl;
    double x=2.0;
    long n=-2;
    std::cout<<myPow(x,n)<<std::endl;
    return 0;
}