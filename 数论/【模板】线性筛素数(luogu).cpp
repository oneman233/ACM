#include <bits/stdc++.h>
using namespace std;

int n,m,tmp;
int idx=0;///控制prime数组
int prime[500000];
int check[10000000];

inline void get_list()
{
    memset(check,0,sizeof(check));
    for(int i=2;i<=n;++i)
    {
        if(!check[i])
            prime[idx++]=i;///插入质数
        for(int j=0;j<idx;++j)
        {
            if(i*prime[j]>n)///过大则跳出
                break;
            check[i*prime[j]]=1;///去除质数的倍数
            if(i%prime[j]==0)
            ///此时i是一个合数，他们的乘积一定被一个较小的数已经筛去了
                break;
        }
    }
}

int main()
{
    cin>>n>>m;
    get_list();
    for(int i=0;i<m;++i)
    {
        cin>>tmp;
        if(!check[tmp]||tmp%2==0||tmp%3==0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    /*
    for(int i=0;i<idx;++i)
        cout<<prime[i]<<endl;
    */
    return 0;
}
