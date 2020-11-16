#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2000000;

int n;
bool isp[maxn+5];
vector<int> p;

void get()
{
    isp[1]=1;
    for(int i=2;i<=maxn;++i)
    {
        if(!isp[i])
            p.push_back(i);
        for(int j=0;j<p.size();++j)
        {
            if(i*p[j]>maxn)
                break;
            isp[i*p[j]]=1;
            if(i%p[j]==0)
                break;
        }
    }
}

int main()
{
    scanf("%d",&n);
    get();
    if(!isp[n])
        printf("0");
    else
    {
        int pos=lower_bound(p.begin(),p.end(),n)-p.begin();
        printf("%d",p[pos]-p[pos-1]);
    }
    return 0;
}
