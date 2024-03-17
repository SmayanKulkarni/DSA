#include <iostream> 

using namespace std;

int length(char input[])

{
    int count = 0;
    for(int i=0; input[i]!= '\0'; i++)
    {
        count++;
    }
    return count;
}
int main()
{
    char s[100];
    cin.getline(s, 100);


    int start = 0;
    int end  = length(s) - 1;

    while(start < end)
    {
        swap(s[start], s[end]);
        start++;
        end--;  
    }

    cout << s << endl;
    
        return 0;
}