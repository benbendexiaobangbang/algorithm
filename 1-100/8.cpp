//
// Created by dyf on 18-10-21.
//

#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
int myAtoi(std::string str) {
    std::cout<<str.size()<<std::endl;
    if(str.size()==0)return 0;
    int j=-1;
    for(int i=0;i<str.size();i++){
        if(str[i]==' ')
            continue;
        else {
            j = i;
            str=str.substr(j);
            break;
        }
    }
    std::cout<<str.size()<<std::endl;
    if(j==-1)return 0;
    int flag=0;
    if(str[0]=='-'){
        flag=1;
        str=str.substr(1);
    }
    else if(str[0]=='+'){
        flag=0;
        str=str.substr(1);
    }
    std::vector<int> a;
    for(int i=0;i<str.size();i++){
        if(str[i]>='0'&&str[i]<='9')
        {
            a.push_back((int)(str[i]-48));
        }
        else
            break;
    }
    if(a.size()==0)return 0;
    long sum=0;
    if(flag==0) {
        for (int i = 0; i < a.size(); i++) {
            sum = sum * 10 + a[i];
            if (sum >= 2147483647)
                return 2147483647;
        }
    }
    if(flag==1) {
        for (int i = 0; i < a.size(); i++) {
            sum = sum * 10 - a[i];
            if (sum <= -2147483648)
                return -2147483648;
        }
    }
    return sum;
}

int main() {
    //std::cout << "Hello, World!" << std::endl;
    std::string s="-91283472332";
    std::cout<<myAtoi(s)<<std::endl;
    return 0;
}