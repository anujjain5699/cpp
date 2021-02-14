#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sort(vector<vector<int>>& mat,int row,int col,int m,int n){
        vector<int> v;
        int r=row,c=col;
        while(r<m && c<n){
            v.push_back(mat[r][c]);
            r++;
            c++;
        }
        std::sort(v.begin(),v.end());
        for(auto x:v){
            mat[row][col]=x;
            row++;
            col++;
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        for(int i=0;i<n;i++){
            sort(mat,0,i,m,n);
        }
        for(int j=1;j<m;j++){
            sort(mat,j,0,m,n);
        }
        return mat;
    }
};

int main(){
    int n,m;
    vector<vector<int>> v;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    Solution s;
    s.diagonalSort(v);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<<" ";
        }
    }
    return 0;
}