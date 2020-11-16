#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,m;
    cin>>n>>m;
    if(m%n!=0)
        cout<<-1;
    else
    {
        int div=m/n,cnt=0;
        while(div%2==0)
        {
            div/=2;
            cnt++;
        }
        while(div%3==0)
        {
            div/=3;
            cnt++;
        }
        if(div==1)
            cout<<cnt;
        else
            cout<<-1;
    }
    return 0;
}
