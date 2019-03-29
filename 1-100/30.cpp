//
// Created by dyf on 18-11-3.
//

#include <iostream>
#include <vector>
#include<map>
#include <string>
#include <limits.h>
#include<algorithm>
//
//void pailie(std::vector<std::string> &words,std::vector<std::string> &a,int len,int  number,std::string str,std::vector<int>&b){
//    if(number==len){
//        for(int i=0;i<a.size();i++){
//            if(a[i]==str)
//                return;
//        }
//        a.push_back(str);
//        return;
//    }
//    for(int i=0;i<words.size();i++){
//        std::string str1;
//        str1=str;
//        if(b[i]==0){
//            str1=str1+words[i];
//            number++;
//            b[i]=1;
//        }else
//            continue;
//        pailie(words,a,len,number,str1,b);
//        number--;
//        b[i]=0;
//    }
//}
//
//std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
//    std::vector<int> c;
//    int len=words.size();
//    if(len==0)
//        return c;
//    std::vector<std::string> a;
//    int number=0;
//    std::vector<int> b;
//    for(int i=0;i<words.size();i++)
//        b.push_back(0);
//    pailie(words,a,len,0,"",b);
//    int n=a[0].size();
//    int m=s.size();
//    for(int i=0;i<a.size();i++){
//        std::string s2=s;
//        std::string s1=a[i];
//        int d=0;
//        int f=0;
//        while((int)(s2.find(s1,f))!=-1){
//            d=s2.find(s1,f);
//            c.push_back(d);
//            f=d+1;
//        }
//    };
//    return c;
//}

void clear(std::vector<int> b,int len){
    for(int m=0;m<len;m++){
        b[m]=0;
    }
}

bool compare(std::string str,std::vector<std::string> &words,std::vector<int> b){
    int i=0;
    int c=0;
    int flag=0;
    while(i!=str.size()){
        flag=0;
        for(int j=0;j<words.size();j++){
            if(b[j]==0){
                if(str.substr(i,words[j].size())==words[j]){
                    b[j]=1;
                    c+=1;
                    flag=1;
                    i=i+words[j].size();
                    if(i==str.size())
                        return true;
                    break;
                }
            }
        }
        if(flag==0)
            return false;
    }
}
std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
    std::vector<int> a;
    std::vector<int> b;
    if(s.size()==0||words.size()==0)
        return a;
    int len=words.size();
    for(int i=0;i<len;i++){
        b.push_back(0);
    }
    int c=0;
    for(int i=0;i<len;i++){
        c+=words[i].size();
    }
    for(int i=0;i<s.size()-c+1;i++){
        std::string str=s.substr(i,c);
        if(compare(str,words,b))
            a.push_back(i);
    }
    return a;
}
//std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
//    std::vector<int> a;
//    std::vector<int> b;
//    int len=words.size();
//    for(int i=0;i<len;i++){
//        b.push_back(0);
//    }
//    int t=0;
//    int c=0;
//    for(int i=0;i<len;i++){
//        c+=words[i].size();
//    }
//    int i=0;
//    int flag=0;
//    while(i<s.size()){
//        flag=0;
//        for(int j=0;j<len;j++){
//            int k=0;
//            for(;k<words[j].size();k++){
//                if(b[j]==0){
//                    if(s[i]==words[j][k]) {
//                        i++;
//                    }
//                    else {
//                        i=i-k;
//                        break;
//                    }
//                }else {
//                    break;}
//            }
//            if(k==words[j].size()){
//                b[j]=1;
//                t=t+k;
//                flag=1;
//                if(c==t){
//                    a.push_back(i-t);
//                    i=i-t+1;
//                    t=0;
//                    for(int m=0;m<len;m++){
//                        b[m]=0;
//                    }
//                }
//                break;
//            }
//        }
//        if(flag==0){
//            if(t==0){
//                i++;
//            }
//            else{
//                i=i-t+1;
//                t=0;
//                clear(b,len);
//            }
//        }
//    }
//    return a;
//}

int main() {
    //std::cout << "Hello, World!" << std::endl;
    std::string s ="barfoothefoobarman";
    std::vector<std::string> a={"foo","bar"};
    std::vector<int> b=findSubstring(s,a);
    for(int i=0;i<b.size();i++){
        std::cout<<b[i]<<" ";
    }
//    std::vector<int> b;
//    int len=a.size();
//    for(int i=0;i<len;i++){
//        b.push_back(0);
//    }
//    std::cout<<compare(s,a,b)<<std::endl;
//    std::cout<<std::endl;
    return 0;
}
