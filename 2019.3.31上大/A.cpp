#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int Max=100000;

int main()
{
    int n;
    cin>>n;
    if(n==0)
        cout<<"None";
    else if(n==1)
        cout<<"XiZhiTang";
    else if(n==2)
        cout<<"YingHuaTang";
    else
        cout<<"BigBoLang";
    return 0;
}
