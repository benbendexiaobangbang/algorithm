//
// Created by dyf on 19-3-10.
//

#include<iostream>
#include<vector>
using namespace std;

//dp[i]
int maxProduct(vector<int>& nums) {
   int maxDP=INT32_MIN;
   int dp1=0;
   int dp2=0;
   for(int i=0;i<nums.size();i++) {
       if (nums[i] > 0) {
           dp1 = max(nums[i], nums[i] * dp1);
           dp2 = nums[i] * dp2;
       } else {
           int t=dp1;
           dp1=max(nums[i]*dp2,nums[i]);
           dp2=min(nums[i]*t,nums[i]);
       }
       maxDP = std::max(dp1, maxDP);
   }
   return maxDP;
}

int main()
{
    std::vector<int> aa={
            2,-5,-2,-4,3

    };
    std::cout<<maxProduct(aa)<<std::endl;
    return 0;
}