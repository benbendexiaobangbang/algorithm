//
// Created by dyf on 18-11-24.
//

#include<iostream>
#include<vector>

std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    int top=0;
    int right=matrix[0].size()-1;
    int left=0;
    int bottom=matrix.size()-1;
    std::vector<int> c;
    int i=0;
    while(top<=bottom&&left<=right){
        if(i%4==0){
            for(int i=left;i<=right;i++) {
                c.push_back(matrix[top][i]);
            }
            top++;
        }
        else if(i%4==1){
            for(int i=top;i<=bottom;i++){
                c.push_back(matrix[i][right]);
            }
            right--;
        }
        else if(i%4==2){
            for(int i=right;i>=left;i--){
                c.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        else if(i%4==3){
            for(int i=bottom;i>=top;i--){
                c.push_back(matrix[i][left]);
            }
            left++;
        }
        i++;
    }
    return c;
}

int main(){
    std::vector<std::vector<int>> a={{1, 2, 3, 4},{5, 6, 7, 8},{9,10,11,12}};
    std::vector<int> b;
    b=spiralOrder(a);

    for(int i=0;i<b.size();i++){
            std::cout<<b[i]<<" ";
        std::cout<<std::endl;
    }
    return 0;
}