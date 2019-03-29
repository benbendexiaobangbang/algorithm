//
// Created by dyf on 18-12-2.
//

#include<iostream>
#include<vector>
#include<map>
void setZeroes(std::vector<std::vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();
    std::vector<int> m1(m+n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                m1[m+j]=1;
                m1[i]=1;
            }
        }
    }

    for(int i=0;i<m;i++){
        if(m1[i]==1) {
            for (int k = 0; k < n; k++) {
                matrix[i][k] = 0;
            }
        }
    }
    for(int i=m;i<m+n;i++){
        if(m1[i]==1) {
            for (int k = 0; k < m; k++) {
                matrix[k][i-m] = 0;
            }
        }
    }
}

int main()
{
    std::vector<std::vector<int>> matrix={{1},
                                          {0}};

    setZeroes(matrix);

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            std::cout<<matrix[i][j];
        }
        std::cout<<std::endl;
    }
    return 0;
}