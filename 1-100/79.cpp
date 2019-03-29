//
// Created by dyf on 18-12-9.
//

#include<iostream>
#include<vector>
#include<map>

bool find(std::vector<std::vector<char>>& board,std::string word,int i,int j,int t,std::vector<int>&m1,
          std::vector<int>&n1,std::vector<std::vector<int>> &c){
    if(i-1>=0){
        if(board[i-1][j]==word[t]&&c[i-1][j]==0) {
            if (t == word.size()-1)
                return true;
            else {
                m1.push_back(i-1);
                n1.push_back(j);
                c[i - 1][j] = 1;
                if(find(board, word, i - 1, j, t + 1,m1,n1,c))
                    return true;
                m1.pop_back();
                n1.pop_back();
                c[i-1][j]=0;
            }
        }
    }
    if(j-1>=0){
        if(board[i][j-1]==word[t]&&c[i][j-1]==0) {
            if (t == word.size()-1)
                return true;
            else {
                m1.push_back(i);
                n1.push_back(j-1);
                c[i][j-1] = 1;
                if(find(board, word, i, j-1, t + 1,m1,n1,c))
                    return true;
                m1.pop_back();
                n1.pop_back();
                c[i][j-1]=0;
            }
        }
    }
    if(j+1<board[0].size())
    {
        if(board[i][j+1]==word[t]&&c[i][j+1]==0) {
            if (t == word.size()-1)
                return true;
            else {
                m1.push_back(i);
                n1.push_back(j+1);
                c[i][j+1] = 1;
                if(find(board, word, i, j+1, t + 1,m1,n1,c))
                    return true;
                m1.pop_back();
                n1.pop_back();
                c[i][j+1]=0;
            }
        }
    }
    if(i+1<board.size()){
        if(board[i+1][j]==word[t]&&c[i+1][j]==0) {
            if (t == word.size()-1)
                return true;
            else {
                m1.push_back(i+1);
                n1.push_back(j);
                c[i+1][j] = 1;
                if(find(board, word, i + 1, j, t + 1,m1,n1,c))
                    return true;
                m1.pop_back();
                n1.pop_back();
                c[i+1][j]=0;
            }
        }
    }
    c[i][j]=0;
    return false;
}

bool exist(std::vector<std::vector<char>>& board, std::string word) {
    if(board.size()==0)
        return false;
    std::vector<int> m;
    std::vector<int> n;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]==word[0]) {
                m.push_back(i);
                n.push_back(j);
            }
        }
    }
    std::vector<std::vector<int>> c;
    std::vector<int> v(board[0].size());
    for(int i=0;i<board.size();i++)
        c.push_back(v);
    if(m.size()==0)
        return false;
    if(word.size()==1)
        return true;
    for(int k=0;k<m.size();k++){
        int i=m[k];
        int j=n[k];
        c[i][j]=1;
        std::vector<int> m1;
        std::vector<int> n1;
        m1.push_back(i);
        n1.push_back(j);
        if(find(board,word,i,j,1,m1,n1,c))
            return true;
        else
            c[i][j]=0;
    }
    return false;
}

int main()
{
    std::vector<std::vector<char>> board = {
            {'C','A','A'},
            {'A','A','A'},
            {'B','C','D'}
    };
    std::cout<<exist(board,"AAB")<<std::endl;
}