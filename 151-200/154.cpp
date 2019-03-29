//
// Created by dyf on 18-11-4.
//

#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
#include<algorithm>

void sortA(std::vector<int>&nums,int s,int t,int &n){
    if(s==t){
        if(s!=nums.size()-1&&nums[s]>nums[s+1])
        {
            n=s;
            return;
        }
    }else
    {
        int m=(s+t)/2;
        sortA(nums,s,m,n);
        sortA(nums,m+1,t,n);
    }
}

int findMin(std::vector<int>& nums) {
    if(nums.size()==0)
        return -1;
    if(nums.size()==1)
        return nums[0];
    int c=-1;
    sortA(nums,0,nums.size()-1,c);

    return nums[c+1];
}
int main() {
    std::vector<int> nums={2,2,2,0,1};
    //int c;
    std::cout<<findMin(nums)<<std::endl;
    //sortA(nums,0,nums.size()-1,c);
    // std::cout<<c<<std::endl;
    return 0;
}