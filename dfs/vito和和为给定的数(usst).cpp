#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

///dfs比三重循环还慢，爷笑了

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
        while(j>i&&nu[j]>=flag)///小的甩到左边
            j--;
        nu[i]=nu[j];
        while(i<j&&nu[i]<=flag)///大的甩到右边
            i++;
        nu[j]=nu[i];
    }
    nu[i]=flag;
    qsor(s,i-1);
    qsor(i+1,e);
}

void dfs(int idx,int i)
///idx用于遍历nu数组，i用于控制ans数组，su用于储存和
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
    dfs(idx+1,i+1);///选了这个数
    dfs(idx+1,i);///没选这个数
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
