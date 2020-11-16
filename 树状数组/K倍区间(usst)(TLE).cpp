#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

typedef long long ll;
const ll Max=100000;
int n,k,temp,ans=0;
int tr[Max+5];

int lowbit(int x)
{
    return x&(-x);
}

void add(int x,int val)
{
    while(x<=n)
    {
        tr[x]+=val;
        x+=lowbit(x);
    }
    ///向上修改
}

int sum(int x)
{
    int ans=0;
    while(x!=0)
    {
        ans+=tr[x];
        x-=lowbit(x);
    }
    ///向下求和
    return ans;
}

int main()
{
    cin>>n>>k;
    _for(i,1,n+1)
    {
        cin>>temp;
        add(i,temp);
    }
    int ans=0;
    _for(i,1,n+1)
    {
        _for(j,i,n+1)
        {
            if((sum(j)-sum(i-1))%k==0)///求区间和下限要减一
                ++ans;
        }
    }
    cout<<ans;
    return 0;
}
