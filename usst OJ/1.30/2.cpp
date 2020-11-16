#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int num[10005];
    memset(num,0,sizeof(num));
    for(int i=0;i<n;i++)
        cin>>num[i];
    sort(num,num+n);
    if(num[0]!=1)
        cout<<1;
    else
    {
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=num[i];
            if(num[i]==1)
                continue;
            if(i==n-1)
                break;
            if(num[i+1]<=sum);
            else
            {
                cout<<sum+1;
                return 0;
            }
        }
        //num10000多全部为0
        cout<<sum+1;
    }
    return 0;
}
