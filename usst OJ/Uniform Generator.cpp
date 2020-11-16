#include <bits/stdc++.h>

using namespace std;

int huzhi(int a,int b)
{
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
    int x,y;
    while(cin>>x>>y)
    {
        if(huzhi(x,y)==1)
            printf("%10d%10d    Good Choice\n",x,y);
        else
            printf("%10d%10d    Bad Choice\n",x,y);
    }
    return 0;
}
