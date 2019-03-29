//
// Created by dyf on 18-11-28.
//

#include<iostream>
#include<string>
#include<vector>

int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
    std::vector<std::vector<int>> cc;
    std::vector<int>v;
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();

    for(int i=0;i<obstacleGrid.size();i++) {
        v.clear();
        for (int j = 0; j < obstacleGrid[i].size(); j++) {
            v.push_back(0);
        }
        cc.push_back(v);
    }


    int flag=0;
    for(int i=0;i<m;i++){
        if(flag==1){
           cc[i][0]=0;
           continue;
        }
        if(obstacleGrid[i][0]==1) {
            flag = 1;
            cc[i][0]=0;
        }else
            cc[i][0]=1;
    }

    flag=0;
    for(int i=0;i<n;i++){
        if(flag==1){
            cc[0][i]=0;
            continue;
        }
        if(obstacleGrid[0][i]==1){
            flag=1;
            cc[0][i]=0;
        }
        else
            cc[0][i]=1;
    }

    if(m==1&&n==1)
        return cc[m-1][n-1];
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(obstacleGrid[i][j]==1)
                cc[i][j]=0;
            else
                cc[i][j]=cc[i-1][j]+cc[i][j-1];
        }
    }
    return cc[m-1][n-1];
}


int main()
{
    std::vector<std::vector<int>> a={{1}};
    std::cout<<uniquePathsWithObstacles(a)<<std::endl;
}