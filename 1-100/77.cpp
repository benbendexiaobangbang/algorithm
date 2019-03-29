//
// Created by dyf on 18-12-9.
//

#include<iostream>
#include<vector>

void com(std::vector<std::vector<int>>&a,std::vector<int> v,int n,int k,int st){
    if(v.size()==k)
        a.push_back(v);

    for(int i=st;i<=n;i++){
        v.push_back(i);
        com(a,v,n,k,i+1);
        v.pop_back();
    }
}

std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> a;
    std::vector<int> v;
    int i=1;
    com(a,v,n,k,i);
    return a;
}

int main()
{
    int n=4;
    int k=2;
    std::vector<std::vector<int>> a=combine(4,2);
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            std::cout<<a[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}