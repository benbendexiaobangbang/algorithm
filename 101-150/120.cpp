//
// Created by root on 19-3-7.
//
#include<iostream>
#include<vector>

int minimumTotal(std::vector<std::vector<int>>& triangle) {
    if(triangle.size()==0)
        return 0;
    if(triangle.size()==1)
        return triangle[0][0];

    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<triangle[i].size();j++){
            if(j==0)
                triangle[i][j]=triangle[i-1][j]+triangle[i][j];
            else if(j==triangle[i].size()-1)
                triangle[i][j]=triangle[i-1][j-1]+triangle[i][j];
            else
                triangle[i][j]=triangle[i][j]+std::min(triangle[i-1][j-1],triangle[i-1][j]);
        }
    }

    long min=INT64_MAX;
    for(int i=0;i<triangle[triangle.size()-1].size();i++){
        if(min>triangle[triangle.size()-1][i])
            min=triangle[triangle.size()-1][i];
    }
    return min;
}

//int minimumTotal(std::vector<std::vector<int>> &triangle) {
//    int n=triangle.size();
//    std::vector<int> dp(triangle.back());
//    for(int i=n-2;i>=0;i--){
//        for(int j=0;j<=i;j++){
//            dp[j]=std::min(dp[j],dp[j+1])+triangle[i][j];
//        }
//    }
//    return dp[0];
//}

int main()
{
    std::vector<std::vector<int>> triangle={{2},
                                            {3,4},
                                            {6,5,7},
                                            {4,1,8,3}};
    std::cout<<minimumTotal(triangle)<<std::endl;
    return 0;
}
