//
// Created by dyf on 19-3-4.
//

#include<iostream>
#include<vector>
int numDistinct(std::string s, std::string t) {
    if(s.size()<t.size()||s.size()==0||t.size()==0)
        return 0;
    std::vector<std::vector<int>>a;
    std::vector<int>v(s.size()+1);
    for(int i=0;i<t.size()+1;i++)
        a.push_back(v);
    for(int i=1;i<t.size()+1;i++){
        for(int j=i;j<s.size()+1;j++){
            if(i==1){
                if (t[i-1] == s[j-1])
                    a[i][j]=a[i][j-1]+1;
                else
                    a[i][j]=a[i][j-1];
            }else {
                if (t[i - 1] == s[j - 1])
                    a[i][j] = a[i][j-1] + a[i-1][j-1];
                else
                    a[i][j] = a[i][j-1];
            }
        }
    }
    return a[t.size()][s.size()];
}

int main()
{
    std::string s="rabbbit";
    std::string t="rabbit";
    std::cout<<numDistinct(s,t)<<std::endl;
    return 0;
}
