#include <bits/stdc++.h>

using namespace std;

void remove(char a[], char x)
{
    if(a[0] == '\0'){
        return;
    }
    if(a[0] !=x) {
        remove(a+1,x);
    }
    else {
        for(int i=0; a[i]!='\0'; i++) {
            a[i]=a[i+1];
        }
         remove(a,x);
}  }

int main()
{
    char a[10];
    cin>>a;
    cout<<"Before Replacement: "<<a<<endl;
    cout<<"After Replacement: ";
    remove(a,'a');
    cout<<"After Replacement: "<<a<<endl;

    return 0;
}