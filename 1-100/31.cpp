//
// Created by dyf on 18-10-30.
//

#include <iostream>
#include <vector>
#include<map>
#include <string>
#include <limits.h>
#include<algorithm>

void pailie(std::vector<std::string> &words,std::vector<std::string> &a,int len,int  number,std::string str,std::vector<int>&b){
    if(number==len){
        for(int i=0;i<a.size();i++){
            if(a[i]==str)
                return;
        }
        a.push_back(str);
        return;
    }
    for(int i=0;i<words.size();i++){
        std::string str1;
        str1=str;
        if(b[i]==0){
            str1=str1+words[i];
            number++;
            b[i]=1;
        }else
            continue;
        pailie(words,a,len,number,str1,b);
        number--;
        b[i]=0;
    }
}

std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
    std::vector<int> c;
    int len=words.size();
    if(len==0)
        return c;
    std::vector<std::string> a;
    int number=0;
    std::vector<int> b;
    for(int i=0;i<words.size();i++)
        b.push_back(0);
    pailie(words,a,len,0,"",b);
    int n=a[0].size();
    int m=s.size();
    for(int i=0;i<a.size();i++){
        std::string s2=s;
        std::string s1=a[i];
        int d=0;
        int f=0;
        while((int)(s2.find(s1,f))!=-1){
        d=s2.find(s1,f);
        c.push_back(d);
        f=d+1;
        }
    };
    return c;
}
int main() {
    std::string s="barfoothefoobarman";

    std::vector<std::string> a={"foo","bar"};
    //nextPermutation(a);
    //std::cout<<(int)(s.find("goodstus"))<<std::endl;
    std::vector<int> b=findSubstring(s,a);
    for(int i=0;i<b.size();i++){
        std::cout<<b[i]<<std::endl;
    }
    return 0;
}
