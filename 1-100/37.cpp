//
// Created by dyf on 18-11-7.
//
#include <iostream>
#include <vector>
#include<map>
#include <string>
#include <limits.h>
//#include<algorithm>
//bool isValidSudoku(std::vector<std::vector<char>>& board) {
//    std::vector<char> a;
//    std::vector<char> b;
//    std::vector<char> c;
//    for(int i=0;i<9;i++){
//        a.clear();
//        b.clear();
//        for(int j=0;j<9;j++){
//            if(board[j][i]>='0'&&board[j][i]<='9'){
//                if(b.size()==0)
//                    b.push_back(board[j][i]);
//                else{
//                    for(int k=0;k<b.size();k++)
//                    {
//                        if(board[j][i]==b[k])
//                            return false;
//                    }
//                    b.push_back(board[j][i]);
//                }
//            }
//            if(board[i][j]>='0'&&board[i][j]<='9'){
//                if(a.size()==0)
//                    a.push_back(board[i][j]);
//                else{
//                    for(int k=0;k<a.size();k++)
//                    {
//                        if(board[i][j]==a[k])
//                            return false;
//                    }
//                    a.push_back(board[i][j]);
//                }
//            }
//        }
//    }
//    for(int c=0;c<3;c++)
//    {
//        a.clear();
//        for(int i=3*c;i<3*c+3;i++){
//            for(int j=0;j<3;j++){
//                if(board[i][j]>='0'&&board[i][j]<='9'){
//                    if(a.size()==0)
//                        a.push_back(board[i][j]);
//                    else{
//                        for(int k=0;k<a.size();k++)
//                        {
//                            if(board[i][j]==a[k])
//                                return false;
//                        }
//                        a.push_back(board[i][j]);
//                    }
//                }
//            }
//        }
//        a.clear();
//        for(int i=3*c;i<3*c+3;i++){
//            for(int j=3;j<6;j++){
//                if(board[i][j]>='0'&&board[i][j]<='9'){
//                    if(a.size()==0)
//                        a.push_back(board[i][j]);
//                    else{
//                        for(int k=0;k<a.size();k++)
//                        {
//                            if(board[i][j]==a[k])
//                                return false;
//                        }
//                        a.push_back(board[i][j]);
//                    }
//                }
//            }
//        }
//        a.clear();
//        for(int i=3*c;i<3*c+3;i++){
//            for(int j=6;j<9;j++){
//                if(board[i][j]>='0'&&board[i][j]<='9'){
//                    if(a.size()==0)
//                        a.push_back(board[i][j]);
//                    else{
//                        for(int k=0;k<a.size();k++)
//                        {
//                            if(board[i][j]==a[k])
//                                return false;
//                        }
//                        a.push_back(board[i][j]);
//                    }
//                }
//            }
//        }
//    }
//    return true;
//}
bool isValid(std::vector<std::vector<char>>& board,int row,int col,char c)
{
    for(int i=0;i<9;i++){
        if(board[row][i]==c)return false;
        if(board[i][col]==c)return false;
    }
    int r1=row/3;
    int l1=col/3;
    for(int j=0;j<3;j++){
        for(int k=0;k<3;k++){
            if(board[3*r1+j][3*l1+k]==c)
                return false;
        }
    }
    return true;
}

bool solve(std::vector<std::vector<char>>& board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                for(char c='1';c<='9';c++){
                    if(isValid(board,i,j,c)){
                        board[i][j]=c;
                        if(solve(board))return true;
                        else board[i][j]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool solve1(std::vector<std::vector<char>> &board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                for(char c='1';c<='9';c++){
                    if(isValid(board,i,j,c)){
                        board[i][j]=c;
                        if(solve1(board))return true;
                        else
                            board[i][j]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(std::vector<std::vector<char>>& board) {
    solve1(board);
    std::cout<<std::endl;
}

int main() {
    std::vector<std::vector<char>> a;
    a.push_back({'5','3','.','.','7','.','.','.','.'});
    a.push_back({'6','.','.','1','9','5','.','.','.'});
    a.push_back({'.','9','8','.','.','.','.','6','.'});
    a.push_back({'8','.','.','.','6','.','.','.','3'});
    a.push_back({'4','.','.','8','.','3','.','.','1'});
    a.push_back({'7','.','.','.','2','.','.','.','6'});
    a.push_back({'.','6','.','.','.','.','2','8','.'});
    a.push_back({'.','.','.','4','1','9','.','.','5'});
    a.push_back({'.','.','.','.','8','.','.','7','9'});
    solveSudoku(a);
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            std::cout<<a[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}

