#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int t;
    int num,sum=0,maxsum=-1001,tou,wei,temp=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        sum=0,maxsum=-1001,temp=1;
        cin>>t;
        for(int j=0;j<t;j++)
        {
            cin>>num;
            sum+=num;
            if(sum>maxsum)
            {
                tou=temp;
                wei=j+1;
                maxsum=sum;
            }
            if(sum<0)
            {
                sum=0;
                temp=j+2;
            }
        }
        printf("Case %d:\n%d %d %d\n",i,maxsum,tou,wei);
        if(i!=n)
            printf("\n");
    }
    return 0;
}
