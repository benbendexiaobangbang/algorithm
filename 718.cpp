//
// Created by dyf on 18-11-4.
//

//
// Created by dyf on 18-11-4.
//

#include <iostream>
#include <vector>
#include<map>
#include <string>
#include <limits.h>
#include<algorithm>

int findLength(std::vector<int>& A, std::vector<int>& B) {
    int s=A.size();
    int t=B.size();
    int max=0;
    std::vector<std::vector<int>> dp(s+1,std::vector<int>(t+1,0));
    for(int i=1;i<=s;i++){
        for(int j=1;j<=t;j++){
            if(A[i-1]==B[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                max=std::max(max,dp[i][j]);
            }
        }
    }
    return max;
}

int main() {
    std::vector<int> A={0,0,0,0,1};
    std::vector<int> B={1,0,0,0,0};
    std::cout<<findLength(A,B)<<std::endl;
    return 0;
}