#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<b;++i)
using namespace std;
typedef long long ll;
const int maxn=100000;

int ans=0;
ll n;

int main()
{
    cin>>n;
    for(int j=0;j<32;j++)
    {
        if(n&(1<<j))
            ans++;
    }
    cout<<ans;
    return 0;
}
