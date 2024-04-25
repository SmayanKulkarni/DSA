#include <bits/stdc++.h>
using namespace std;


int countvowles(string str, int i)
{
    if(i==0) return 0;
   
   
    if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'  )
    {
        return 1+countvowles(str,i-1);
    }
    else return countvowles(str,i-1);
}


int main()
{
    string a= "aeiioodsd";
    int len = a.length();
    int n = countvowles(a,len+1);
    cout<<n<<endl;
    
    cout<<endl;
    return 0;
}