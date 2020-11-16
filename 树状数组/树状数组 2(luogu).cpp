#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

typedef long long ll;
const int Max=500000;
ll tree[Max+5];
int n,m;
int temp,a,b,k;

ll lowbit(int x)
{
    return x&(-x);
}

ll sum(int x)
{
    ll ans=0;
    while(x!=0)
    {
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}

void add(int x,int y)
{
    while(x<=n)
    {
        tree[x]+=y;
        x+=lowbit(x);
    }
}

int main()
///本质上是用树状数组维护差分数组
{
    cin>>n>>m;
    int last=0;
    _for(i,1,n+1)
    {
        cin>>temp;
        add(i,temp-last);
        last=temp;
    }
    ///保存的是各个数字之差
    _for(i,0,m)
    {
        cin>>temp;
        if(temp==1)
        {
            cin>>a>>b>>k;
            add(a,k);
            add(b+1,-k);
        }
        else if(temp==2)
        {
            cin>>a;
            cout<<sum(a)<<endl;
        }
    }
    return 0;
}
