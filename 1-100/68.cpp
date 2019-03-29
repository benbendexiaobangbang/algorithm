//
// Created by dyf on 18-11-30.
//

#include<iostream>
#include<vector>

std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
    std::vector<std::string> result;
    std::vector<std::string> d1;
    std::vector<std::vector<std::string>> d2;
    std::string s1="";
    int i=0;

    while(i!=words.size()) {
        s1="";
        d1.clear();
        while((words[i].size()+s1.size())<=maxWidth) {
            s1+=words[i];
            s1+=" ";
            d1.push_back(words[i]);
            i++;
        }
        d2.push_back(d1);
        result.push_back(s1);
    }

    std::string s2="";
    for(int i=0;i<result.size()-1;i++){
        s2="";
        result[i].erase(result[i].find_last_not_of(" ")+1);
        if(result[i].find_first_of(" ")==-1){
            int t1=result[i].size();
            for(int j=0;j<maxWidth-t1;j++)
            {
                result[i]+=" ";
            }
            continue;
        }

        int c=d2[i].size()-1;
        int d=maxWidth-result[i].size();
        int x1=d/c;
        int x2=d%c;

        s2=d2[i][0];
        for(int j=1;j<d2[i].size();j++)
        {
            if(j<x2+1){
                for(int k=0;k<x1+2;k++){
                    s2+=" ";
                }
            }
            else
            {
                for(int k=0;k<x1+1;k++){
                    s2+=" ";
                }
            }
            s2+=d2[i][j];
        }
        result[i]=s2;
    }

    result[result.size()-1].erase(result[result.size()-1].find_last_not_of(" ")+1);
    int t=result[result.size()-1].size();
    int d=maxWidth-t;

    for(int i=0;i<d;i++)
        result[result.size()-1]+=" ";

    return result;
}

int main()
{
    std::vector<std::string> words={"ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"
    };
    std::vector<std::string> retult=fullJustify(words,16);
    for(int i=0;i<retult.size();i++){
        std::cout<<retult[i]<<std::endl;
        std::cout<<retult[i].size()<<std::endl;
    }
}