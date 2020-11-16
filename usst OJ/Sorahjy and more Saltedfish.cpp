#include <bits/stdc++.h>

using namespace std;

int n;
long long num[1005];
long long out[1005];
long long cha;

void shuchu()
{
    for(int i=0;i<n;i++)
    {
        printf("%d",out[i]);
        if(i!=(n-1))
            printf(" ");
    }
}

int main()
{
    int cuowu=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>num[i];
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            cha=(num[j]-num[i])/(j-i);
            for(int k=0;k<n;k++)
            {
                out[k]=num[i]+cha*(k-i);
                if(out[k]!=num[k])
                    cuowu++;
                if(cuowu==4)
                    break;
            }
            if(cuowu!=4)
            {
                shuchu();
                return 0;
            }
            else
                cuowu=0;
        }
    }
    return 0;
}
