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
    if(target<matrix[0][0])
        return false;
    if(target==matrix[0][0])
        return true;
    int i=1;
    for(;i<h;i++){
        if(target==matrix[i][0])
            return true;
        if(target<matrix[i][0])
            break;
    }
    i=i-1;
    if(target>matrix[i][w-1])
        return false;
    for(int j=1;j<w;j++) {
        if (target == matrix[i][j])
            return true;
    }
    return false;
}

int main()
{
    std::vector<std::vector<int>> matrix = {
    {1,   3,  5,  7},
            {10, 11, 16, 20},
            {23, 30, 34, 50}
    };
    std::cout<<searchMatrix(matrix,23)<<std::endl;
    return 0;
}