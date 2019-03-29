//
// Created by dyf on 18-11-30.
//

#include<iostream>
#include<vector>

int climbStairs(int n) {
    std::vector<int> a(n);

    if(n==1) {
        return 1;
    }
    if(n==2) {
        return 2;
    }
    if(n>2) {
        a[0] = 1;
        a[1] = 2;
        for (int i =2;i<n;i++){
            a[i]=a[i-1]+a[i-2];
        }
        return a[n-1];
    }
}

int main(){
    std::cout<<climbStairs(5)<<std::endl;
}