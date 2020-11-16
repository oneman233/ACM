#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    int pa=0,pb=0;
    cin>>a>>b;
    int x,y,z;
    cin>>x>>y>>z;
    if(x==1&&y==1&&z==1)
    {
        cout<<"The winner is b: "<<b<<" + 3";
        return 0;
    }
    if(x==0&&y==0&&z==0)
    {
        cout<<"The winner is a: "<<a<<" + 3";
        return 0;
    }
    if(x==1)
        pb++;
    else
        pa++;
    if(y==1)
        pb++;
    else
        pa++;
    if(z==1)
        pb++;
    else
        pa++;
    if(a+pa>b+pb)
        cout<<"The winner is a: "<<a<<" + "<<pa;
    else
        cout<<"The winner is b: "<<b<<" + "<<pb;
    return 0;
}
