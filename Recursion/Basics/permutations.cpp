#include <iostream>
using namespace std;

void printpermu(char str[], int i=0)
{
    if(str[i] =='\0') 
    {
        cout<<str<<endl;
        return;
    }

    for(int j=i; str[j]!='\0'; j++) 
    {
        swap(str[i], str[j]);
        printpermu(str, i+1);
        swap(str[i], str[j]);
    }
}

int main()
{
    char str[] = "ABC";
    printpermu(str);
    return 0;

}