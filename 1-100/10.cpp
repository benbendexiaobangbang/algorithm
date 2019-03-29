//
// Created by dyf on 18-10-21.
//

//
// Created by dyf on 18-10-21.
//

#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
//bool isMatch(std::string s, std::string p) {
//    int j=0;
//    int i=0;
//    while(i<=s.size()-1&&j<=p.size()-1){
//        if(s[i]==p[j]){
//            i++;j++;
//        }
//        else if(p[j]=='.')
//        {
//            p[j]=s[i];
//            i++;
//            j++;
//        }
//        else if(p[j]=='*'){
//            int c1=1;
//            int c2=0;
//            int k=i;
//            if(s[i]!=s[i-1]||s[i-1]!=p[j-1]){
//                j++;
//            }else if(s[i]==s[i-1]&&s[i-1]==p[j-1]) {
//                for(k=i+1;k<s.size();k++){
//                    if(s[k]==s[i])
//                        c1++;
//                    else {
//                        i=k;
//                        break;
//                    }
//                }
//                if(i==s.size())
//                    return true;
//                for(k=j+1;k<p.size();k++){
//                    if(p[k]==p[j-1])
//                        c2++;
//                    else{
//                        j=k;
//                        break;
//                    }
//                }
//                if(c2>c1)return false;
//                if(j==s.size())
//                    return false;
//
//            }
//        }
//        else if(s[i]!=p[j]){
//            i=0;
//            j++;
//        }
//    }
//    if(i==s.size())
//        return true;
//    else
//        return false;
//}

bool isMatch(std::string s, std::string p) {
    std::vector<std::vector<bool>> match(s.length() + 2, std::vector<bool>(p.length() + 2, false));
    match[1][1] = s[0] == p[0] || p[0] == '.';
    for (int j = 2; j < p.length() + 1; j += 2)
        match[0][j] = match[0][j - 2] && p[j - 1] == '*';

    for (int i = 1; i < s.length() + 1; i++)
        for (int j = 2; j < p.length() + 1; j++)
        {
            if (p[j - 1] != '*')
                match[i][j] = match[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
            else
                match[i][j] = match[i][j - 2] || match[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.');
        }
    return match[s.length()][p.length()];
}

int main() {
    std::string s="";
    std::string p=".*";
    std::cout<<isMatch(s,p)<<std::endl;
    return 0;
}