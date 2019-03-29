//
// Created by dyf on 18-10-27.
//

//
// Created by dyf on 18-10-26.
//

#include <iostream>
#include <vector>
#include<stack>
#include <string>
#include <limits.h>
#include<algorithm>

int longestValidParentheses(std::string s) {
    std::stack<int>sta;
    int max=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==')'&&!sta.empty()&&s[sta.top()]=='('){
            sta.pop();
            if(sta.empty()){
                max=i+1;
            }
            else if(max<i-sta.top())
            {
                max=i-sta.top();
            }
        }else
        {
            sta.push(i);
        }
    }
    return max;
}

int main() {
    std::string ss=")()())";
    std::cout<<longestValidParentheses(ss)<<std::endl;
    return 0;
}
