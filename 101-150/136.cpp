//
// Created by dyf on 19-1-12.
//

#include<iostream>
#include<vector>
int singleNumber(std::vector<int>& nums) {
    int result=0;
    for(int i=0;i<nums.size();i++)
        result=result^nums[i];
    return result;
}

int main()
{
    std::vector<int> aa={4,1,2,1,2};
    std::cout<<singleNumber(aa)<<std::endl;
    return 0;
}