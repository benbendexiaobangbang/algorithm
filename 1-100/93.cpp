//
// Created by dyf on 18-12-23.
//

#include<iostream>
#include<string>
#include<vector>

void restore(std::vector<std::string> &a,std::string &s,int c,std::string ss,int d){
    if(c==s.size()&&d==4) {
        ss=ss.substr(0,ss.size()-1);
        a.push_back(ss);
        return;
    }else if(d==4&&c!=s.size())
    {
        return;
    }
    std::string ss1="";
    ss1+=s[c+0];
    ss+=ss1;
    ss+=".";
    restore(a,s,c+1,ss,d+1);
    ss=ss.substr(0,ss.size()-ss1.size()-1);
    if(c+1<=s.size()) {
        if(s[c]=='0')
            return;
        ss1 += s[c + 1];
        ss += ss1;
        ss += ".";
        restore(a, s, c + 2, ss, d + 1);
        ss = ss.substr(0, ss.size() - ss1.size() - 1);
    }
    if(c+2<s.size()) {
        ss1 += s[c + 2];
        int f = std::stoi(ss1);
        if (f <= 255) {
            ss += ss1;
            ss += ".";
        } else
            return;
        restore(a, s, c + 3, ss, d + 1);
    }
    return ;
}

std::vector<std::string> restoreIpAddresses(std::string s) {
    std::vector<std::string> a;
    if(s.size()>12||s.size()<4)
        return a;
    std::string ss="";
    int d=0;
    restore(a,s,0,ss,d);
    return a;
}

int main()
{
    std::string s="101023";
    std::vector<std::string> a=restoreIpAddresses(s);
    for(int i=0;i<a.size();i++){
        std::cout<<a[i]<<std::endl;
    }
    return 0;
}