//
// Created by dyf on 18-12-11.
//

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//int largestRectangleArea(std::vector<int>& heights) {
//    if(heights.size()==0)
//        return 0;
//    int max=0;
//    for(int i=0;i<heights.size();i++){
//        int c=heights[i];
//        for(int j=i+1;j<heights.size();j++){
//            if(heights[i]>heights[j])
//                break;
//            else if(heights[i]<=heights[j])
//                c=c+heights[i];
//        }
//        for(int j=i-1;j>=0;j--){
//            if(heights[i]>heights[j])
//                break;
//            else if(heights[i]<=heights[j])
//                c=c+heights[i];
//        }
//        if(c>max)
//            max=c;
//    }
//    return max;
//}
//
//int largestRectangleArea(std::vector<int>& heights) {
//    if(heights.size()==0)
//        return 0;
//    int maxArea=0;
//    for(int i=0;i<heights.size();i++){
//        if(i+1<heights.size()&&heights[i]<=heights[i+1])
//            continue;
//        int minH=heights[i];
//        int area=0;
//        for(int j=i;j>=0;j--){
//            minH=std::min(minH,heights[j]);
//            area=minH*(i-j+1);
//            maxArea=std::max(maxArea,area);
//        }
//    }
//    return maxArea;
//}

//int largestRectangleArea(vector<int>& heights) {
//             int res = 0;
//             stack<int> st;
//             heights.push_back(0);
//             for (int i = 0; i < heights.size(); ++i) {
//                     while (!st.empty() && heights[st.top()] >= heights[i]) {
//                             int cur = st.top(); st.pop();
//                             res = max(res, heights[cur] * (st.empty() ? i : (i - st.top() - 1)));
//                         }
//                     st.push(i);
//                 }
//             return res;
//}


int largestRectangleArea(vector<int>& heights) {
    int res=0;
    int cur=0;
    stack<int> st;
    heights.push_back(0);
    for(int i=0;i<heights.size();i++){
        while(!st.empty()&&heights[st.top()]>=heights[i]){
            cur=st.top();
            st.pop();
            res=max(res,heights[cur]*(st.empty()?i:(i-st.top()-1)));
        }
        st.push(i);
    }
    return res;
}


int main()
{
    std::vector<int> heights={2,1,4,6,8,10};
    std::cout<<largestRectangleArea(heights)<<std::endl;
    return 0;
}