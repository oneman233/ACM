#include <bits/stdc++.h>
using namespace std;
const int mod=100003;

int n,k;
int a[100000+100+5];

int main()
{
    a[0]=1;
    cin>>n>>k;
    for(int i=0;i<=n;++i){
        a[i]%=mod;
        for(int j=i+1;j<=i+k;++j){
            a[j]+=a[i];
            a[j]%=mod;
        }
    }
    cout<<a[n];
    return 0;
}
