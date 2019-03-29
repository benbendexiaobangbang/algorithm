//
// Created by dyf on 18-10-22.
//

#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
int maxArea(std::vector<int>& height) {
    int max=0;
    int h=0;
    for(int i=0;i<height.size()-1;i++)
    {
        for(int j=i+1;j<height.size();j++)
        {
            h=std::min(height[i],height[j]);
            if(h*(j-i)>max)
                max=h*(j-i);
        }
    }
    return max;
}

int main() {
    //std::cout << "Hello, World!" << std::endl;
    std::vector<int> a={1,8,6,2,5,4,8,3,7};
    std::cout<<maxArea(a)<<std::endl;
    return 0;
}