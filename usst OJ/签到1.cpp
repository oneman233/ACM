#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int Max=500000;

int n,num[Max+5];

int main()
{
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        cout<<"8";
        _for(i,9,16)
            cout<<s[i];
        if(n!=0)
            cout<<endl;
    }
    return 0;
}
