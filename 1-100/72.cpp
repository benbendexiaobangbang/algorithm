//
// Created by dyf on 18-12-9.
//

#include <iostream>
#include<vector>

int minDistance(std::string word1, std::string word2) {
    std::vector<std::vector<int>> c;
    std::vector<int> v(word2.size()+1);
    for(int i=0;i<=word1.size();i++){
        c.push_back(v);
    }

    c[0][0]=0;
    for(int i=1;i<=word1.size();i++){
        c[i][0]=i;
    }
    for(int i=1;i<=word2.size();i++){
        c[0][i]=i;
    }
    for(int i=1;i<=word1.size();i++){
        for(int j=1;j<=word2.size();j++){
            int b=std::min((c[i-1][j-1]+(word1[i-1]==word2[j-1]?0:1)),c[i-1][j]+1);
            c[i][j]=std::min(b,c[i][j-1]+1);
        }
    }
    return c[word1.size()][word2.size()];
}

int main()
{
    std::string word1="intention";
    std::string word2="execution";
    std::cout<<minDistance(word1,word2)<<std::endl;
    return 0;
}