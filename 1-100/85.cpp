//
// Created by dyf on 18-12-13.
//
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//int maximalRectangle(std::vector<std::vector<char>>& matrix) {
//    if(matrix.empty())
//        return 0;
//    int width=matrix[0].size();
//    int height=matrix.size();
//
//    int max=0;
//    for(int i=0;i<height;i++){
//        for(int j=0;j<width;j++){
//            int max1=0;
//            int w1=0;
//            for(int k=j;k<width;k++){
//                if(matrix[i][k]=='1')
//                    w1++;
//                else
//                    break;
//            }
//            max1=w1;
//            if(w1==0)
//                continue;
//            int flag=0;
//            for(int l=i+1;l<height;l++){
//                int k=j;
//                for(;k<j+w1;k++){
//                    if(matrix[l][k]=='0'){
//                        w1=(k-j);
//                        if((l-i+1)*w1>max1){
//                            max1=(l-i+1)*w1;
//                        }
//                        break;
//                    }
//                }
//                if(k==j+w1){
//                    if((l-i+1)*w1>max1) {
//                        max1=(l-i+1)*w1;
//                    }
//                }
//            }
//            if(max<max1)
//                max=max1;
//        }
//    }
//    return max;
//}

//int MaxArea(vector<int>& heights) {
//    int res=0;
//    int cur=0;
//    stack<int> st;
//    heights.push_back(0);
//    for(int i=0;i<heights.size();i++){
//        while(!st.empty()&&heights[st.top()]>=heights[i]){
//            cur=st.top();
//            st.pop();
//            res=max(res,heights[cur]*(st.empty()?i:(i-st.top()-1)));
//        }
//        st.push(i);
//    }
//    return res;
//}
int MaxArea(std::vector<int>& heights) {
    if(heights.size()==0)
        return 0;
    int maxArea=0;
    for(int i=0;i<heights.size();i++){
        if(i+1<heights.size()&&heights[i]<=heights[i+1])
            continue;
        int minH=heights[i];
        int area=0;
        for(int j=i;j>=0;j--){
            minH=std::min(minH,heights[j]);
            area=minH*(i-j+1);
            maxArea=std::max(maxArea,area);
        }
    }
    return maxArea;
}

//int MaxArea(vector<int> &row){
//    int maxArea=0;
//
//    row.push_back(0);
//    stack<int> indexs;
//    indexs.push(-1);
//    for(int i=0;i<row.size();i++){
//        int index;
//        while(indexs.size()>1&&(index=indexs.top(),row[i]<=row[index])){
//            indexs.pop();
//            maxArea=max(maxArea,(row[index])*(i-indexs.top()-1));
//        }
//        indexs.push(i);
//    }
//
//    return maxArea;
//}
//
////
////int MaxArea(vector<char> &row){
////    int maxArea=0;
////    row.push_back('0');
////    stack<int> st;
////    for(int i=0;i<row.size();i++){
////        while(!st.empty()&&row[st.top()]>=row[i]) {
////            int cur = st.top();
////            st.pop();
////            maxArea = max(maxArea, (row[cur] - '0') * (st.empty() ? i : i - st.top() - 1));
////        }
////        st.push(i);
////    }
////    return maxArea;
////}
//
//int maximalRectangle(vector<vector<char>>& matrix) {
//    if(matrix.empty())
//        return 0;
//
//    std::vector<std::vector<int>> a;
//    std::vector<int> v(matrix[0].size());
//    int maxArea=0;
//    a.push_back(v);
//    for(int j=0;j<matrix[0].size();j++){
//        if(matrix[0][j]=='1')
//            a[0][j]=1;
//    }
//    maxArea=max(maxArea,MaxArea(a[0]));
//    for(int i=1;i<matrix.size();i++){
//        a.push_back(v);
//        for(int j=0;j<matrix[0].size();j++){
//            if(matrix[i][j]=='1')
//                a[i][j]=1+a[i-1][j];
//        }
//        maxArea=max(maxArea,MaxArea(a[i]));
//    }
//
//    return maxArea;
//}

//int largestRectangleArea(vector<int> &height) {
//    int res = 0; stack<int> s;
//    height.push_back(0);
//    for (int i = 0; i < height.size(); ++i) {
//        if (s.empty() || height[s.top()] <= height[i])
//            s.push(i);
//        else {
//            int tmp = s.top();
//            s.pop();
//            res = max(res, height[tmp] * (s.empty() ? i : (i - s.top() - 1)));
//            --i; }
//    } return res;
//}
int maximalRectangle(vector<vector<char>>& matrix) {
    int res = 0;
    vector<int> height; //它这里是按行进行压缩
    for (int i = 0; i < matrix.size(); ++i) {
        height.resize(matrix[i].size());
        for (int j = 0; j < matrix[i].size(); ++j) {
            height[j] = matrix[i][j] == '0' ? 0 : (1 + height[j]);
        }
        res = max(res, MaxArea(height));
    }
    return res;
}

int main() {
   std::vector<std::vector<char>> a={
//                           {'1','1','1','1','1','1','1','1'},
//                           {'1','1','1','1','1','1','1','0'},
//                           {'1','1','1','1','1','1','1','0'},
//                           {'1','1','1','1','1','0','0','0'},
//                           {'0','1','1','1','1','0','0','0'}
//                                     }; //={
//           {'1', '0', '1', '0', '0'},
//           {'1', '0', '1', '1', '1'},
//           {'1', '1', '1', '1', '1'},
//           {'1', '0', '0', '1', '0'}
//            {}
           {'1'}

    };
    std::cout<<maximalRectangle(a)<<std::endl;
    return 0;
}
