//
// Created by dyf on 18-11-12.
//
#include <iostream>
#include <vector>
#include<map>
#include <string>
#include <limits.h>
#include<algorithm>

std::string addi(std::string num1,std::string num2){
    std::string m="";
    int a=num1.size();
    int b=num2.size();
    int max=std::abs(a-b);
    for(int i=0;i<max;i++){
        m+="0";
    }
    if(num1.size()>num2.size()){
        num2=m+num2;
    }else{
        num1=m+num1;
    }
    int c=0;
    int d=0;
    for(int i=num1.size()-1;i>=0;i--){
        d=num1[i]+num2[i]+c-96;
        num1[i]=d%10+48;
        c=d/10;
        if(i==0&&c==1){
            num1="1"+num1;
        }
    }
    return num1;
}

std::string mul(std::string num1,int c){
    int m=0;
    int d=0;
    for(int i=num1.size()-1;i>=0;i--){
        d=(num1[i]-48)*c+m;
        num1[i]=d%10+48;
        m=d/10;
        if(i==0&&m!=0){
            num1=std::to_string(m)+num1;
        }
    }
    return num1;
}

std::string multiply(std::string &num1, std::string &num2) {
    std::string result="";
    std::string tmp="";
    std::string c="";
    for (int i = num2.size() - 1; i >= 0; i--) {
        tmp = mul(num1, num2[i] - 48);
        tmp=tmp+c;
        result = addi(result, tmp);
        c+="0";
    }
    int t=0;
    for(int i=0;i<result.size()-1;i++){
        if(result[i]!='0')
        {
            break;
        }
        t++;
    }
    result=result.substr(t);
    return result;
}

int main() {
    std::string nums1="123";
    std::string nums2="0";
    std::cout<<multiply(nums1,nums2)<<std::endl;
    return 0;
}

