#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    double pa=a/100.0,pb=b/100.0;
    pb*=(1.0-pa);
    if(pa>pb)
        cout<<"Ben";
    else if(pa==pb)
        cout<<"equal";
    else
        cout<<"Oak";
    return 0;
}
