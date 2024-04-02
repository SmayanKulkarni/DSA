void printascending(int n)
{
    if(n==0) return;
    printascending(n-1);
    cout<<n<<endl;
    return;
}