//
// Created by dyf on 18-10-30.
//

//
// Created by dyf on 18-10-30.
//

#include <iostream>
#include <vector>
#include<map>
#include <string>
#include <limits.h>
#include<algorithm>

void perM(std::vector<std::vector<int>> &a,std::vector<int> &b,std::vector<int>&nums,std::vector<int>&v,int number,int len){
    if(len+1==number){
        for(int i=0;i<a.size();i++){
            if(a[i]==v)
                return;
        }
        a.push_back(v);
        return;
    }
    else {
        for(int i=0;i<=len;i++) {
            if (b[i] == 0) {
                v.push_back(nums[i]);
                number++;
                b[i]=1;
                perM(a,b,nums,v,number,len);
                b[i]=0;
                number--;
                v.pop_back();
            }
        }
    }

}

std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
    std::vector<std::vector<int>> a;
    int len=nums.size();
    std::vector<int> ch;
    for(int i=0;i<nums.size();i++){
        ch.push_back(0);
    }
    std::vector<int> v;
    if(len==0)
        return a;
    else
        perM(a,ch,nums,v,0,len-1);
    return a;
}
int main() {
    //std::cout << "Hello, World!" << std::endl;
    std::vector<int> a={1,1,2};
    std::vector<std::vector<int>> b=permuteUnique(a);
    for(int i=0;i<b.size();i++){
        for(int j=0;j<b[i].size();j++){
            std::cout<<b[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}