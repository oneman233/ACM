#include <bits/stdc++.h>
using namespace std;
const int maxn=100000;
typedef long long ll;

int n;
ll a[maxn+5];

void s(ll &a,ll &b)
{
    ll tmp=a;
    a=b;
    b=tmp;
}

void put()
{
    for(int i=0;i<n;++i)
        printf("%d ",a[i]);
    printf("\n");
}

void shell_sort(int l,int r)
{
    int len=r-l+1;
    for(int gap=len/2;gap>0;gap/=2)
    {
        for(int i=gap;i<len;++i)
        {
            int j=i;
            while(j-gap>=0&&a[j]<a[j-gap])
            {
                s(a[j],a[j-gap]);
                j-=gap;
            }
        }
    }
}

void insert_sort(int l,int r)
{
    for(int i=l;i<=r;++i){
        int j=i-1;
        for(;j>=l&&a[j]>a[i];j--);
        if(j!=l-1){
            int tmp=a[i];
            for(int k=i-1;k>=j+1;--k)
                a[k+1]=a[k];
            a[j+1]=tmp;
        }
    }
}

void qsort(int l,int r)
{
    if(l>=r)
        return;
    if(r-l<=10)
        insert_sort(l,r);
    else
    {
        int m=(l+r)/2;

    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    /*
    qsort(0,n-1);
    put();
    */
    /*
    insert_sort(0,n-1);
    put();
    */
    shell_sort(0,n-1);
    put();
    return 0;
}
