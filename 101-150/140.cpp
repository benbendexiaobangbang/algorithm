//
// Created by root on 19-3-7.
//

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

bool wordBreak1(std::string s, std::vector<std::string>& wordDict) {
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

void breakWo(std::string s,std::vector<std::string>& wordDict,std::vector<std::string> &ss,std::string &s1){
    if(s.size()==0)
    {
        s1=s1.substr(0,s1.size()-1);
        ss.push_back(s1);
    }
    else
    {   std::string s2=s1;
        for(int i=0;i<s.size();i++){
            s1=s2;
            if(std::find(wordDict.begin(),wordDict.end(),s.substr(0,i+1))!=wordDict.end()){
                s1+=s.substr(0,i+1)+" ";
                breakWo(s.substr(i+1),wordDict,ss,s1);
            }
        }
    }

}

std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict) {
    std::vector<std::string> ss;
    std::string s1="";
    if(!wordBreak1(s,wordDict))
        return ss;
    else
        breakWo(s,wordDict,ss,s1);
    return ss;
}

//bool wordBreak1(string s, vector<string>& wordDict) {
//    if(s.size()==0){
//        return true;
//    }
//    if(wordDict.size()==0){
//        return false;
//    }
//    map<string, int> m;
//    int max_length = 0;
//    for(string s:wordDict){
//        if(max_length<s.length()){
//            max_length = s.length();
//        }
//        m[s]=1;
//    }
//    vector<bool> v(s.length()+1,false);
//    v[0] = true;
//    for(int i = 1; i < s.length()+1;i++){
//        for(int j = i-1;j>=0&&i-j<=max_length;j--){
//            if(m[s.substr(j,i-j)]==1 &&v[j] == true){
//                v[i] = true;
//                break;
//            }
//        }
//    }
//    return v[v.size()-1];
//}
//
//vector<string> wordBreak(string s, vector<string>& wordDict) {
//    if(!wordBreak1(s, wordDict)){
//        return {};
//    }
//    vector<vector<string>> dp(s.size()+1,vector<string>());
//    unordered_map<string, int> m;
//    int max_length = 0;
//    int min_length =INT32_MAX;
//    for(int i = 0;i<wordDict.size();i++){
//        m[wordDict[i]]++;
//        int val = wordDict[i].size();
//        max_length = max(max_length,val);
//        min_length = min(min_length,val);
//    }
//    dp[0]={""};
//    for(int i = 0;i+min_length-1<s.size();i++){
//        if(i!=0&&dp[i].size()==0){
//            continue;
//        }else{
//            for(int j=min_length;j<=max_length&&i+j-1<s.size();j++){
//                if(m.find(s.substr(i,j))!=m.end()){
//                    for(int k = 0;k<dp[i].size();k++){
//                        if(i==0){
//                            dp[i+j].push_back(s.substr(i,j));
//                        }else{
//                            dp[i+j].push_back(dp[i][k]+" "+s.substr(i,j));
//                        }
//                    }
//                }
//            }
//        }
//    }
//    return dp[s.size()];
//}

//
//void breakWo(std::string s,std::vector<std::string>& wordDict,std::vector<std::string> &ss,std::string &s1){
//    if(s.size()==0)
//    {
//        s1=s1.substr(0,s1.size());
//        ss.push_back(s1);
//    }
//    else
//    {   std::string s2=s1;
//        for(int i=0;i<wordDict.size();i++){
//            s1=s2;
//            if(s.find_first_of(wordDict[i])==0){
//                s1+=s.substr(0,wordDict[i].size())+" ";
//                breakWo(s.substr(wordDict[i].size()),wordDict,ss,s1);
//            }
//        }
//    }
//
//}
//
//std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict) {
//    std::vector<std::string> ss;
//    std::string s1="";
//    breakWo(s,wordDict,ss,s1);
//    return ss;
//}

int main()
{
    std::string s="catsanddog";
    std::vector<std::string> wordDict={
            "cat", "cats", "and", "sand", "dog"
    };
    //std::cout<<s.substr(0,3)<<std::endl;

    std::vector<std::string> d=wordBreak(s,wordDict);
   // sort(d.begin(),d.end(),compare);
    for(int i=0;i<d.size();i++){
        std::cout<<d[i]<<" ";
        std::cout<<std::endl;
    }

    return 0;
}