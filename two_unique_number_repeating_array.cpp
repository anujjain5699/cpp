#include <bits/stdc++.h>
using namespace std;
int checksetbit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}
void unique(int a[], int n)
{
    int exor = 0;
    for (int i = 0; i < n; i++)
        exor = exor ^ a[i];

    int tempxor = exor;
    int setbit = 0;
    int pos = 0;
    while (setbit != 1)
    {
        setbit = exor & 1;
        pos++;
        exor = exor >> 1;
    }
    int newxor = 0;
    for (int i = 0; i < n; i++)
    {
        if (checksetbit(a[i], pos - 1))
        {
            newxor = newxor ^ a[i];
        }
    }
    cout << newxor << " ";
    cout << (tempxor ^ newxor) << " ";
}
int main()
{
    int a[] = {1, 2, 3, 1, 2, 3, 5, 7};
    unique(a, 8);
    return 0;
}