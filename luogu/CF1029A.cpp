#include <bits/stdc++.h>
using namespace std;

int n,k;
int p[55];
string t;

void getp()
{
    int j=0;
    p[0]=p[1]=0;
    for(int i=1;i<t.length();++i){
        while(j&&t[j]!=t[i])
            j=p[j];
        if(t[j]==t[i])
            j++;
        p[i+1]=j;
    }
}

void build()
{
    getp();
    string ans=t;
    ///at least print once
    int cnt=1;
    ///nums of matchings
    while(cnt<k){
        for(int i=p[t.length()];i<t.length();++i)
            ans.append(1,t[i]);
        cnt++;
    }
    cout<<ans;
}

int main()
{
    cin>>n>>k>>t;
    build();
    return 0;
}
