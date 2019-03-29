//
// Created by dyf on 18-10-26.
//

//
// Created by dyf on 18-10-23.
//

#include <iostream>
#include <vector>
#include<map>
#include <string>
#include <limits.h>
#include<algorithm>

void combination(std::vector<std::vector<int>> &a,std::vector<int> v,std::vector<int> candidates,int target){
    if(target==0){
        a.push_back(v);
        return;
    }

    for(int i=0;i<candidates.size();i++) {
        int c=target;
        std::vector<int> v1=v;
        if(v1.size()!=0){
            int d=v1.back();
            if(d>candidates[i])
                continue;
        }
            c= c - candidates[i];
            if (c >= 0)
                v1.push_back(candidates[i]);
            else
                return;
            combination(a, v1, candidates, c);
    }
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> a;
    std::vector<int> v;
    std::sort(candidates.begin(),candidates.end());
    combination(a,v,candidates,target);
    return a;
}
int main() {
    //std::cout << "Hello, World!" << std::endl;
    std::vector<int> a={2,3,5,7};
    std::vector<std::vector<int>> b=combinationSum(a,8);
    for(int i=0;i<b.size();i++){
        for(int j=0;j<b[i].size();j++){
            std::cout<<b[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}
