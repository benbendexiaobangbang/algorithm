//
// Created by dyf on 18-12-9.
//

#include <iostream>
#include<vector>



bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int h=matrix.size();
    if(h==0)
        return false;
    int w=matrix[0].size();
    if(w==0)
        return false;
    int i=0;
    int j=0;
    if(target<matrix[0][0])
        return false;
    else if(target==matrix[0][0])
        return true;
    while(i<h-1&&j<w-1){
        if(target>matrix[i+1][j+1])
        {
            i++;
            j++;
        }
        else if(target==matrix[i+1][j+1])
            return true;
        else if(target<matrix[i+1][j+1])
        {
            for(int k1=0;k1<i+1;k1++){
                if(target==matrix[k1][j+1])
                    return true;
            }
            for(int k1=0;k1<j+1;k1++){
                if(target==matrix[i+1][k1])
                    return true;
            }
            break;
        }
    }

    if(h>2)
        i=i+2;
    if(w>2)
        j=j+2;
        if(i<h){
            for(;i<h;i++){
                for(int k1=0;k1<w;k1++){
                    if(matrix[i][k1]==target)
                        return true;
                }
            }
        }

        if (j < w) {
            for (; j < w; j++) {
                for (int k1 = 0; k1 < h; k1++) {
                    if (matrix[k1][j] == target)
                        return true;
                }
            }
        }
    return false;
}

int main()
{
    std::vector<std::vector<int>> matrix = {
            {-1,3,4},
            {1,6,7}
    };
    std::cout<<searchMatrix(matrix,4)<<std::endl;
    return 0;
}