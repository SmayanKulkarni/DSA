#include <iostream>

using namespace std;

int main()
{
    cout << "Enter the number of elements" << endl;
    int n;
    cin >> n; // to accept the input from user
    int a[n];
    cout << "Enter the elements of the array: " << endl;
    int sum=0;
    for( int i = 0;i<n;i++ )
    {
        cin>>a[i];
    }
    for( int i = 0;i<n;i++ )
    {
        sum = sum+a[i];
    }
    cout << "The sum of the array is: " << sum << endl;
    return 0;
}