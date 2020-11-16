#include <bits/stdc++.h>
using namespace std;

double die(int n)
{
    double ans=0.0;
    for(int i=2;i<=n+1;i++)
        ans+=1.0/i;
    return ans;
}

int main()
{
    double a;
    while(cin>>a)
    {
        for(int i=1;i<1000;i++)
        {
            if(die(i)>=a)
            {
                cout<<i<<" card(s)"<<endl;
                break;
            }
        }
    }
    return 0;
}
