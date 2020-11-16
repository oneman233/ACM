#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;

const int Max=200000;

int main()
{
    int n,m,l;
    int a[Max+5],b[Max+5];
    /*n只鱼，m个渔夫，l长的绳子*/
    int chafen[Max+5];
    memset(chafen,0,sizeof(chafen));
    cin>>n>>m>>l;
    _for(i,0,n)
        cin>>a[i]>>b[i];
    _for(i,0,n)
    {
        if(b[i]>l)
            continue;
        int s=a[i]+b[i]-l,e=a[i]+l-b[i];
        if(s<1)
            chafen[1]++;
        else
            chafen[s]++;
        if(e>Max);///后面的所有人都能抓到这条鱼，没必要--
        else
            chafen[e+1]--;
    }
    int temp=0;
    _for(i,1,Max+1)
    {
        temp+=chafen[i];
        chafen[i]=temp;
    }
    int pos;
    _for(i,0,m)
    {
        cin>>pos;
        cout<<chafen[pos]<<endl;
    }
    return 0;
}
