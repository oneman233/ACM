#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int Max = 100000;

int main()
{
    int n,xi[Max];
    bool allzero=true;
    cin>>n;
    for(int i=n;i>=0;--i)
    {
        cin>>xi[i];
        if(xi[i]!=0)
            allzero=false;
    }
    if(n==0)
    ///nΪ0ֱ�����ϵ������
        cout<<xi[0];
    else
    {
        ///ȫΪ0������
        if(allzero)
        {
            cout<<0;
            return 0;
        }
        while(xi[n]==0)
            n--;///�ҵ�ͷ��λ��
        if(n!=0)
        {
            ///ͷ
            if(xi[n]==0);
            else if(xi[n]==1)
                cout<<"x^"<<n;
            else if(xi[n]==-1)
                cout<<"-x^"<<n;
            else
                cout<<xi[n]<<"x^"<<n;
            ///�м�
            for(int i=n-1;i>=1;--i)
            {
                if(i!=1)
                {
                    if(xi[i]==0)
                        continue;
                    if(xi[i]>1)
                        cout<<"+"<<xi[i]<<"x^"<<i;
                    else if(xi[i]<-1)
                        cout<<xi[i]<<"x^"<<i;
                    else if(xi[i]==1)
                        cout<<"+"<<"x^"<<i;
                    else if(xi[i]==-1)
                        cout<<"-x^"<<i;
                }
                else
                {
                    if(xi[i]==0)
                        continue;
                    if(xi[i]>1)
                        cout<<"+"<<xi[i]<<"x";
                    else if(xi[i]<-1)
                        cout<<xi[i]<<"x";
                    else if(xi[i]==1)
                        cout<<"+"<<"x";
                    else if(xi[i]==-1)
                        cout<<"-x";
                }
            }
        }
        ///β
        if(n==0)
        {
            cout<<xi[n];
            return 0;
        }
        if(xi[0]==0);
        else if(xi[0]>0)
            cout<<"+"<<xi[0];
        else
            cout<<xi[0];
    }
    return 0;
}
