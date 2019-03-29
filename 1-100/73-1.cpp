//
// Created by dyf on 18-12-2.
//

#include<iostream>
#include<vector>
#include<map>
void setZeroes(std::vector<std::vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();

    bool row= false;
    bool col=false;

    for(int i=0;i<m;i++){
        if(matrix[i][0]==0) {
            col = true;
            break;
        }
    }

    for(int i=0;i<n;i++){
        if(matrix[0][i]==0) {
            row = true;
            break;
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    }

    for(int i=1;i<m;i++){
        if(matrix[i][0]==0) {
            for (int k =1; k < n; k++) {
                matrix[i][k] = 0;
            }
        }
    }
    for(int i=1;i<n;i++) {
        if (matrix[0][i] == 0) {
            for (int k = 1; k < m; k++) {
                matrix[k][i] = 0;
            }
        }
    }

    if(col){
        for(int i=0;i<m;i++){
            matrix[i][0]=0;
        }
    }

    if(row){
        for(int i=0;i<n;i++){
            matrix[0][i]=0;
        }
    }
}

int main()
{
    std::vector<std::vector<int>> matrix={{0,1,2,0},
                                          {3,4,5,2},
                                          {1,3,1,5}};


    setZeroes(matrix);

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            std::cout<<matrix[i][j];
        }
        std::cout<<std::endl;
    }
    return 0;
}