//
// Created by dyf on 19-1-12.
//

#include<iostream>
#include<vector>
#include<string>

bool isInterleave(std::string s1,std::string s2,std::string s3){
    int n1=s1.size();
    int n2=s2.size();
    int n3=s3.size();
    if(n1+n2!=n3)
        return false;
    if(n1==0&&n2!=0){
        for(int i=0;i<s2.size();i++){
            if(s2[i]!=s3[i])
                return false;
        }
        return true;
    }else if(n1!=0&&n2==0){
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s3[i])
                return false;
        }
        return true;
    }else if(n1==0&&n2==0)
        return true;
    std::vector<std::vector<int>> ss;
    std::vector<int> a(n2+1);
    for(int i=0;i<n1+1;i++){
        ss.push_back(a);
    }
    for(int i=1;i<n1+1;i++){
        if(s1[i-1]==s3[i-1])
            ss[i][0]=1;
        else
            break;
    }

    for(int j=1;j<n2+1;j++){
        if(s2[j-1]==s3[j-1])
            ss[0][j]=1;
        else
            break;
    }
    int i=1;
    int j=1;
    for(;i<n1+1;i++){
        for(j=1;j<n2+1;j++){
            if(ss[i][j-1]==1&&s3[i+j-1]==s2[j-1])
                ss[i][j]=1;
            else if(ss[i-1][j]==1&&s3[i+j-1]==s1[i-1])
                ss[i][j]=1;
            else if(ss[i-1][j-1]==1){
                if(s3[i+j-2]==s1[i-1]&&s3[i+j-1]==s2[j-1])
                    ss[i][j]=1;
                else if(s3[i+j-2]==s2[j-1]&&s3[i+j-1]==s1[i-1])
                    ss[i][j]=1;
            }
        }
    }
    return ss[i-1][j-1];
}

int main()
{
    std::string s1="aabaac";
    std::string s2="aadaaeaaf";
    std::string s3="aadaaeaabaafaac";
    std::cout<<isInterleave(s1,s2,s3)<<std::endl;
    return 0;
}