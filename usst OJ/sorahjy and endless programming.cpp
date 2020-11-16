#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;//命令行数
    int i;//计数器
    int ans=0;//储存运算结果
    int num[260][2];//储存运算数
    int lock=1000;//运行了100000次就认为会无限运行
    string order[300];//储存命令
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>order[i];
        if(order[i]=="if")
            cin>>num[i][0]>>num[i][1];
        else
            cin>>num[i][0];
    }
    i=1;
    while(true)
    {
        lock--;
        if(lock==0)
        {
            cout<<"-1";
            return 0;
        }
        if(order[i]=="add")
            ans=(ans+num[i][0])%256;
        else if(order[i]=="minus")
            ans=(ans+256-num[i][0])%256;
        else if(order[i]=="xor")
            ans=(ans^num[i][0])%256;
        else if(order[i]=="jump")
        {
            i=num[i][0];
            if(i>n)
                break;
            continue;
        }
        else if(order[i]=="if")
        {
            if(ans<num[i][0])
            {
                i=num[i][1];
                if(i>n)
                    break;
                continue;
            }
        }
        i++;
        if(i>n)
            break;
    }
    cout<<ans;
    return 0;
}
