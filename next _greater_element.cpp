/*
Next Greater Element

Given an array, print the Next Greater Element (NGE) for every element. 
The Next greater Element for an element x is the first greater element on the right side of x in the array. 
Elements for which no greater element exist, consider the next greater element as -1.
Time Complexity: O(n) 
Auxiliary Space: O(n)
 */

#include <bits/stdc++.h>
using namespace std;
void printNGE(int arr[], int n)
{
    stack<int> st;
    vector<int> v;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && st.top()<=arr[i])
        st.pop();
        if(st.empty()){
        v.push_back(-1);}
        else{
        v.push_back(st.top());
        }
        st.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; i++)
        cout << v[i] <<" ";
}
int main()
{
    int arr[] = { 11, 13, 21, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}