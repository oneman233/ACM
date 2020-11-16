#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

const int Max=7;

void csort(int n[])
{
    int big=0,sml=1000000;
    _for(i,0,Max)
    {
        big=max(big,n[i]);
        sml=min(sml,n[i]);
    }
    int buc[big+1];
    memset(buc,0,sizeof(buc));
    _for(i,0,Max)
        buc[n[i]]++;
    _for(i,sml,big+1)
    {
        while(buc[i])
        {
            cout<<i<<" ";
            buc[i]--;
        }
    }
}

int main()
{
    int n[Max]={9,5,2,6,10,3,4};
    _for(i,0,Max)
        cout<<n[i]<<" ";
    cout<<endl;
    csort(n);
    return 0;
}
