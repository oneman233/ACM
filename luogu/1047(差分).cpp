#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l,m;
    int x,y;
    int way[10005];//被砍了多少次
    int ans=0;
    cin>>l>>m;
    for(int i=0;i<=l;i++)
        way[i]=0;
    while(m--)
    {
        cin>>x>>y;
        way[x]++;
        way[y+1]--;
    }
    for(int i=0,cut=0;i<=l;i++)
    {
        cut+=way[i];
        if(cut<=0)
            ans++;
    }
    cout<<ans;
    return 0;
}
