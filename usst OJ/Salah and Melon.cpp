#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,k;
ll cnt=0;

int main()
{
    cin>>m>>k>>n;
    ll as=1;
    while(as*k<=m)
        ++as;
    while(as*k<=n){
        cout<<as*k-m<<endl;
        ++as;
        ++cnt;
    }
    if(cnt==0)
        cout<<-1;
    return 0;
}
