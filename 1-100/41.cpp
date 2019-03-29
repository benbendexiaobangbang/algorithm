//
// Created by dyf on 18-10-30.
//

#include <iostream>
#include <vector>
#include<map>
#include <string>
#include <limits.h>
#include<algorithm>

int firstMissingPositive(std::vector<int>& nums) {
    int temp=0;
    int i=0;
    int t=0;
    if(nums.size()==0)
        return 1;
    while(i!=nums.size()){
        if(nums[i]==t+1||nums[i]<=0||nums[i]>nums.size()) {
            i++;
            t++;
        }
        else{
            if(nums[i]!=nums[nums[i]-1]){
            temp=nums[nums[i]-1];
            nums[nums[i]-1]=nums[i];
            nums[i]=temp;
            }
            else{
                i++;
                t++;
            }
        }
    }
    int j=0;
    for(;j<nums.size();j++){
        if(nums[j]!=j+1)
            return j+1;
    }
    return j+1;
}
int main() {
    //std::cout << "Hello, World!" << std::endl;
    std::vector<int> a={1,2,2,1,3,1,0,4,0};
    std::cout<<firstMissingPositive(a)<<std::endl;
    return 0;
}
