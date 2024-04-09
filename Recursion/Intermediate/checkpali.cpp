#include <bits/stdc++.h>
using namespace std;

bool checkpali(int a[], int s, int e)
{
    if (s > e)
    {
        return true;
    }
    if (a[s] == a[e])
    {
        return checkpali(a, s + 1, e - 1);
    }
    else
    {
        return false;
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << checkpali(a, 0, n - 1) << endl;
    return 0;
}