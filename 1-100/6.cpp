//
// Created by dyf on 18-10-21.
//

#include <iostream>
#include <vector>
#include <string>
std::string convert(std::string s, int numRows) {
    if(numRows<=0) return NULL;
    if(numRows==1) return s;
    std::vector<std::vector<char>> a;
    int len=2*numRows-2;
    for(int i=0;i<numRows;i++){
        std::vector<char> v;
        a.push_back(v);
    }
    for(int i=0;i<s.size();i++){
        for(int j=0;j<numRows;j++){
            if(i%len==j){
                a[j].push_back(s[i]);
            }
        }
        for(int j=numRows;j<len;j++){
            if(i%len==j){
                a[len-j].push_back(s[i]);
            }
        }
    }
    char c[s.size()];

    int i=0;
    for(int j=0;j<a.size();j++){
        for(int k=0;k<a[j].size();k++){
            c[i++]=a[j][k];
        }
    }
    std::string str=c;
    return str.substr(0,s.size());
}

int main() {
    //std::cout << "Hello, World!" << std::endl;
    std::string s="PAYPALISHIRING";
    std::cout<<convert(s,4)<<std::endl;
    return 0;
}