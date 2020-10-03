/*Fast Exponention using Bit Manipulation
Given two integers A and N, the task is to calculate
 A raised to power N (i.e. A^N).



*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pi (3.141592653589)
#define mod 1000000007
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


bool isPrime(int n){
    if(n==1) return false;
    if(n==2) return true;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}

int power(int a, int n) 
{ 
  
    // Stores final answer 
    int ans = 1; 
  
    while (n > 0) { 
  
        int last_bit = (n & 1); 
  
        // Check if current LSB 
        // is set 
        if (last_bit) { 
            ans = ans * a; 
        } 
  
        a = a * a; 
  
        // Right shift 
        n = n >> 1; 
    } 
  
    return ans; 
} 


int32_t main(){
fast
int a,n;
cin>>a>>n;
cout<<(power(a,n))<<"\n";;
return 0;
}
