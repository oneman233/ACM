#include <bits/stdc++.h>
using namespace std;

int n,m;
int a,b;
int aji=0,aou=0,bji=0,bou=0;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a;
        if(a&1)
            aji++;
        else
            aou++;
    }
    for(int i=1;i<=m;++i){
        cin>>b;
        if(b&1)
            bji++;
        else
            bou++;
    }
    cout<<min(aji,bou)+min(aou,bji);
    return 0;
}
