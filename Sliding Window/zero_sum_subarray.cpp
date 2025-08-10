#include <iostream>
#include <unordered_map>
#include <stdlib.h>
using namespace std;

int nsquarefunc(int arr[], int n)
{

    int total = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == 0)
            {
                total++;
            }
        }
    }
    return total;
}

int nfunc(int arr[], int n){

    long long int total = 0;
    unordered_map<long long int,long long int> m;

    long long int PrefixSum=0;

    m[0] = 1;

    for(int i =0;i<n;i++)
    {
        PrefixSum+=arr[i];
        if(m.count(PrefixSum))
        {
            total +=m[PrefixSum];
            m[PrefixSum]++;
        }
        else{
            m[PrefixSum] = 1;
        }
    }

    return total;
}
int main()
{

    int arr[] = {6, -1, -3, 4, -2, 2, 4, 6, -12, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The size of array is: \n"<< n << endl;

    int tot = nsquarefunc(arr, n);

    cout<< "The subarrays are: \n" << tot << endl;

    int tot2 = nfunc(arr, n);

    cout<< "The subarrays are: " << tot2 << endl;

    return 0;
}