//
// Created by dyf on 18-10-22.
//
#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
#include<algorithm>
int threeSumClosest(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> a;
    std::vector<int> b;
    sort(nums.begin(),nums.end());
    if(nums.size()<=3)
    {
        int c=0;
        for(int i=0;i<nums.size();i++)
            c+=nums[i];
        return c;
    }
    int sum=-1;
    int closest=nums[0]+nums[1]+nums[2];
    int min=std::abs(nums[0]+nums[1]+nums[2]-target);
    for(int i=0;i<nums.size()-2;i++){
        sum=target-nums[i];
        int l=i+1;
        int r=nums.size()-1;
        while(l<r){
            if(std::abs(sum-nums[l]-nums[r])<min){
                min=std::abs(sum-nums[l]-nums[r]);
                closest=nums[i]+nums[l]+nums[r];
            }
            if((sum-nums[l]-nums[r])>0){
                l++;
            }
            else if((sum-nums[l]-nums[r])<0){
                r--;
            }
            else if((sum-nums[l]-nums[r])==0)
                return target;
        }
    }
    return closest;
}
int main() {
    //std::cout << "Hello, World!" << std::endl;
    std::vector<int> a={1,2,5,10,11};
    std::cout<<threeSumClosest(a,12)<<std::endl;
    return 0;
}
