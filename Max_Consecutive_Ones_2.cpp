/**
Untitled-1487 Max Consecutive Ones II
Problem:
Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.

Example 1:

Input: [1,0,1,1,0]
Output: 4
Explanation: Flip the first zero will get the the maximum number of consecutive 1s.
    After flipping, the maximum number of consecutive 1s is 4.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000

 */

#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> a){
    int count_zeroes=0,ans=0,j=-1;
    for(int i=0;i<a.size();i++){
        if(a[i]==0){
            count_zeroes++;
        }
        while(count_zeroes > 1){
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
    cout<<findMaxConsecutiveOnes(a)<<endl;
    return 0;
}