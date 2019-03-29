//
// Created by dyf on 18-11-24.
//

#include<iostream>
#include<vector>

int jump(std::vector<int>& nums) {
    int min=0;
    if(nums.size()==1)
        return min;
    int i=0;
    int max=0;
    int t=0;
    int len=0;
    while(i<nums.size()){
        if(i+max>=nums.size()-1)
            return min+1;
        max=i+nums[i];
        len=max;
        t=i;
        for(int j=i+1;j<=len&&j<nums.size();j++){
            if(j+nums[j]>max){
                max=j+nums[j];
                t=j;
            }
        }
        i=t;
        min++;
    }
    return min;
}

int main(){
    std::vector<int> a={1,1,1,1};
    std::cout<<jump(a)<<std::endl;
    return 0;
}