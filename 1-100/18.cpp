//
// Created by dyf on 18-10-23.
//

#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
#include<algorithm>
std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> a;
    std::vector<int> b;
    if(nums.size()<4)
        return a;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-3;i++){
        for(int j=i+1;j<nums.size()-2;j++){
            int c=target-nums[i]-nums[j];
            int s=j+1;
            int t=nums.size()-1;
            while(s<t){
                if(nums[s]+nums[t]>c)
                    t--;
                else if(nums[s]+nums[t]<c)
                    s++;
                else if(nums[s]+nums[t]==c){
                    b.clear();
                    b.push_back(nums[i]);
                    b.push_back(nums[j]);
                    b.push_back(nums[s]);
                    b.push_back(nums[t]);
                    int k=0;
                    if(a.size()==0){
                        a.push_back(b);
                    }else {
                        for (; k < a.size(); k++) {
                            if (a[k] == b)
                                break;
                        }
                        if (k == a.size()) {
                            a.push_back(b);
                        }
                    }
                    s++;
                }
            }
        }
    }
    return a;
}

int main() {
    //std::cout << "Hello, World!" << std::endl;
    std::vector<int> a={-3,-2,-1,0,0,1,2,3};
    std::vector<std::vector<int>> b=fourSum(a,0);
    for(int i=0;i<b.size();i++){
        for(int j=0;j<b[i].size();j++){
            std::cout<<b[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}
