#include <bits/stdc++.h>

using namespace std;

int n,m,l;
//n条鱼，m个渔夫，l长的线
int a,b,x[200005];
//鱼的坐标和x轴
int man;
//储存渔夫的位置
int ans[200005];
//储存答案

int main()
//差分数组，下限++，上限的下一个--，最后是求和
{
    memset(x,0,sizeof(x));
    cin>>n>>m>>l;
    while(n--)
    {
        cin>>a>>b;
        if(b>l)
            continue;
        else if(b==l)
        {
            x[a]++;
            x[a+1]--;
        }
        else//b<l的情况
        {
            if(a+b-l<0)
                x[0]++;
            else
                x[a+b-l]++;
            if(a+l-b>200000);//超过二十万的就别减了
            else
                x[a+l-b+1]--;
        }
    }
    ans[0]=x[0];
    for(int i=1;i<=200000;i++)
        ans[i]=ans[i-1]+x[i];
    while(m--)
    {
        cin>>man;
        cout<<ans[man]<<endl;
    }
    return 0;
}
