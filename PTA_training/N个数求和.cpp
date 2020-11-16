#include <bits/stdc++.h>
using namespace std;

int n;
int fenmu[105],fenzi[105];
long long dafenmu=1,dafenzi=0;
long long zhengshu;
bool fushu=false;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d/%d",&fenzi[i],&fenmu[i]);
        dafenmu*=fenmu[i];
    }
    for(int i=0;i<n;i++)
        fenzi[i]*=dafenmu/fenmu[i];
    for(int i=0;i<n;i++)
        dafenzi+=fenzi[i];
    if(dafenzi<0)
    {
        fushu=true;
        dafenzi*=-1;
    }
    zhengshu=dafenzi/dafenmu;
    if(zhengshu!=0)
        printf("%lld",zhengshu);
    if(dafenzi%dafenmu==0)
        return 0;
    dafenzi%=dafenmu;
    for(int i=2;i<=dafenzi-1;i++)
    {
        while(dafenzi%i==0&&dafenmu%i==0)
        {
            dafenzi/=i;dafenmu/=i;
        }
    }
    if(zhengshu!=0)
        printf(" ");
    if(fushu)
        dafenzi*=-1;
    printf("%lld/%lld",dafenzi,dafenmu);
    return 0;
}
