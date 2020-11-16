#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[100005];

bool chk(int x)
{
    int flg=1,cnt=1;
    bool can=true;
    while(can){
        can=false;
        for(int i=flg+1;i<=n;++i){
            if(a[i]-a[flg]>=x){
                can=true;
                flg=i;
                cnt++;
                break;
            }
        }
        if(cnt>=m)
            return true;
    }
    return false;
}

int half(int l,int r)
{
    while(l<=r){
        int m=(l+r)/2;
        if(chk(m))
            l=m+1;
        else
            r=m-1;
    }
    return r;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    printf("%d",half(0,a[n]-a[1]));
    return 0;
}
