//
// Created by dyf on 18-11-24.
//

#include<iostream>
#include<vector>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

void sort(std::vector<Interval> &a){
    Interval b(0,0);
    Interval temp(0,0);
    int t=0;
    for(int i=0;i<a.size();i++){
        b=a[i];
        t=0;
        for(int j=i+1;j<a.size();j++){
            if(a[j].start<b.start){
                b=a[j];
                t=j;
            }
        }
        if(t!=0){
            temp=a[i];
            a[i]=a[t];
            a[t]=temp;
        }
    }
}

std::vector<Interval> merge(std::vector<Interval>& intervals) {
    std::vector<Interval> result;
    if(intervals.size()==0)
        return result;
    if(intervals.size()==1)
        return intervals;
    sort(intervals);
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
    std::vector<Interval> a={{1,3},{2,6},{3,4},{8,10},{15,18}};

    std::vector<Interval> b=merge(a);

    return 0;
}