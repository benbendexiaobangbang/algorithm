//
// Created by dyf on 18-12-15.
//

#include<iostream>
#include<vector>
#include<algorithm>
bool scram(std::string s1,std::string s2){
    if(s1.size()!=s2.size())
        return false;
    if(s1==s2)
        return true;
    else {
        std::string str1 = s1, str2 = s2;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        if (str1 != str2)
            return false;
        for (int i = 1; i < s1.size(); i++) {
            std::string m1 = s1.substr(0, i);
            std::string m2 = s1.substr(i);
            std::string n1 = s2.substr(0, i);
            std::string n2 = s2.substr(i);
            if (scram(m1, n1) && scram(m2, n2))
                return true;
            n1 = s2.substr(0, s2.size() - i);
            n2 = s2.substr(s2.size() - i);
            if (scram(m1, n2) && scram(m2, n1))
                return true;
        }
    }
    return false;
}

bool isScramble(std::string s1, std::string s2) {
    if(s1.size()!=s2.size())
        return false;
    return scram(s1,s2);
}

int main(){
    std::string s1="abcde";
    std::string s2="caebd";
    std::cout<<isScramble(s1,s2)<<std::endl;
    return 0;
}