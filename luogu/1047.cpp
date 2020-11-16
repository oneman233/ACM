#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l,m;
    cin>>l>>m;
    int ans=0;
    int r[10005];
    for(int i=0;i<=l;i++)
        r[i]=1;
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        for(int j=x;j<=y;j++)
            r[j]=0;
    }
    for(int i=0;i<=l;i++)
    {
        if(r[i])
            ans++;
    }
    cout<<ans;
    return 0;
}
