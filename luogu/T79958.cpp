#include <bits/stdc++.h>
using namespace std;

int t,n,ans=0;
int a[10005];

void s(int l1,int r1,int l2,int r2)
{
    int i=l1,j=l2,k=0;
    int tmp[10005];
    while(i<=r1&&j<=r2){
        if(a[i]<=a[j]){
            tmp[k]=a[i];
            i++;
        }
        else{
            tmp[k]=a[j];
            j++;
            ans+=r1-i+1;
        }
        k++;
    }
    while(i<=r1){
        tmp[k]=a[i];
        i++;
        k++;
    }
    while(j<=r2){
        tmp[k]=a[j];
        j++;
        k++;
    }
    j=0;
    for(i=l1;i<=r2;++i,++j)
        a[i]=tmp[j];
}

void ms(int l,int r)
{
    if(l==r)
        return;
    ms(l,(l+r)/2);
    ms((l+r)/2+1,r);
    s(l,(l+r)/2,(l+r)/2+1,r);
}

int main()
{
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        ms(1,n);
    printf("%d\n",ans);
    }
    return 0;
}
