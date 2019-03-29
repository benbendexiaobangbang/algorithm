//
// Created by dyf on 18-11-3.
//

#include <iostream>
#include <vector>
#include<map>
#include <string>
#include <limits.h>
#include<algorithm>
using namespace std;
//std::string minWindow(std::string s, std::string t) {
//    if(s.size()<t.size())
//        return "";
//    int min=s.size();
//    int t1=-1,t2=-1;
//    // while(!s.empty())
//    for(int i=0;i<s.size()-t.size()+1;i++){
//        int minx=s.size();
//        int maxx=-1;
//        int j=0;
//        int m=0;
//        for(;j<t.size();j++){
//            std::string str="";
//            str=s.substr(i);
//            int flag=0;
//            int t3=-1;
//            t3=i;
//            int ss=-1;
//            for(int k=0;k<j;k++){
//                if(t[k]==t[j])
//                {
//                    ss=str.find_first_of(t[k]);
//                    t3=t3+ss+1;
//                    flag=1;
//                    str=s.substr(t3);
//                }
//            }
//            ss=str.find_first_of(t[j]);
//            if(ss==-1)
//                break;
//            t3+=ss;
//            if(t3>maxx)
//                maxx=t3;
//            if(t3<minx)
//                minx=t3;
//        }
//        if(j==t.size()&&maxx-minx<min)
//        {
//            min=maxx-minx;
//            t1=minx;
//            t2=maxx;
//        }
//    }
//    if(t1!=-1&&t2!=-1)
//        return s.substr(t1,t2-t1+1);
//    else if(t1==-1||t2==-1)
//        return "";
//
//}

string minWindow(string s, string t) {
    vector<int> map(128,0);
    for(auto c: t)
        map[c]++;
    int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
    while(end<s.size()){
        if(map[s[end]]>0)
        {
            map[s[end]]-=1;
            end+=1;
            counter--; //in t
        }
        else
        {
            map[s[end]]-=1;
            end+=1;
        }
        while(counter==0){ //valid
            if(end-begin<d)
                d=end-(head=begin);
            if(map[s[begin]]==0){
                map[s[begin]]+=1;
                begin+=1;
                counter++; //make it invalid
            }
            else
            {
                map[s[begin]]+=1;
                begin+=1;
            }
        }
    }
    return d==INT_MAX? "":s.substr(head, d);
}

int main() {
    //std::cout << "Hello, World!" << std::endl;
    std::string s ="ADOBECODEBANC";
    std::string t="ABC";
    std::cout<<minWindow(s,t)<<std::endl;
            //std::cout<<s.substr(2,4)<<std::endl;
    //std::cout<<s.find_first_of('B')<<std::endl;
    return 0;
}