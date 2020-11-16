#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a[100010],ans=10000000;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    int ansi;
    for(int i=1;i<=100000;++i)///对每一个可能的终点
    {
        int cnt=0;///计数器
        bool can=true;///能否使得全部数字抵达终点
        for(int j=0;j<n;++j)///枚举该序列的各个值
        {
            int tmp=a[j];
            int contri=
            for(int i=0;tmp>=1;++i)
            {

            }
            ///修改数字
            if(tmp!=i)
            {
                can=false;
                break;
            }
        }
        if(cnt==0)
        {
            printf("0");
            return 0;
        }
        if(ans>cnt&&can)
        {
            ans=cnt;
            ansi=i;
        }
    }
    cout<<ansi<<endl;
    printf("%d",ans);
    return 0;
}
