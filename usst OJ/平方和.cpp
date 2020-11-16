#include <bits/stdc++.h>
using namespace std;

vector<int> num;
int n;
int ans=10000;

void dfs(int i,int step,int now)
{
    if(i<0||step>ans)
        return;
    if(now==0)
    {
        ans=min(ans,step);
        return;
    }
    if(now>=num[i])
        dfs(i,step+1,now-num[i]);
    dfs(i-1,step,now);
}

int main()
{
    cin>>n;
    for(int i=1;i*i<=n;++i)
        num.push_back(i*i);
    dfs(num.size()-1,0,n);
    cout<<ans;
    return 0;
}
