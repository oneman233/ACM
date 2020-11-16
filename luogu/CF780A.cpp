#include <bits/stdc++.h>
using namespace std;

int n;
int x[200005];

int main()
{
    cin>>n;
    int cnt=0,mx=0;
    map<int,int> m;
    for(int i=1;i<=n*2;++i){
        cin>>x[i];
        if(m[x[i]]==0){
            cnt++;
            m[x[i]]=1;
        }
        else{
            cnt--;
            m[x[i]]=0;
        }
        mx=max(mx,cnt);
    }
    cout<<mx;
    return 0;
}
