#include <bits/stdc++.h>
using namespace std;

int n,a,x,b,y;
int l(int x)
{
    if(x>1)
        return x-1;
    else
        return n;
}
int r(int x)
{
    if(x<n)
        return x+1;
    else
        return 1;
}

int main()
{
    cin>>n>>a>>x>>b>>y;
    bool can=false;
    int f1=a,f2=b;
    while(f1!=x&&f2!=y){
        f1=r(f1);f2=l(f2);
        if(f1==f2){
            can=true;
            break;
        }
    }
    if(can)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
