#include <bits/stdc++.h>
using namespace std;

int n;
int ans[10000],last[35],mid[35];//ansҪ����10000

int findmid(int l,int r,int num)
{
    for(int i=l;i<=r;i++)
    {
        if(mid[i]==num)
            return i;
    }
}

void build(int l,int r,int root,int idx)
{
    //cout<<idx<<endl;
    if(l>r)
        return;
    ans[idx]=last[root];
    //idx���ƴ��±�
    int pos=0;
    pos=findmid(l,r,last[root]);
    //cout<<pos<<endl;
    //pos��ȫ��ȷ
    //�ҵ����������еĸ��ڵ�
    //mid[pos]=last[root]
    build(l,pos-1,root-1-r+pos,idx*2+1);
    //������
    build(pos+1,r,root-1,idx*2+2);
    //������
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>last[i];
    for(int i=0;i<n;i++)
        cin>>mid[i];
    build(0,n-1,n-1,0);
    int cnt=0;
    for(int i=0;i<10000;i++)
    {
        if(ans[i]!=0)
        {
            cout<<ans[i];
            cnt++;
            if(cnt!=n)
                cout<<" ";
            else
                break;
        }
    }
    return 0;
}
