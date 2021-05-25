/**
Untitled-1487 Max Consecutive Ones III
Problem:
Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most k 0's.

Example 1:

Input: [1,0,1,1,0] ,k=2
Output: 6

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000

 */

#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> a,int k){
    int count_zeroes=0,ans=0,j=-1;
    for(int i=0;i<a.size();i++){
        if(a[i]==0){
            count_zeroes++;
        }
        while(count_zeroes > k){
            j++;
            if(a[j]==0)
            count_zeroes--;
        }
        if((i-j)>ans)
        ans=i-j;
    }
    return ans;
}

int main(){
    vector<int> a={1,1,0,1,0,0,1,1,0,1,0,1,1,1,0,0,1,1,1};
    int k=3;
    cout<<findMaxConsecutiveOnes(a,k)<<endl;
    return 0;
}