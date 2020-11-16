#include <bits/stdc++.h>

using namespace std;

int n,m;
int pre[1005];
int find(int i)
{
    if(pre[i]==i)
        return i;
    else
        find(pre[i]);
}

int main()
{
    int a,b;
    int ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        pre[i]=i;
    while(m--)
    {
        cin>>a>>b;
        pre[find(a)]=find(b);
    }
    for(int i=1;i<=n;i++)
    {
        if(pre[i]==i)
            ans++;
    }
    cout<<ans-1;
    return 0;
}
