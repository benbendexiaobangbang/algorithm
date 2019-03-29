//
// Created by dyf on 18-12-1.
//

#include<iostream>
#include<vector>

//std::string simplifyPath(std::string path) {
//    std::string path1="";
//    std::string path2="";
//    while(path.find_first_of('.')!=-1)
//    {
//        int d=path.find_first_of('.');
//        if(path[d+1]=='.'&&(path[d+2]=='/'||path.size()==d+2)){
//            path1=path.substr(0,d);
//            path2=path.substr(d+2);
//            d=path1.find_last_not_of('/');
//            if(d==-1){
//                path=path1+path2;
//            }
//            else{
//                path1=path1.substr(0,d);
//                d=path1.find_last_of('/');
//                path1=path1.substr(0,d);
//                path=path1+path2;
//            }
//        }else if(path[d+1]=='/'||path.size()==d+1)
//        {
//            path1=path.substr(d+1);
//            path2=path.substr(0,d);
//            path=path2+path1;
//        }
//        else
//            break;
//    }
//
//    int d=path.size();
//    std::string s="";
//    int flag=0;
//    for(int i=0;i<d;i++){
//        if(path[i]=='/'){
//            if(flag==0) {
//                s+="/";
//                flag = 1;
//            }
//        }
//        else{
//            s += path[i];
//            flag=0;
//        }
//    }
//
//
//
//    if(s.find_last_of('/')==s.size()-1&&s.size()!=1)
//    {
//        int d=s.find_last_of('/');
//        s=s.substr(0,s.size()-1);
//    }
//    return s;
//}

std::string simplifyPath(std::string path) {
    std::vector<std::string> words;
    std::vector<std::string> words1;
    int i=0;
    std::string ss="";
    int d=path.find_first_of("/");
    path=path.substr(1);
    while(i!=path.size())
    {
        if(path[i]!='/'){
            ss+=path[i];
        }
        else
        {
            if(ss.size()!=0) {
                words.push_back(ss);
                ss = "";
            }
        }
        i++;
    }
    if(ss.size()!=0) {
        words.push_back(ss);
    }

    for(int i=0;i<words.size();i++){
        if(words[i]!="."&&words[i]!=".."){
            words1.push_back(words[i]);
        }
        if(words[i]==".."){
            if(words1.size()!=0){
                words1.pop_back();
            }
        }
    }

    ss="/";
    if(words1.size()==0)
        return ss;
    for(int i=0;i<words1.size()-1;i++){
        ss+=words1[i];
        ss+="/";
    }
    ss+=words1[words1.size()-1];

    return ss;
}

int main()
{
    std::string path="/...";
    std::cout<<simplifyPath(path)<<std::endl;
}