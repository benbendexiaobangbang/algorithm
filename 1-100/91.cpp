//
// Created by dyf on 18-12-15.
//

#include <iostream>
#include <vector>
#include<map>
int numDecodings(std::string s) {
    if(s.find_first_not_of('0')!=0)
        return 0;
    std::vector<int> d;
    d.push_back(1);
    d.push_back(1);
    if(s[0]=='0')
        s=s.substr(1);
    std::string ss="";
    for(int i=2;i<s.size()+1;i++){
        ss="";
        ss+=s[i-1-1];
        ss+=s[i-1];
        if(s[i-1]=='0') {
            if(s[i-2]>'2')
                return 0;
            else if(s[i-2]=='0')
                return 0;
            if(i>=3) {
                if(s[i-2]>'0'&&s[i-2]<='2'&&s[i-3]>'0'&&s[i-3]<='2')
                    d.push_back(d[i-2]);
                else
                    d.push_back(d[i-1]);
            }
            else if (ss <= "26") {
                d.push_back(d[i - 1]);
            }

//            if(s[i-2]=='0')
//                return 0;
//            if (ss <= "26") {
//                d.push_back(d[i - 1]);
//            }
//            else
//                return 0;
        }
        else {
            if (s[i - 2] == '0') {
                d.push_back(d[i - 1]);
            } else {
                if (ss <= "26") {
                    d.push_back(d[i - 1] + d[i - 2]);
                } else
                {
                    d.push_back(d[i - 1]);
                }
            }
        }
    }

    return d[s.size()];
}

int main(){
    std::string s="7206";
    std::cout<<numDecodings(s)<<std::endl;
    return 0;
}