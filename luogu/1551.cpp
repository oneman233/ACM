#include <bits/stdc++.h>
using namespace std;

int n,m,p;
int pre[5005];

int root(int x)
{
    if(x==pre[x])
        return x;
    else
    {
        pre[x]=root(pre[x]);
        return pre[x];
    }
}

void meg(int x,int y)
{
    int xr=root(x);
    int yr=root(y);
    pre[xr]=yr;
}

int main()
{
    cin>>n>>m>>p;
    for(int i=1;i<=n;++i)
        pre[i]=i;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        meg(a,b);
    }
    while(p--)
    {
        int a,b;
        cin>>a>>b;
        if(root(a)==root(b))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
