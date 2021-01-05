/*
problem link:https://leetcode.com/problems/merge-intervals/


Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

*/

#include<bits/stdc++.h>
using namespace std;
void merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergeIntervals;
        if(intervals.size()==0)
            return ;
        sort(intervals.begin(),intervals.end());
        vector<int> tempInterval=intervals[0];
        for(auto it:intervals){
            if(it[0]<=tempInterval[1]){
                tempInterval[1]=max(tempInterval[1],it[1]);
            }else{
                mergeIntervals.push_back(tempInterval);
                tempInterval=it;
            }
        }
        mergeIntervals.push_back(tempInterval);
        for(vector<int> i:mergeIntervals){
            for(int val:i){
                cout<<val<<" ";
                }
            cout<<"\n";
        }
}
int main(){
    vector<vector<int>> v={{1,3},{2,6},{8,10},{11,13},{15,18}};
    merge(v);
 return 0;   
}