//
// Created by root on 19-3-7.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
    std::vector<int> dp(s.size()+1);
    dp[0]=1;
    for(int i=0;i<s.size()+1;i++){
        for(int j=0;j<=i;j++){
            if(dp[j]&&std::find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end()){
                dp[i]=1;
            }
        }
    }
    return dp[s.size()];
}

//bool wordBreak(string s, vector<string>& wordDict) {
//    vector<bool> state(s.length()+1, false);
//    state[0] = true;
//    for (int i = 1; i <= s.length(); i++) {
//        for (int j = 0; j <= i ; j++) {
//            if (state[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end()) {
//                state[i] = true;
//            }
//        }
//    }
//    return state[s.length()];
//}

int main()
{
    std::string s="applepenapple";
    std::vector<std::string> wordDict={
            "apple","pen"
    };
    std::cout<<wordBreak(s,wordDict)<<std::endl;
    return 0;
}
