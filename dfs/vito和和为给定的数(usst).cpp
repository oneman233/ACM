#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

///dfs������ѭ��������үЦ��

typedef long long ll;
const int Max=1000;
int n;
bool flag=true;
ll sum,nu[Max+5],ans[3];

void qsor(int s,int e)
{
    if(s>e)
        return;
    int i=s,j=e;
    ll flag=nu[s];
    while(i<j)
    {
        while(j>i&&nu[j]>=flag)///С��˦�����
            j--;
        nu[i]=nu[j];
        while(i<j&&nu[i]<=flag)///���˦���ұ�
            i++;
        nu[j]=nu[i];
    }
    nu[i]=flag;
    qsor(s,i-1);
    qsor(i+1,e);
}

void dfs(int idx,int i)
///idx���ڱ���nu���飬i���ڿ���ans���飬su���ڴ����
{
    if(idx>=n||i>=3||!flag)
        return;
    if(ans[0]+ans[1]+ans[2]==sum)
    {
        flag=false;
        cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2];
        return;
    }
    /*
    _for(i,0,3)
        cout<<ans[i]<<" ";
    cout<<su<<endl;
    */
    ans[i]=nu[idx];
    dfs(idx+1,i+1);///ѡ�������
    dfs(idx+1,i);///ûѡ�����
}

int main()
{
    cin>>n;
    _for(i,0,n)
        cin>>nu[i];
    qsor(0,n-1);
    cin>>sum;
    dfs(0,0);
    if(flag)
        cout<<"NO";
    return 0;
}
