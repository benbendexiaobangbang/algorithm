//
// Created by dyf on 18-11-24.
//

#include<iostream>
#include<vector>

std::vector<std::vector<int>> generateMatrix(int n){
    int top=0;
    int right=n-1;
    int left=0;
    int bottom=n-1;
    std::vector<std::vector<int>> c;
    std::vector<int> v;
    for(int i=0;i<n;i++){
        v.clear();
        for(int i=0;i<n;i++){
            v.push_back(0);
        }
        c.push_back(v);
    }
    int i=0;
    int d=0;
    while(top<=bottom&&left<=right){
        if(d%4==0){
            for(int j=left;j<=right;j++) {
                i++;
                c[top][j]=i;

            }
            top++;
        }
        else if(d%4==1){
            for(int j=top;j<=bottom;j++){
                i++;
                c[j][right]=i;

            }
            right--;
        }
        else if(d%4==2){
            for(int j=right;j>=left;j--){
                i++;
                c[bottom][j]=i;
            }
            bottom--;
        }
        else if(d%4==3){
            for(int j=bottom;j>=top;j--){
                i++;
                c[j][left]=i;
            }
            left++;
        }
        d++;
    }
    return c;
}

int main(){
    std::vector<std::vector<int>> a=generateMatrix(4);

    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout<<std::endl;
    }
    return 0;
}