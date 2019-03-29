//
// Created by dyf on 18-11-14.
//

#include <iostream>
#include <vector>
#include<map>
#include <string>
#include <limits.h>
#include<algorithm>

bool isMatch(std::string s, std::string p) {
    std::vector<std::vector<bool>> match(s.length() + 1, std::vector<bool>(p.length() + 1, false));
    //match[1][1] = s[0] == p[0] || p[0] == '?'||p[0]=='*';
    match[0][0]=1;
    for(int i=1;i<p.length()+1;i++){
        if(p[i-1]=='*'&&match[0][i-1]==1)
            match[0][i]=1;
    }

    for(int i=1;i<s.size()+1;i++){
        for(int j=1;j<p.size()+1;j++){
            if(p[j-1]!='*'){
                match[i][j]=match[i-1][j-1]&&(p[j-1]==s[i-1]||p[j-1]=='?');
            }
            else
            {
                match[i][j]=match[i-1][j-1]||match[i][j-1]||match[i-1][j];
            }
        }
    }

    return match[s.length()][p.length()];

}

int main() {
    std::string nums1="aa";
    std::string nums2="a";
    std::cout<<isMatch(nums1,nums2)<<std::endl;
    return 0;
}

