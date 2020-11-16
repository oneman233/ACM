#include <bits/stdc++.h>
using namespace std;
const int N=5001,K=1000001;

int n,s[N],vis[K];

int main()
{
    memset(vis,0,sizeof(vis));
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>s[i];
    sort(s+1,s+1+n);
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            vis[s[j]-s[i]]=1;
    for(int k=1;k<=K;++k){
        if(!vis[k]){
            int flg=1;
            for(int j=k;j<=K;j+=k){
                if(vis[j]){
                    flg=0;
                    break;
                }
            }
            if(flg){
                cout<<k;
                break;
            }
        }
    }
    return 0;
}
