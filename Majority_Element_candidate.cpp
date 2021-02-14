/*

https://leetcode.com/problems/majority-element/
*/

#include<bits/stdc++.h>
using namespace std;
class Majority_Element_candidate {
public:
    int majorityElement(vector<int>& nums) {
        int maj=0,count=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[maj])count++;
            else
            {
                count--;
                if(count==0)
                {
                    maj=i;
                    count=1;
                }
            }
        }
        return nums[maj];
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    Majority_Element me;
    int nn=me.majorityElement(v);
    cout<<nn;
    return 0;  
}
