//
// Created by dyf on 18-11-25.
//

#include<iostream>
#include<vector>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

std::vector<Interval> insert(std::vector<Interval>& intervals, Interval newInterval) {
    std::vector<Interval> result;
    if(intervals.size()==0){
        result.push_back(newInterval);
        return result;
    }
    int j=0;
    for(;j<intervals.size();j++){
        if(newInterval.start<=intervals[j].start){
            intervals.insert(intervals.begin()+j,newInterval);
            break;
        }
    }
    if(j==intervals.size())
        intervals.insert(intervals.begin()+j,newInterval);
    int i=1;
    Interval a=intervals[0];
    while(i!=intervals.size()){
        if(a.end<intervals[i].start) {
            result.push_back(a);
            a=intervals[i];
        }else if(a.end>=intervals[i].start&&a.end<intervals[i].end){
            a.end=intervals[i].end;
        }
        i++;
    }
    result.push_back(a);
    return result;
}

int main(){
    std::vector<Interval> a={{1,5}};
    Interval c={2,7};
    std::vector<Interval> b=insert(a,c);

    return 0;
}
