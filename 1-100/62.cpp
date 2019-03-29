//
// Created by dyf on 18-11-28.
//

#include<iostream>
#include<string>
#include<vector>

int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> cc;
    std::vector<int>v;
    for(int i=0;i<m;i++){
        v.clear();
        for(int j=0;j<n;j++){
            v.push_back(0);
        }
        cc.push_back(v);
    }
    for(int i=0;i<m;i++){
        cc[i][0]=1;
    }
    for(int i=0;i<n;i++){
        cc[0][i]=1;
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            cc[i][j]=cc[i][j-1]+cc[i-1][j];
        }
    }
    return cc[m-1][n-1];
}


int main()
{
    int m=3,n=2;
    std::cout<<uniquePaths(7,3)<<std::endl;
}