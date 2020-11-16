#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,tiao[10005];
    int bu[10005];//抵达某一格所需的最小步数
    for(int i=0;i<10005;i++)
        bu[i]=1000000;//先全部设为无限大
    bu[0]=0;//抵达第0格不需要任何操作
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>tiao[i];
    for(int i=0;i<n;i++)
    {
        if(i+tiao[i]>=n&&bu[i]!=1000000)//一步过河，直接输出
        {
            cout<<bu[i]+1;
            return 0;
        }
        for(int j=1;j<=tiao[i];j++)
            bu[i+j]=min(bu[i]+1,bu[i+j]);
    }
    cout<<"-1";//如果在上面的循环过程中无法抵达，那么就没办法抵达对岸
    return 0;
}
