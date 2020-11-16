#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=500005;

int n;
ll a[maxn];
ll tmp[maxn];
ll ans=0;

void s(int l1,int r1,int l2,int r2)
{
    int i=l1,j=l2,k=0;
    while(i<=r1&&j<=r2){
        if(a[i]<=a[j]){
            tmp[k]=a[i];
            i++;
        }
        else{
            tmp[k]=a[j];
            ans+=r1-i+1;
            j++;
        }
        k++;
    }
    while(i<=r1){
        tmp[k]=a[i];
        i++;k++;
    }
    while(j<=r2){
        tmp[k]=a[j];
        j++;k++;
    }
    for(int p=l1,q=0;p<=r2;p++,q++)
        a[p]=tmp[q];
}

void ms(int l,int r)
{
    if(l>=r)
        return;
    int m=(l+r)/2;
    ms(l,m);
    ms(m+1,r);
    s(l,m,m+1,r);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%lld",&a[i]);
    ms(1,n);
    //cout<<ans<<endl;
    printf("%lld",a[1]);
    for(int i=2;i<=n;++i)
        printf(" %lld",a[i]);
    printf("\n");
    return 0;
}
