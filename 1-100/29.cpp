//
// Created by dyf on 18-10-27.
//

#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
#include<algorithm>
//int divide(int dividend, int divisor) {
//    int i=0;
//    int flag=0;
//    if(dividend==0)
//        return 0;
//    if(dividend==-2147483648){
//        if(divisor==-1)
//            return 2147483647;
//        else if(divisor==1)
//            return -2147483648;
//    }
//    if((dividend<0&&divisor>0)||(dividend>0&&divisor<0))
//        flag=1;
//    if(dividend>0)
//        dividend=-dividend;
//    if(divisor>0)
//        divisor=-divisor;
//    if(dividend>divisor)
//        return 0;
//    while(dividend<=0)
//    {
//        dividend=dividend-divisor;
//        if(dividend<=0)
//            i+=1;
//    }
//    if(flag==1)
//        i=-i;
//    return i;
//}

int divide(int dividend, int divisor) {
    if(dividend == INT_MIN && divisor == -1) return INT_MAX;
    long d=std::abs((long)dividend);
    long b=std::abs((long)divisor);
    long res=0;
    if(b==1)
        return (int)(((dividend<0)^(divisor<0))?d*-1:d);

    while(d>=b){
        long tmp=b;
        long p=1;
        while(d>=(tmp<<1)){
            tmp<<=1;
            p<<=1;
        }
        d-=tmp;
        res+=p;
    }
    return (int)(((dividend<0)^(divisor<0))?-res:res);
}

int main() {
    long dividend=10;
    long divisor=3;
    std::cout<<divide(dividend,divisor)<<std::endl;
    return 0;
}