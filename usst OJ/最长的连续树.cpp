#include<bits/stdc++.h>
using namespace std;
const int maxm=1000000;

int m,n,tmp,cnt;
int a[maxm+5],b[maxm+5];

int main()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;++i){
        scanf("%d",&tmp);
        if(tmp&1)
            a[tmp]=1;
        else
            b[tmp]=1;
    }
    int ans=0,pos;
    cnt=0;
    for(int i=1;i<=m-1;i+=2)
    {
        if(a[i]==0)
            cnt++;
        else
            cnt=0;
        if(cnt>ans){
            ans=cnt;
            pos=i-(ans-1)*2;
        }
    }
    cnt=0;
    for(int i=2;i<=m;i+=2)
    {
        if(b[i]==0)
            cnt++;
        else
            cnt=0;
        if(cnt>ans){
            ans=cnt;
            pos=i-(ans-1)*2;
        }
    }
    cout<<pos<<" "<<ans;
    return 0;
}
