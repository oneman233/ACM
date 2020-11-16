#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    cin>>n;
    if(n==0){
        cout<<1;
        return 0;
    }
    int flag=1,cnt=0;
    do
    {
        flag*=2;
        flag%=(2*n+1);
        cnt++;
    }
    while(flag!=1);
    cout<<cnt;
    return 0;
}
