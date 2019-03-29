//
// Created by dyf on 18-10-30.
//

#include <iostream>
#include <vector>
#include<map>
#include <string>
#include <limits.h>
#include<algorithm>

int getN(int n){
    if(n<=1)
        return 1;
    else
        return n*getN(n-1);
}

std::string getPermutation(int n, int k) {
    std::vector<int> a;
    std::vector<int> b;
    for(int i=0;i<n;i++){
        a.push_back(i+1);
        b.push_back(0);
    }
    std::string str="";
    while(n!=0){
        int c=getN(n-1);
        if(k%c==0){
            k=k/c;
            int d=0;
            for(int i=0;i<a.size();i++){
                if(b[i]==0)
                    d++;
                if(d==k){
                    b[i]=1;
                    d=i;
                    break;
                }
            }
            char re[10];
            sprintf(re,"%d",a[d]);
            str+=re;
            for(int j=a.size()-1;j>=0;j--){
                if(b[j]!=1){
                    sprintf(re,"%d",a[j]);
                    str+=re;
                }
            }
            break;
        }else
        {
            int f=k/c+1;
            k=k%c;

            int d=0;
            for(int i=0;i<a.size();i++){
                if(b[i]==0)
                    d++;
                if(d==f){
                    b[i]=1;
                    d=i;
                    break;
                }
            }
            char re[10];
            sprintf(re,"%d",a[d]);
            str+=re;
            n--;
        }
    }
    return str;
}

int main() {

    std::cout<<getPermutation(5,49)<<std::endl;
    return 0;
}