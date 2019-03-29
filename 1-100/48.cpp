//
// Created by dyf on 18-11-24.
//

#include<iostream>
#include<vector>

void rotate(std::vector<std::vector<int>>& matrix) {
    int num=matrix.size()-1;
    int temp=0;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<i;j++){
            temp=0;
            temp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=temp;
        }
    }

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size()/2;j++){
            temp=0;
            temp=matrix[i][j];
            matrix[i][j]=matrix[i][num-j];
            matrix[i][num-j]=temp;
        }
    }
}

int main(){
    std::vector<std::vector<int>> a={{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};

    rotate(a);

    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            std::cout<<a[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}