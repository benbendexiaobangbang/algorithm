//
// Created by dyf on 18-10-31.
//

#include <iostream>
#include <vector>
#include<map>
#include <string>
#include <limits.h>
#include<algorithm>

void push(std::vector<std::vector<int>> &a,std::vector<int> &v,std::vector<int> &nums,int n,int s){
    if(v.size()==n){
        a.push_back(v);
        return;
    }
    for(int i=s;i<nums.size();i++){
        v.push_back(nums[i]);
        push(a,v,nums,n,i+1);
        v.pop_back();
    }
}

std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    int n=0;
    std::vector<int> v;
    std::vector<std::vector<int>> a;
    std::vector<int> flag;
    for(int i=0;i< nums.size();i++){
        flag.push_back(0);
    }
    while(n!=nums.size()+1){
        v.clear();
        if(n==0)
            a.push_back(v);
        else{
            push(a,v,nums,n,0);
        }
        n++;
    }
    return a;
}

int main() {
    std::vector<int> a={1,2,3};
    //std::cout<<getPermutation(5,49)<<std::endl;
    std::vector<std::vector<int>> b=subsets(a);
    for(int i=0;i<b.size();i++){
        for(int j=0;j<b[i].size();j++){
            std::cout<<b[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}