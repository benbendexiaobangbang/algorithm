//
// Created by dyf on 18-10-24.
//

#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
#include <algorithm>
#include<map>

//std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
//    std::vector<std::vector<int>> ss;
//    std::vector<std::vector<std::string>> sss;
//    std::map<std::string,std::vector<int>> m;
//    std::vector<int> c;
//    for(int j=0;j<26;j++)
//        c.push_back(0);
//
//    for(int i=0;i<strs.size();i++){
//        ss.push_back(c);
//        for(int k=0;k<strs[i].size();k++){
//            int d=strs[i][k]-'a';
//            ss[i][d]+=1;
//        }
//        m.insert(std::pair<std::string,std::vector<int>>(strs[i],ss[i]));
//    }
//    std::vector<std::string> a;
//    a.push_back(strs[0]);
//    sss.push_back(a);
//    for(int i=1;i<strs.size();i++){
//        std::vector<int>cc=m.at(strs[i]);
//        int j=0;
//        for(j=0;j<sss.size();j++){
//            std::string str=sss[j][0];
//            std::vector<int> bb=m.at(str);
//            if(bb==cc){
//                sss[j].push_back(strs[i]);
//                break;
//            }
//        }
//        if(j==sss.size()){
//            a.clear();
//            a.push_back(strs[i]);
//            sss.push_back(a);
//        }
//    }
//    return sss;
//}

//
//std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
//    std::vector<std::vector<std::string>> sss;
//    std::string s="";
//    std::string d="";
//    std::vector<std::string>v;
//    d=strs[0];
//    v.push_back(d);
//    sss.push_back(v);
//    for(int i=1;i<strs.size();i++){
//        s=strs[i];
//        std::sort(s.begin(),s.end());
//        int j=0;
//        for(;j<sss.size();j++){
//            d=sss[j][0];
//            std::sort(d.begin(),d.end());
//            if(s==d){
//                sss[j].push_back(strs[i]);
//                break;
//            }
//        }
//        if(j==sss.size())
//        {
//            v.clear();
//            v.push_back(strs[i]);
//            sss.push_back(v);
//        }
//    }
//    return sss;
//}

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::vector<std::vector<std::string>> sss;
    std::map<std::string,int> m;
    int c=0;
    std::string s="";
    std::vector<std::string> v;
    for(int i=0;i<strs.size();i++) {
        s = strs[i];
        std::sort(s.begin(), s.end());
        if (m.find(s) == m.end()) {
            m[s] = c;
            ++c;
            sss.push_back(std::vector<std::string>{});
        }
        sss[m[s]].push_back(strs[i]);
    }
    return sss;
}
int main() {
    //std::cout << "Hello, World!" << std::endl;
    double x=2.0;
    long n=-2;
    std::vector<std::string> strs={"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> ss=groupAnagrams(strs);
    for(int i=0;i<ss.size();i++)
    {
        for(int j=0;j<ss[i].size();j++) {
            std::cout<<ss[i][j]<<" "; }
        std::cout<<std::endl;
    }
    return 0;
}