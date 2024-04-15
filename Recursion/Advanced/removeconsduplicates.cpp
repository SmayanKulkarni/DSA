#include <bits/stdc++.h>

using namespace std;

void printsubs(string input, string output)
{
    if(input.length()==0)
    {
        cout<<output<<endl;
        return;
    }
    printsubs(input.substr(1),output+input[0]); //including
    printsubs(input.substr(1),output);//excluding
    
}

int main()
{
    string input;
    cin>>input;
    string output="";
    printsubs(input,output);
    
    return 0;
}