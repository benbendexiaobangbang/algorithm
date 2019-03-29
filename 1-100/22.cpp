//
// Created by dyf on 18-10-25.
//

#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
#include<algorithm>

void generateP(string sublist,vector<string>& res,int left,int right)
{
    if(left == 0 && right == 0)
    {
        res.push_back(sublist);
        return;
    }
    if(left > 0)
    {
        generateP(sublist+"(",res,left-1,right);
    }
    if(left < right)
    {
        generateP(sublist+")",res,left,right-1);
    }


}


vector<string> generateParenthesis(int n) {
    vector<string> res;
    generateP("",res,n,n);
    return res;
}

int main() {
    std::vector<std::string> a=generateParenthesis(3);
    for(int i=0;i<a.size();i++){
        std::cout<<a[i]<<std::endl;
    }
    return 0;
}