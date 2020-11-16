#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;

struct m
{
private:
    long long num[2][2];
public:
    m(long long a,long long b,long long c,long long d)
    {
        num[0][0]=a;
        num[0][1]=b;
        num[1][0]=c;
        num[1][1]=d;
    }
    int getnum(int i,int j)
    {
        return num[i][j];
    }
    void setnum(int i,int j,long long val)
    {
        num[i][j]=val;
    }
};

m mul(m a,m b)
{
    m ans=m(0,0,0,0);
    long long ul=0,ur=0,dl=0,dr=0;
    _for(i,0,2)
        ul+=a.getnum(0,i)*b.getnum(i,0);
    _for(i,0,2)
        dl+=a.getnum(1,i)*b.getnum(i,0);
    _for(i,0,2)
        ur+=a.getnum(0,i)*b.getnum(i,1);
    _for(i,0,2)
        dr+=a.getnum(1,i)*b.getnum(i,1);
    ans.setnum(0,0,ul);
    ans.setnum(0,1,ur);
    ans.setnum(1,0,dl);
    ans.setnum(1,1,dr);
    return ans;
}

long long f(int n)
{
    if(n<=2)
        return 1;
    n-=2;
    m ans=m(1,0,0,1);
    m temp=m(0,1,1,1);
    while(n)
    {
        if(n&1)
            ans=mul(ans,temp);
        temp=mul(temp,temp);
        n/=2;
    }
    return ans.getnum(0,1)+ans.getnum(1,1);
}

int main()
{
    int n;
    while(cin>>n)
        cout<<f(n)<<endl;
    return 0;
}

/*
两个性质：
f1^2+f2^2+...+fn^2=fn*fn+1
gcd(fa,fb)=f(gcd(a,b))
*/
