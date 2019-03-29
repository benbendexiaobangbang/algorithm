//
// Created by dyf on 18-11-4.
//

#include <iostream>
#include <vector>
#include<map>
#include <string>
#include <limits.h>
#include<algorithm>

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    std::vector<int> a;
    if(nums.size()==0||k==0)
        return a;
    int max=nums[0];
    for(int i=i+1;i<k;i++){
        if(max<nums[i])
            max=nums[i];
    }
    for(int i=0;i<nums.size()-k+1;i++){
        if(nums[i+k-1]>max)
            max=nums[i+k-1];
        else {
            max = nums[i];
            for (int j = i + 1; j < i + k; j++) {
                if (max < nums[j])
                    max = nums[j];
            }
        }
        a.push_back(max);
    }
    return a;
}
int main() {
    std::vector<int> nums={1,3,-1,-3,5,3,6,7};
    int k=3;
    std::vector<int> a=maxSlidingWindow(nums,k);
    for(int i=0;i<a.size();i++){
        std::cout<<a[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}