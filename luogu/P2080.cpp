#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,v;
int a[35],b[35];
int ans=0x3f3f3f3f;

int main()
{
    cin>>n>>v;
    for(int i=0;i<n;++i)
        cin>>a[i]>>b[i];
    for(int i=1;i<(1LL<<n);++i){
        int cnta=0,cntb=0;
        for(int j=0;j<n;++j){
            if(i&(1LL<<j)){
                cnta+=a[j];
                cntb+=b[j];
            }
        }
        if(cnta+cntb>=v)
            ans=min(ans,abs(cnta-cntb));
        if(ans==0)
            break;
    }
    if(ans!=0x3f3f3f3f)
        cout<<ans;
    else
        cout<<-1;
    return 0;
}
