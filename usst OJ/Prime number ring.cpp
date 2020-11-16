#include <bits/stdc++.h>

using namespace std;

bool isprime(int a)
{
    if(a==1)
        return false;
    for(int i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
            return true;
    }
    return false;
}

int num[20],n;
int lock1=0;

void shuchu()
{
    for(int i=0;i<n;i++)
    {
        cout<<num[i];
        if(i!=n-1)
            cout<<" ";
    }
    cout<<"\n";
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        num[i]=i+1;
    do
    {
        if(num[0]!=1)
            break;
        for(int i=0;i<=n-2;i++)
        {
            if(isprime(num[i]+num[i+1]))
                lock1=1;
        }
        if(isprime(num[0]+num[n-1]))
            lock1=1;
        if(lock1!=1)
            shuchu();
        lock1=0;
    }
    while(next_permutation(num,num+n));
    return 0;
}
