#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void selectionsort(int a[], int n) // we use indexes instead of values since it doesnt allow creation of duplicates
{
    for (int i = 0; i <= n - 2; i++)
    {
        int smallest = i;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (a[i] > a[j])
            {
                smallest = j;
            }
        }
        if (a[i] > smallest)
        {
            swap(a[i], a[smallest]);
        }
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

    selectionsort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}