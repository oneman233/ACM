#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005],b[100005];
int cnt[6],tmp[6];

int main()
{
    memset(cnt,0,sizeof(cnt));
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i]>>b[i];
    memset(tmp,0,sizeof(tmp));
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;++i){
        for(int j=1;j<=5;++j)
            if(j!=a[i]&&j!=b[i])
                tmp[j]=0;
        if(a[i]!=b[i]){
            tmp[a[i]]++;
            tmp[b[i]]++;
        }
        else{
            tmp[a[i]]++;
        }
        for(int j=1;j<=5;++j)
            cnt[j]=max(cnt[j],tmp[j]);
    }
    int big=-100,ans;
    for(int i=1;i<=5;++i){
        if(cnt[i]>big){
            big=cnt[i];
            ans=i;
        }
    }
    cout<<big<<' '<<ans;
    return 0;
}
