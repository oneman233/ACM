#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long num[1005];
    long long sum;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>num[i];
    cin>>sum;
    sort(num,num+n);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(num[i]+num[j]+num[k]==sum)
                {
                    cout<<num[i]<<" "<<num[j]<<" "<<num[k];
                    return 0;
                }
                if(num[i]+num[j]+num[k]>sum)
                    continue;
            }
        }
    }
    cout<<"NO";
    return 0;
}
