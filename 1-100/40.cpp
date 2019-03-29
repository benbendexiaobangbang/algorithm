//
// Created by dyf on 18-10-26.
//

#include <iostream>
#include <vector>
#include<map>
#include <string>
#include <limits.h>
#include<algorithm>

void combination(std::vector<std::vector<int>> &a,std::vector<int> v,std::vector<int> candidates,int target,int len,int curr){
    if(target==0){
        for(int i=0;i<a.size();i++){
            if(v==a[i])
                return;
        }
        a.push_back(v);
        return;
    }

    int c=target;
    int d=candidates[curr];
    std::vector<int> v1=v;
    c=c-d;
    if(c<0)
        return;
    else if(c==0){
        v1.push_back(d);
        combination(a,v1,candidates,c,len,curr);
    }
    else
    {
        if(curr+1<len){
            combination(a,v1,candidates,c+d,len,curr+1);
            v1.push_back(d);
            combination(a,v1,candidates,c,len,curr+1);
        }
    }
}

std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> a;
    std::vector<int> v;
    std::sort(candidates.begin(),candidates.end());
    int len=candidates.size();
    combination(a,v,candidates,target,len,0);
    return a;
}
int main() {
    //std::cout << "Hello, World!" << std::endl;
    std::vector<int> a={5};
    std::vector<std::vector<int>> b=combinationSum2(a,5);
    for(int i=0;i<b.size();i++){
        for(int j=0;j<b[i].size();j++){
            std::cout<<b[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}
