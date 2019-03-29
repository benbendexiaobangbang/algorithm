//
// Created by dyf on 19-3-4.
//

#include<iostream>
#include<vector>

//std::string longestPalindrome(std::string s) {
//    if(s.size()==0)
//        return "";
//    std::vector<std::vector<int>> b;
//    std::vector<int> v(s.size());
//    for(int i=0;i<s.size();i++){
//        b.push_back(v);
//    }
//    int maxlen=1;
//    int start=0;
//    for(int i=0;i<s.size();i++){
//        for(int j=0;j<=i;j++){
//            if(i-j<2)
//                b[j][i]=(s[i]==s[j]);
//            else
//                b[j][i]=(s[j]==s[i]&&b[j+1][i-1]);
//            if(b[j][i]&&maxlen<i-j+1){
//                maxlen=i-j+1;
//                start=j;
//            }
//        }
//    }
//    return s.substr(start,maxlen);
//}

std::string longestPalindrome(std::string s) {

    if(s.size()==0)
        return "";
    int maxlen=1;
    int start=0;
    for(int i=0;i<s.size()-1;i++){
        int s1=i;
        int t1=s.size()-1;
        int t=t1;
        while(s1<t1){
            if(s[s1]==s[t1])
            {
                s1++;
                t1--;
            }
            else
            {
                t--;
                s1=i;
                t1=t;
            }
        }
        if(t-i+1>maxlen){
            maxlen=t-i+1;
            start=i;
        }
    }
    return s.substr(start,maxlen);
}

int main()
{
    std::string s="cbbd";
    std::cout<<longestPalindrome(s)<<std::endl;
    return 0;
}