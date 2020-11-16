#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num[12];
    int money=0;
    int store=0;
    for(int i=0;i<12;i++)
        cin>>num[i];
    for(int i=0;i<12;i++)
    {
        money+=300;//月初得到零花钱
        money-=num[i];//除去预算
        if(money>=100)
        {
            store+=money/100*100;
            money%=100;
        }
        else if(money<0)
        {
            cout<<-(i+1);
            return 0;
        }
        else;
    }
    cout<<store*1.2+money;
    return 0;
}
