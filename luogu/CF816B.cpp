#include <bits\stdc++.h>
using namespace std;
const int maxn=200005;

int n,k,q;
int l,r,dif[maxn],sum[maxn],ans[maxn];

void debug()
{
    for(int i=90;i<=100;++i)
        cout<<sum[i]<<' ';
    cout<<endl;
    for(int i=90;i<=100;++i)
        cout<<ans[i]<<' ';
    cout<<endl;
}

int main(){
    cin>>n>>k>>q;
    memset(dif,0,sizeof(dif));
    for(int i=1;i<=n;++i){
        cin>>l>>r;
        dif[l]++;
        dif[r+1]--;
    }
    sum[1]=dif[1];
    for(int i=2;i<=200000;++i)
        sum[i]=sum[i-1]+dif[i];
    ans[0]=0;
    int cnt=0;
    for(int i=1;i<=200000;++i){
        if(sum[i]>=k)
            cnt++;
        ans[i]=cnt;
    }
    //debug();
    for(int i=1;i<=q;++i){
        cin>>l>>r;
        cout<<ans[r]-ans[l-1]<<endl;
    }
    return 0;
}
