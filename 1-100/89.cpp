//
// Created by dyf on 18-12-15.
//

#include<iostream>
#include<vector>
#include<algorithm>

void code(std::vector<int> &dd,std::vector<std::string> &aa,int &d){
    int c=1;
    while(c!=d){
        std::string ss=aa.back();
        std::string ss1=ss;
        int flag=0;
        for(int i=0;i<ss.size();i++) {
            flag = 0;
            ss1 = ss;
            if (ss[i] == '1')
                ss1[i] = '0';
            else
                ss1[i] = '1';
            int f = 0;
            for (int j = 0; j < aa[0].size(); j++) {
                if (ss1[j] == '1')
                    f += 1 << (ss1.size() - 1 - j);
            }
            for (int i = 0; i < dd.size(); i++) {
                if (dd[i] == f) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                aa.push_back(ss1);
                dd.push_back(f);
                c++;
                break;
            }
        }
    }
}

std::vector<int> grayCode(int n) {
    std::vector<int> dd;
    std::vector<std::string> aa;
    int c=1;
    c=c<<n;
    std::string str="";
    for(int i=0;i<n;i++){
        str=str+"0";
    }
    aa.push_back(str);
    dd.push_back(0);
    code(dd,aa,c);
    return dd;
}

int main()
{
    int n=2;
    std::vector<int>a=grayCode(10);
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++){
        std::cout<<a[i]<<" ";
    }
    std::cout<<std::endl;
}