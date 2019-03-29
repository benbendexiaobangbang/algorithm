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

int searchA(std::vector<int> nums,int s,int t,int target){
    if(s==t){
        if(target==nums[s])
            return true;
        else
            return false;
    }
    int m=(s+t)/2;
    return searchA(nums,s,m,target)||searchA(nums,m+1,t,target);
}

bool search(std::vector<int>& nums, int target) {
    if(nums.size()==0)
        return false;
    int c=0;
    sortA(nums,0,nums.size()-1,c);
    if(target>nums[nums.size()-1])
        return searchA(nums,0,c,target);
    else
        return searchA(nums,c,nums.size()-1,target);
}

int main() {
    std::vector<int> nums={2,5,6,0,0,1,2};
    int target=3;
    //int c;
    std::cout<<search(nums,target)<<std::endl;
    //sortA(nums,0,nums.size()-1,c);
    // std::cout<<c<<std::endl;
    return 0;
}