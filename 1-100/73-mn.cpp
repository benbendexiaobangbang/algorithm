//
// Created by dyf on 18-12-2.
//

#include<iostream>
#include<vector>
#include<map>
void setZeroes(std::vector<std::vector<int>>& matrix) {
    std::vector<int> m1;
    std::vector<int> m2;
    int m=matrix.size();
    int n=matrix[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                m1.push_back(i);
                m2.push_back(j);
            }
        }
    }

    for(int k=0;k<m1.size();k++){
        //cout << iter->first << " : " << iter->second << endl;
        int i=m1[k];
        int j=m2[k];
        for(int k=0;k<n;k++){
            matrix[i][k]=0;
        }
        for(int k=0;k<m;k++){
            matrix[k][j]=0;
        }
    }
}

int main()
{
    std::vector<std::vector<int>> matrix={{0,1,2,0},
                                        {3,4,5,2}, {1,3,1,5}};

    setZeroes(matrix);

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            std::cout<<matrix[i][j];
        }
        std::cout<<std::endl;
    }
    return 0;
}