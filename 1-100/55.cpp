//
// Created by dyf on 18-11-24.
//

#include<iostream>
#include<vector>

bool canJump(std::vector<int>& nums) {
    if(nums.size()==1)
        return true;
    int i=nums.size()-1;
    while(i>=0){
        if(nums[i]!=0)
            i--;
        else{
            int c=1;
            int j=i-1;
            for(;j>=0;j--){
                if(nums[j]>c){
                    i--;
                    break;
                }else if(i==nums.size()-1&&nums[j]==c){
                    i--;
                    break;
                }
                c++;
            }
            if(j==-1)
                return false;
        }
    }
    return true;
}

int main(){
    std::vector<int> a={2,0,0};
    std::cout<<canJump(a)<<std::endl;
    return 0;
}