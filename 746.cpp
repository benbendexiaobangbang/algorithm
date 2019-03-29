//
// Created by dyf on 18-12-1.
//

#include<iostream>
#include<vector>

int minCostClimbingStairs(std::vector<int>& cost) {
    std::vector<int> d(cost.size());
    d[0]=cost[0];
    d[1]=cost[1];
    for(int i=2;i<cost.size();i++){
        d[i]=std::min(d[i-1]+cost[i],d[i-2]+cost[i]);
    }
    return std::min(d[cost.size()-1],d[cost.size()-2]);
}

int main(){
    std::vector<int> cost={1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    std::cout<<minCostClimbingStairs(cost)<<std::endl;
}