//
// Created by dyf on 18-10-27.
//

#include <iostream>
#include <vector>
#include<map>
#include <string>
#include <limits.h>
#include<algorithm>
bool isValidSudoku(std::vector<std::vector<char>>& board) {
    std::vector<char> a;
    std::vector<char> b;
    std::vector<char> c;
    for(int i=0;i<9;i++){
        a.clear();
        b.clear();
        for(int j=0;j<9;j++){
            if(board[j][i]>='0'&&board[j][i]<='9'){
                if(b.size()==0)
                    b.push_back(board[j][i]);
                else{
                    for(int k=0;k<b.size();k++)
                    {
                        if(board[j][i]==b[k])
                            return false;
                    }
                    b.push_back(board[j][i]);
                }
            }
            if(board[i][j]>='0'&&board[i][j]<='9'){
                 if(a.size()==0)
                    a.push_back(board[i][j]);
                else{
                    for(int k=0;k<a.size();k++)
                    {
                        if(board[i][j]==a[k])
                            return false;
                    }
                    a.push_back(board[i][j]);
                }
            }
        }
    }
    for(int c=0;c<3;c++)
    {
        a.clear();
        for(int i=3*c;i<3*c+3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]>='0'&&board[i][j]<='9'){
                    if(a.size()==0)
                        a.push_back(board[i][j]);
                    else{
                        for(int k=0;k<a.size();k++)
                        {
                            if(board[i][j]==a[k])
                                return false;
                        }
                        a.push_back(board[i][j]);
                    }
                }
            }
        }
        a.clear();
        for(int i=3*c;i<3*c+3;i++){
            for(int j=3;j<6;j++){
                if(board[i][j]>='0'&&board[i][j]<='9'){
                    if(a.size()==0)
                        a.push_back(board[i][j]);
                    else{
                        for(int k=0;k<a.size();k++)
                        {
                            if(board[i][j]==a[k])
                                return false;
                        }
                        a.push_back(board[i][j]);
                    }
                }
            }
        }
        a.clear();
        for(int i=3*c;i<3*c+3;i++){
            for(int j=6;j<9;j++){
                if(board[i][j]>='0'&&board[i][j]<='9'){
                    if(a.size()==0)
                        a.push_back(board[i][j]);
                    else{
                        for(int k=0;k<a.size();k++)
                        {
                            if(board[i][j]==a[k])
                                return false;
                        }
                        a.push_back(board[i][j]);
                    }
                }
            }
        }
    }
    return true;
}
int main() {
    std::vector<std::vector<char>> a;
    a.push_back({'8','.','3','.','.','.','.','.','.'});
    a.push_back({'.','.','.','.','.','.','.','2','.'});
    a.push_back({'.','1','.','.','.','.','.','7','.'});
    a.push_back({'1','.','.','.','.','.','.','.','3'});
    a.push_back({'.','.','.','.','.','2','.','.','.'});
    a.push_back({'.','.','.','.','.','3','.','.','.'});
    a.push_back({'.','.','.','.','6','.','.','.','.'});
    a.push_back({'9','.','.','.','.','.','6','.','.'});
    a.push_back({'.','.','1','.','.','4','.','.','.'});
    std::cout<<isValidSudoku(a)<<std::endl;
    return 0;
}
