#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll n,ans=0;

///f(k)=f(2k)
///f(2)+...+f(2k)=f(1)+...+f(k)
///sum(2k)=f(1)+f(2)+f(3)+...+f(k)+...+f(2k)
///       =f(1)+f(3)+f(5)+...+f(2k-1)+f(2)+...+f(2k)
///       =1+3+5+...+2k-1+sum(k)
///let n equals to 2k,which means n%2==0
///sum(n)=1+3+5+...+n-1+sum(n/2)
///sum(n)=n*n/4+sum(n/2)

int main()
{
    cin>>n;
    while(n>=1){
        if(n&1){
            ans+=n;
            n--;
        }
        else{
            ans+=n*n/4LL;
            n>>=1;
        }
    }
    cout<<ans;
    return 0;
}
