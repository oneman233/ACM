#include <bits/stdc++.h>
using namespace std;
int n,a[200005],b[200005];
map<int,int> m;

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){cin>>a[i];m[a[i]]=0;}
    for(int i=1;i<=n;++i){cin>>b[i];m[b[i]]=i;}
    if(m[1]){
        for(int i=2;i<=n;++i){
            if(m[i-1]==n){
                for(int j=i;j<=n&&m[j]<=j-i;++j){
                    if(j>n){
                        cout<<n-i+1;
                        return 0;
                    }
                }
            }
        }
    }
    int as=0;
    for(int i=1;i<=n;++i)
        as=max(as,m[i]-i+1+n);
    cout<<as;
    return 0;
}
