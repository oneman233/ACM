#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    int cnt=0;
    int n[9]={1,2,3,4,5,6,7,8,9};
    do
    {
        int a=n[0]*100+n[1]*10+n[2];
        int b=n[3]*100+n[4]*10+n[5];
        int c=n[6]*100+n[7]*10+n[8];
        int d=(a+b+c)/(x+y+z);
        if(a==d*x&&b==d*y&&c==d*z)
        {
            cout<<a<<" "<<b<<" "<<c<<endl;
            cnt++;
        }
    }
    while(next_permutation(n,n+9));
    if(cnt==0)
        cout<<"No!!!";
    return 0;
}
