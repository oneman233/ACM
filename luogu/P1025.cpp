#include <bits/stdc++.h>
using namespace std;

int n,k;
int ans=0;

void dfs(int tmp,int step,int flag)
{
    if(tmp==0&&step==k){
        ans++;
        return;
    }
    if(tmp<=0||step>=k)
        return;
    for(int i=flag;i<=tmp;++i)
        dfs(tmp-i,step+1,i);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        ans=0;
        cin>>n>>k;
        for(int i=0;i<=n/k;++i)
            dfs(n-i,1,i);
        cout<<ans<<endl;
    }

    return 0;
}
