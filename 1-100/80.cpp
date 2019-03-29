//
// Created by dyf on 18-12-10.
//

#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
#include<algorithm>

int removeDuplicates(std::vector<int>& nums) {
    if(nums.size()==0)
        return 0;
    int n=nums.size();
    int i=1;
    int a=1;
    while(i!=n)
    {
        if(nums[i]==nums[i-1])
        {
            a++;
            if(a>2)
            {
                for(int j=i;j<n-1;j++){
                    nums[j]=nums[j+1];
                }
                a=a-1;
                n--;
            }else
            {
                i++;
            }
        }
        else
        {
            a=1;
            i++;
        }
    }
    return n;
}

int main() {
    std::vector<int> nums={1,1,1,2,2,3};
    std::cout<<removeDuplicates(nums)<<std::endl;
    return 0;
}