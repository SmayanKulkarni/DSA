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
void printsubs(string input, string output, vector<string> v)
{
    if(input.length()==0)
    {
        v.push_back(output);
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
    vector<string> v;
    printsubs(input,output,v);
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<endl;
    }
    
    return 0;
}