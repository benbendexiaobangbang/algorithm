//
// Created by root on 19-3-10.
//

#include<iostream>
#include<vector>
using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    std::vector<std::vector<int>> dp(dungeon.size(),std::vector<int>(dungeon[0].size()));
    int m=dungeon.size();
    int n=dungeon[0].size();

    dp[m-1][n-1]=max(1,1-dungeon[m-1][n-1]);

    for(int i=m-2;i>=0;i--){
        dp[i][n-1]=max(1,dp[i+1][n-1]-dungeon[i][n-1]);
    }

    for(int i=n-2;i>=0;i--){
        dp[m-1][i]=max(1,dp[m-1][i+1]-dungeon[m-1][i]);
    }

    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            int dp_min=min(dp[i+1][j],dp[i][j+1]);
            dp[i][j]=max(1,dp_min-dungeon[i][j]);
        }
    }
    return dp[0][0];
}


int main()
{
    std::vector<std::vector<int>> aa={
            {1,-4,5,-99},{2,-2,-2,-1}

            //{1,-3,3},{0,-2,0},{-3,-3,-3}

            //{-2,-3,3},{-5,-10,1},{10,30,-5}

    };
    std::cout<<calculateMinimumHP(aa)<<std::endl;
    return 0;
}