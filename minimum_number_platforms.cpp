//Minimum Number of Platforms Required
#include<bits/stdc++.h>
using namespace std;
int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);
    int plat_needed = 1, result = 1;
    int i = 1, j = 0;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j]) {
            plat_needed++;
            i++;
        }
        else if (arr[i] > dep[j]) {
            plat_needed--;
            j++;
        }
        if (plat_needed > result)
            result = plat_needed;
    }
    return result;
}
int findPlatform_multimap(int *a,int *d,int n)
{
    multimap<int,char> m;
    for(int i=0;i<n;i++)
    {
        m.insert(pair<int,char>(a[i],'a'));
        m.insert(pair<int,char>(d[i],'d'));
    }
    int result = 0;
    int plat_needed = 0;
    multimap<int, char>::iterator i = m.begin();
    for(;i!=m.end();i++)
    {
        if((*i).second=='a')plat_needed++;
        else plat_needed--;
        if(plat_needed>result)result = plat_needed;
    }
    return result;
}
int main()
{
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum Number of Platforms Required = "<<findPlatform(arr, dep, n)<<endl;
    cout << "Minimum Number of Platforms Required using multimap= "<<findPlatform_multimap(arr, dep, n)<<endl;
    return 0;
}