#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
    if(a==b)
        return a;
    if(a==1||b==1)
        return 1;
    if(a<b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    while(b!=0)
    {
        int i=a%b;
        a=b;
        b=i;
    }
    return a;
}

int main()
{
    int n,a,b;
    int yinshu;
    cin>>n>>a>>b;
    yinshu=gcd(a,b);
    if((n/yinshu-2)%2==0)
        cout<<"sorahjy";
    else
        cout<<"vito";
    return 0;
}
