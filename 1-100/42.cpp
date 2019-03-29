//
// Created by dyf on 18-11-5.
//

#include <iostream>
#include <vector>
#include<map>
#include <string>
#include <limits.h>
#include<algorithm>

int trap(std::vector<int>& height) {
    if(height.size()<=2)
        return 0;
    int i=0;
    int sum=0;
    int c=0;
    int max=0;
    int c1=-1;
    while(i<height.size()-2){
            max=0;
            c1=-1;
            if(height[i]>height[i+1]){
                c=0;
                int j=i+1;
                for(;j<height.size();j++){
                    if(height[j]>=height[i])
                    {
                        int d=height[i];
                        sum+=d*(j-i-1)-c;
                        i=j;
                        break;
                    }
                    c+=height[j];
                }
                if(j==height.size())
                {
                    c=0;
                    int k=i+2;
                    for(;k<height.size();k++){
                        if(height[k]>height[i+1])
                        {
                            if(height[k]>max){
                                max=height[k];
                                c1=k;
                            }
                        }
                    }
                    if(c1!=-1)
                    {
                        int d=height[i]<height[c1]?height[i]:height[c1];
                        for(int t=i+1;t<c1;t++){
                            c+=height[t];
                        }
                        sum+=d*(c1-i-1)-c;
                        i=c1;
                    }else
                        i++;
                }
            }else
                i++;
    }
    return sum;
}
int main() {
    //std::cout << "Hello, World!" << std::endl;
    std::vector<int> height={4,9,4,5,3,2};
    std::cout<<trap(height)<<std::endl;
    return 0;
}
