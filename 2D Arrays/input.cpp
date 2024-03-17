#include <iostream>

using namespace std;

int main()
{   

    int rarr[100][100];
    int m,n;
    cin>>m>>n;
    

    //input
    for(int i = 0; i <m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>> rarr[i][j];
        }
    }
    //rowwise output
    for(int i = 0; i <m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<rarr[i][j]<<" ";
        }
        cout<<endl;
    }
    // columnwise output
   
    for(int i = 0; i <n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<rarr[j][i]<<" ";
        }
        cout<<endl;
    }


    return 0;
}