//
// Created by dyf on 18-11-12.
//

#include<iostream>
#include<string>

std::string countAndSay(int n) {
    std::string s="";
    s+="1";
    if(n==1)
        return s;
    for(int i=2;i<=n;i++){
        std::string ss1="";
        int c=1;
        char cc=s[0];
        int j=1;
        for(;j<s.size();j++){
            if(cc==s[j])
            {
                c++;
            }else
            {
                ss1+=std::to_string(c);
                ss1+=s[j-1];
                cc=s[j];
                c=1;
            }
        }

        ss1+=std::to_string(c);
        ss1+=s[j-1];
        s=ss1;
    }
    return s;
}

int main()
{
    std::cout<<countAndSay(6)<<std::endl;
    return 0;
}