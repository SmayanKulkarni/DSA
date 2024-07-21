#include <bits/stdc++.h>

using namespace std;

vector<int> removeduplicates(int *a, int n)
{

    vector<int> output;
    unordered_map<int, bool> mymap;
    for (int i = 0; i < n; i++)
    {
        if (mymap.count(a[i]) == 0)
        {
            output.push_back(a[i]);
            mymap[a[i]] = true;
        }
    }
    return output;
}

int main()
{
    int a[] = {1,2,4,5,6,2,3,1,2};
    vector<int> output = removeduplicates(a, 9);
    for(int i = 0;i<output.size();i++) cout<<output[i]<<endl;
    return 0; //comment
}
