#include <bits/stdc++.h>
using namespace std;

long long w(long long a ,long long b ,long long c)
{
    if(a<=0||b<=0||c<=0)
        return 1;
    if(a>20||b>20||c>20)
        return w(20,20,20);
    if(a<b&&b<c)
        return w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    return w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}

int main()
{
    int x,y,z;
    while(cin>>x>>y>>z)
    {
        if(x==-1&&y==-1&&z==-1)
            break;
        cout<<w(x,y,z)<<endl;
    }
    return 0;
}
