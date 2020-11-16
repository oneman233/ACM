#include <bits/stdc++.h>
using namespace std;

int m,n,x,y;
int arr[100005];
int st[100005][20];

void init()
{
    memset(st,0x3f,sizeof(st));
    for(int i=m;i>=1;--i){
        st[i][0]=arr[i];
        for(int j=1;i+(1<<j)-1<=m;++j)
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    }
}

int q(int l,int r)
{
    int len=(int)log2(r-l+1);
    return min(st[l][len],st[r-(1<<len)+1][len]);
}

int main()
{
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;++i)
        scanf("%d",&arr[i]);
    init();
    while(n--){
        scanf("%d %d",&x,&y);
        printf("%d ",q(x,y));
    }
    return 0;
}
