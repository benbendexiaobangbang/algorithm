//
// Created by root on 19-3-7.
//

#include<iostream>
#include<vector>

int minCut(std::string s) {
    int n=s.size();
    std::vector<std::vector<int>>judge;
    std::vector<int> v(n);
    for(int i=0;i<n;i++){
        judge.push_back(v);
    }
    std::vector<int> dp(n);
    for(int i=n-1;i>=0;i--){
        dp[i]=INT32_MAX;
        for(int j=i;j<n;j++){
            if(s[j]==s[i]&&(j-i<=1||judge[i+1][j-1])){
                judge[i][j]=1;
                if(j+1<n){
                    dp[i]=std::min(dp[i],dp[j+1]+1);
                }
                else
                    dp[i]=0;
            }
        }
    }
    return dp[0];
}

int main()
{
    std::string s="abcdcba";
    std::cout<<minCut(s)<<std::endl;
    return 0;
}