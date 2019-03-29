//
// Created by dyf on 18-10-23.
//

#include <iostream>
#include <vector>
#include<map>
#include <string>
#include <limits.h>
#include<algorithm>

void letter(std::vector<std::string> &a,std::string digits,int number,std::map<char,std::vector<char>> m,std::string str){
    int len=digits.size();
    if(number==len){
        a.push_back(str);
        return;
    }
    char c=digits[number];
    std::vector<char>ss=m.at(c);

    for(int i=0;i<ss.size();i++){
        str+=ss[i];
        letter(a,digits,number+1,m,str);
        str = str.substr(0, str.length() - 1);
    }
}

std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> a;
    std::map<char,std::vector<char>> m;
    m.insert(std::pair<char,std::vector<char>>('2',{'a','b','c'}));
    m.insert(std::pair<char,std::vector<char>>('3',{'d','e','f'}));
    m.insert(std::pair<char,std::vector<char>>('4',{'g','h','i'}));
    m.insert(std::pair<char,std::vector<char>>('5',{'j','k','l'}));
    m.insert(std::pair<char,std::vector<char>>('6',{'m','n','o'}));
    m.insert(std::pair<char,std::vector<char>>('7',{'p','q','r','s'}));
    m.insert(std::pair<char,std::vector<char>>('8',{'t','u','v'}));
    m.insert(std::pair<char,std::vector<char>>('9',{'w','x','y','z'}));
    if(digits.size()==0)
        return a;
    letter(a,digits,0,m,"");
    return a;
}
int main() {
    //std::cout << "Hello, World!" << std::endl;
    std::string s="23";
    std::vector<std::string> a=letterCombinations(s);
    for(int i=0;i<a.size();i++)
       std::cout<<a[i]<<std::endl;
    return 0;
}
