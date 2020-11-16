#include <bits/stdc++.h>
using namespace std;

int n,sm=0,as=0;
int a[105];

void debug()
{
    for(int i=1;i<=n;++i)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i],sm+=a[i];
    sm/=n;
    for(int i=1;i<=n;++i){
        if(a[i]<sm){
            a[i+1]-=sm-a[i];
            a[i]=sm;
            as++;
        }
        else if(a[i]>sm){
            a[i+1]+=a[i]-sm;
            a[i]=sm;
            as++;
        }
    }
    cout<<as;
    return 0;
}
