int power(int a,int b)
{
    int ans = 1;
    while(b>=0)
    {
        ans*=a;
        b--;
    } 
    return ans;
}