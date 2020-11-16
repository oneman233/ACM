#include <bits/stdc++.h>

using namespace std;

int f(int x)
{
    int ans=0;
    while(x!=0)
    {
        ans+=(x%10);
        x/=10;
    }
    return ans;
}

int g(int x)
{
    int ans=0;
    for(int i=0;i<18;i++)
    {
        if(x&(1<<i))
            ans++;
    }
    return ans;
}

int main()
{
    int n;
    int ans=0;
    cin>>n;
    /*if(n>=1000)
    {
        cout<<"13";
        return 0;
    }*/
    for(int i=1;i<=n;i++)
    {
        if(f(i)==g(i))
            ans++;
    }
    cout<<ans;
    return 0;
}
