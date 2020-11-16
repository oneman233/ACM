#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,ans=0;
int k,num[100005],idx=0;
ll brute_ans=0;

void trans()
{
    while(n){
        num[idx++]=n%k;
        n/=k;
    }
}

void brute(ll in)
{
    int tmp=in;
    string a="";
    while(tmp){
        a.append(1,tmp%k+'0');
        tmp/=k;
    }
    for(int i=0;i<a.length();++i)
        if(a[i]!='0'&&(i&1))
            return;
    brute_ans++;
    ///cout<<in<<endl;
}

void lower()
{
    for(int i=idx-1;i>=0;--i){
        if(num[i]!=0&&(i&1)){
            num[i]=0;
            num[i-1]=k-1;
        }
    }
}

ll pow(int x)
{
    ll out=1,tmp=k;
    while(x){
        if(x&1)
            out*=tmp;
        tmp*=tmp;
        x>>=1;
    }
    return out;
}

void put()
{
    for(int i=idx-1;i>=0;--i)
        cout<<num[i]<<" ";
    cout<<endl;
}

int main()
{
    cin>>n>>k;
    trans();
    ///put();
    if(idx&1)
        ans+=pow((idx-1)/2);
    else
        ans+=pow(idx/2);
    if(idx&1){
        lower();
        ///put();
        ans+=num[idx-1]*pow((idx-1)/2);
        for(int i=idx-3;i>=0;i-=2)
            ans-=(k-1-num[i])*pow((i-1)/2);
    }
    cout<<ans;
    /*
    for(ll i=0;i<=n;++i)
        brute(i);
    cout<<brute_ans;
    */
    return 0;
}
