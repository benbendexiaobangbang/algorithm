//
// Created by dyf on 19-1-12.
//

#include<iostream>
#include<vector>
#include<string>

bool isInterleave(std::string s1,std::string s2,std::string s3){
    int t1=0;
    int t2=0;
    int t3=0;
    int n1=s1.size();
    int n2=s2.size();
    int n3=s3.size();
    std::vector<int> ss1;
    std::vector<int> ss2;
    std::vector<int> ss3;
    if(n1+n2!=n3)
        return false;
    while(t3<n3){
        if(s3[t3]==s2[t2]&&s3[t3]==s1[t1]){
            t3++;
            t1++;
            ss1.push_back(t1-1);
            ss2.push_back(t2);
            ss3.push_back(t3-1);
        }
        else if(s3[t3]==s1[t1]&&s3[t3]!=s2[t2]) {
            t3++;
            t1++;
        }
        else if(s3[t3]==s2[t2]&&s3[t3]!=s1[t1])
        {
            t3++;
            t2++;
        }
        else if(s3[t3]!=s2[t2]&&s3[t3]!=s1[t1])
        {
            if(ss1.size()!=0){
                t3=ss3.back();
                t2=ss2.back();
                t1=ss1.back();
                ss2.pop_back();
                ss1.pop_back();
                ss3.pop_back();
                t3++;
                t2++;
            }else
                return false;
        }
    }
    return true;
}

int main()
{
    std::string s1="aabcc";
    std::string s2="dbbca";
    std::string s3="aadbbcbcac";
    std::cout<<isInterleave(s1,s2,s3)<<std::endl;
    return 0;
}