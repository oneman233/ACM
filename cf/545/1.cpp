#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int b[3];

int main()
{
    cin>>n;
    int as=0;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]!=a[i-1])
            b[a[i]]=0;
        b[a[i]]++;
        as=max(as,min(b[1],b[2])*2);
    }
    cout<<as;
    return 0;
}
