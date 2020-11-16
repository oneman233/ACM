#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;
typedef long long ll;

const ll Max = 0x3f3f3f3f;
int nu[25];
int n,k,ans=0;

inline bool ispri(int x)
{
    if(x==0 || x==1)
        return false;
    for(int i=2;i*i<=x;++i)
        if(x%i==0)
            return false;
    return true;
}

inline void dfs(int step,int sum,int cnt)
{
    if(step==n || cnt==k)///遍历完毕或者已经找了k个数了
    {
        if(ispri(sum) && cnt==k)
            ++ans;
        return;
    }
    dfs(step+1,sum+nu[step],cnt+1);///选择
    dfs(step+1,sum,cnt);///不选择
}

int main()
{
    cin>>n>>k;
    _for(i,0,n)
        cin>>nu[i];
    dfs(0,0,0);
    cout<<ans;
    return 0;
}
