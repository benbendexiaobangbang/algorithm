//
// Created by dyf on 18-11-6.
//

//
// Created by dyf on 18-11-6.
//

#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

void solve(std::vector<std::vector<std::string>> &a,std::vector<std::vector<int>>b,std::vector<std::string> s,int n,int len){
    if(len==n){
        a.push_back(s);
        return;
    }
    std::string str="";
    int flag=0;
    for(int i=0;i<n;i++){
        std::vector<std::vector<int>>c=b;
        if(b[len][i]==1)
            str+=".";
        else if(b[len][i]==0){
            str+="Q";
            flag=1;
            c[len][i]=1;
            for(int k=i;k<n;k++)
            {
                c[len][k]=1;
            }
            for(int k=len;k<n;k++){
                c[k][i]=1;
            }
            for(int k=len+1,l=i+1;k<n&&l<n;k++,l++){
                c[k][l]=1;
            }
            for(int k=len+1,l=i-1;k<n&&l>=0;k++,l--){
                c[k][l]=1;
            }
            len++;
            for(int j=i+1;j<n;j++){
                str+=".";
            }
            s.push_back(str);
            solve(a,c,s,n,len);
            str=str.substr(0,i);
            str+=".";
            len--;
            s.pop_back();
        }
    }
    if(flag==0)
        return;
}

int totalNQueens(int n) {
    std::vector<std::vector<std::string>> a;
    std::vector<std::vector<int>>b(n,std::vector<int>(n));
    if(n==0)
        return 0;
    std::vector<std::string> s;
    solve(a,b,s,n,0);
    return a.size();
}

int main() {
    int n=1;
    std::cout<<totalNQueens(4)<<std::endl;
    return 0;
}