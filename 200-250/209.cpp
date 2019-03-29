//
// Created by dyf on 18-11-4.
//

#include <iostream>
#include <vector>
#include<map>
#include <string>
#include <limits.h>
#include<algorithm>

int minSubArrayLen(int s, std::vector<int>& nums) {
    int sum=0;
    int min=0;
    int begin=0,end=0;
    int i=0;
    for(;i<nums.size();i++){
        sum+=nums[i];
        end=i;
        if(sum>=s)
        {
            while(sum-nums[begin]>=s){
                sum=sum-nums[begin];
                begin++;
            }
            min=end-begin+1;
            break;
        }
    }
    end=i+1;
    while(end<nums.size()){
        sum=sum-nums[begin++]+nums[end];
        while(sum-nums[begin]>=s){
            sum=sum-nums[begin];
            begin++;
        }
        if(end-begin+1<min)
            min=end-begin+1;
        end++;
    }
    return min;
}

int main() {
    std::vector<int> nums={1,2,3,4,5};
    int k=11;
    std::cout<<minSubArrayLen(k,nums)<<std::endl;
    return 0;
}