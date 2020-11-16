#include <bits/stdc++.h>
using namespace std;
const int maxn=205;
const int inf=0x3f3f3f3f;

int n;
int num[maxn],s[maxn];
int mx[maxn][maxn],mn[maxn][maxn];

int dif(int i,int j)
{
    return s[j]-s[i-1];
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&num[i]);
        s[i]=s[i-1]+num[i];
    }
    for(int i=n+1;i<=2*n;++i){
        num[i]=num[i-n];
        s[i]=s[i-1]+num[i];
    }
    memset(mn,0x3f,sizeof(mn));
    for(int i=1;i<=2*n;++i)
        mn[i][i]=0;
    for(int len=1;len<=n;++len){
        for(int i=1;i<=2*n&&i+len-1<=2*n;++i){
            int j=i+len-1;
            for(int k=i;k<j;++k){
                mx[i][j]=max(mx[i][j],mx[i][k]+mx[k+1][j]+dif(i,j));
                mn[i][j]=min(mn[i][j],mn[i][k]+mn[k+1][j]+dif(i,j));
            }
        }
    }
    int mxans=0,mnans=inf;
    for(int i=1;i<n;++i){
        mxans=max(mxans,mx[i][i+n-1]);
        mnans=min(mnans,mn[i][i+n-1]);
    }
    printf("%d\n%d",mnans,mxans);
    return 0;
}
