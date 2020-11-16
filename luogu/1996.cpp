#include <bits/stdc++.h>
using namespace std;

int n,m;
bool vis[105];
int r(int i)
{
    if(i<n)
        return i+1;
    else
        return 1;
}

int main()
{
    memset(vis,0,sizeof(vis));
    cin>>n>>m;
    int cnt=0,fg=1000000,i=1;
    while(fg--){
        if(!vis[i])
            cnt++;
        if(cnt==m){
            vis[i]=true;
            cout<<i<<" ";
            cnt=0;
        }
        i=r(i);
    }
    return 0;
}
