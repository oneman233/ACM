#include <bits/stdc++.h>
#define elif else if
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;
int a[1099];
int x[1099][1099];

int main()
{
    int mn=1e9;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            if(i<j) x[i][j]=a[j]-a[i];
            else x[i][j]=9001;
        }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            mn=min(mn,x[i][j]);
    if(mn>=0) puts("yes");
    else puts("no");
    return 0;
}
