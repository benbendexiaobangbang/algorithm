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
    std::stack<int> ss1;
    std::stack<char> ss2;
    std::stack<char> ss3;
    std::vector<int> q1;
    std::vector<int> q2;
    int len = s.size();
    int n = 0;
    int max2 = 0;
    int t1 = INT_MAX;
    int t2 = 0;
    int s1 = 0;
    int s2 = 0;
    for (int j = 0; j < len; j++) {
        if (s[j] == '(') {
            ss1.push(j);
            ss2.push(s[j]);
        } else if (s[j] == ')') {
            if (!ss2.empty()) {
                n = n + 2;
                if (t1 > ss1.top())
                    t1 = ss1.top();
                t2 = j;
                ss1.pop();
                ss2.pop();
            } else {
                if (max2 < n) {
                    max2 = n;
                    s1 = t1;
                    s2 = t2;
                    q1.push_back(s1);
                    q2.push_back(s2);
                }
                t1 = j + 1;
                n = 0;
                continue;
            }
        }
    }
    if (max2 < n) {
        s1 = t1;
        s2 = t2;
        q1.push_back(s1);
        q2.push_back(s2);
    }
    max2 = 0;
    while (!q1.empty()) {
        int s1 = q1.back();
        q1.pop_back();
        int s2 = q2.back();
        q2.pop_back();
        n = 0;
        for (int j = s2; j >= s1; j--) {
            if (s[j] == ')') {
                ss3.push(s[j]);
            } else if (s[j] == '(') {
                if (!ss3.empty()) {
                    n = n + 2;
                    ss3.pop();
                } else {
                    if (max2 < n) {
                        max2 = n;
                    }
                    n = 0;
                    continue;
                }
            }
        }
        if (max2 < n)
            max2 = n;
    }
    return max2;
}

int main() {
    std::string ss="(((((()()())()())(((()))()(((()(())(((()()((()))))))))))())))()(((((()))(())))(((()))(()()()(()(((()))()))((()())(((())(((((()(()()(()())(())(((()()(()(())())(((()()))())()(()()())";
    std::cout<<longestValidParentheses(ss)<<std::endl;
    return 0;
}
