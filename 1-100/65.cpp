//
// Created by dyf on 18-11-29.
//

#include<iostream>
#include<string>

bool isNumber(std::string s) {
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ")+1);
    if(s.size()==0)
        return false;

    if(s.size()==1){
        if(s[0]=='.'||s[0]=='+'||s[0]=='-'||s[0]=='e')
            return false;
    }

    if(s.find_first_of(" ")!=-1)
        return false;

    if(s.find_first_of(".")!=s.find_last_of("."))
        return false;

    for(int i=0;i<s.size();i++){
        if((s[i]<'0'&&s[i]!='.'&&s[i]!='+'&&s[i]!='-')||(s[i]>'9'&&s[i]!='e'))
            return false;
        if((s[i]=='e')&&((i==1&&(s[0]=='+'||s[0]=='-'))||i==0||i==s.size()-1))
            return false;
    }

    if(s.find_first_of("e")!=s.find_last_of("e"))
        return false;

    if(s.find_first_of("+")!=s.find_last_of("+")&&(s[s.find_last_of("+")-1]!='e'))
        return false;

    if(s.find_first_of("-")!=s.find_last_of("-")&&(s[s.find_last_of("-")-1]!='e'))
        return false;

    if(s[0]=='e')
        return false;

    int a=s.find_first_of('.');
    if(s[a+1]=='e'&&a!=0)
        if(s.size()==a+1)
            return false;
    if(s[0]=='.'&&(s[1]=='e'))
        return false;

    if(s[0]=='+'||s[0]=='-') {
        if (s[1] == '.'&&( s[2]=='e'))
            return false;
    }

    int b=s.find_first_of('e');
    int c=s.find_first_of('.');
    if(b!=-1&&b<c)
        return false;

    c=s.find_first_of('+');

    if(b!=-1&&c+1==b)
        return false;

    c=s.find_first_of('-');

    if(b!=-1&&c+1==b)
        return false;

    if(s.find_first_of("+")!=-1)
        if(s.find_first_of("+")!=0)
            if(s.find_first_of("e")==-1)
                return false;

    if(s.find_first_of("-")!=-1)
        if(s.find_first_of("-")!=0)
            if(s.find_first_of("e")==-1)
                return false;

    if(s[s.size()-1]=='+'||s[s.size()-1]=='-')
        return false;

    if(s[0]=='+'||s[0]=='-'){
        if(s[1]=='.'&&s.size()==2)
            return false;
    }

    return true;
}

int main(){
    std::string s1=" 0.1 ";
    std::string s2="01";
    std::string s3="abc";
    std::string s4="1 a";
    std::string s5="+42e+76125";
    std::string s6="0 1";
    //std::cout<<isNumber(s1)<<std::endl;
    //std::cout<<isNumber(s2)<<std::endl;
    //std::cout<<isNumber(s3)<<std::endl;
    //std::cout<<isNumber(s4)<<std::endl;
    std::cout<<isNumber(s5)<<std::endl;
    //std::cout<<isNumber(s6)<<std::endl;
    return 0;
}