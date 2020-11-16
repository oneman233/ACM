#include <bits/stdc++.h>
using namespace std;

int cost[10]={6,2,5,5,4,5,6,3,7,6};/*表示从0到9各个数字的消耗*/
int n;
int ans=0;

int cal(int num)
{
    int out=0;
    if(num==0)
        return 6;
    while(num!=0)
    {
        out+=cost[num%10];
        num/=10;
    }
    return out;
}
/*计算某一数字的消耗*/

int main()
{
    cin>>n;
    if(n<12)
    {
        cout<<0;
        return 0;
    }
    for(int i=0;i<=1000;i++)
    {
        for(int j=0;j<=1000;j++)
        {
            if((cal(i)+cal(j)+cal(i+j)+4)==n)
            {
                //cout<<i<<"+"<<j<<"="<<i+j<<endl;
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
