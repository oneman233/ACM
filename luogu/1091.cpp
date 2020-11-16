#include <bits/stdc++.h>
using namespace std;

int n;
int t[105];
int up[105],down[105];

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>t[i];
    for(int i=1;i<=n;++i)
        up[i]=1,down[i]=1;
    for(int i=1;i<=n;++i){
        for(int j=i-1;j>=1;--j){
            if(t[i]>t[j])
                up[i]=max(up[i],up[j]+1);
            else if(t[i]==t[j])
                up[i]=max(up[i],up[j]);
        }
    }
    for(int i=n;i>=1;--i){
        for(int j=i+1;j<=n;++j){
            if(t[i]>t[j])
                down[i]=max(down[i],down[j]+1);
            else if(t[i]==t[j])
                down[i]=max(down[i],down[j]);
        }
    }
    int ans=-100;
    /*
    for(int i=1;i<=n;++i)
        cout<<down[i]<<' ';
    */
    for(int i=1;i<=n;++i)
        ans=max(ans,up[i]+down[i]-1);
    cout<<n-ans;
    return 0;
}
/*
5
1 2 3 2 1

5
1 1 1 1 1
*/
