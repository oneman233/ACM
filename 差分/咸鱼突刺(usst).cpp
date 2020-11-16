#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long blood[300005],sword[300005];
    int chafen[300005];
    memset(chafen,0,sizeof(chafen));
    int temp=0;
    _for(i,0,n)
        cin>>sword[i];
    _for(i,0,n)
        cin>>blood[i];
    _for(i,0,n)
    {
        if(sword[i]>=i)
            chafen[0]++;
        else
            chafen[i-sword[i]]++;
        chafen[i]--;
    }
    int ans=0;
    _for(i,0,n)
    {
        temp+=chafen[i];
        if(temp<=blood[i])
            ans++;
    }
    cout<<ans;
    return 0;
}
