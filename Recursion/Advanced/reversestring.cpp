#include <iostream>
#include <string>
using namespace std;

void revstring(string &s, int st, int e)
{
    if(st>=e) 
    {
        
        return;
    }
    swap(s[st],s[e]);
    revstring(s,st+1, e-1);
    
}

int main()
{
    string a;
    cin>>a;
      int len = a.length();
    revstring(a,0,len-1);
    cout<<a<<endl;
    return 0;
}