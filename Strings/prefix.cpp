#include <iostream>
#include <cstring> 

using namespace std;


void suff(char str[])
{
    for(int e=0;e<strlen(str);e++)
    {
        for(int s=0;s<=e;s++) 
        {
        cout<< str[s];
        }
        cout<<endl;
    }
    
}
int main()
{
    char str[] = "abcd";
    suff(str);
    return 0;

}