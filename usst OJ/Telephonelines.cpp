#include <bits/stdc++.h>
#define _rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

const int MAX=105;
const int INF=1e+6;

int n;//�ڵ���
int way[MAX][MAX],par[MAX],low[MAX];
//������󡢸��ڵ��������
bool vis[MAX];//�Ƿ񱻷���
vector<int> out;
long long ans=0;
//�������
int make,cost;
//�������ĸ��ڵ�͵�ǰ�������

int main()
{
    scanf("%d",&n);
    _rep(i,1,n)
    {
        _rep(j,1,n)
        {
            scanf("%d",&way[i][j]);
        }
    }
    _rep(i,1,n)
    {
        vis[i]=false;
        low[i]=INF;
    }
    low[1]=0;
    //��һ������һ�Žڵ㣬���Ƕ�ȥ��һ�Žڵ�����Ϊ�ѷ���
    par[1]=1;
    //���ĸ��ڵ����Լ�
    _rep(i,1,n)
    {
        cost=INF;
        _rep(j,1,n)
        {
            if(!vis[j]&&low[j]<cost)
            {
                cost=low[j];
                make=j;
            }
        }
        vis[make]=true;
        ans+=cost;
        if(cost)//������Ĳ�Ϊ0���������޵�·�������ֵ��򴢴�
        {
            out.push_back(min(make,par[make]));
            out.push_back(max(make,par[make]));
        }
        _rep(j,1,n)
        {
            if(!vis[j]&&way[make][j]<low[j])//���ǵ��Ǵ�j�޵�make��·��
            {
                low[j]=way[make][j];
                par[j]=make;
            }
        }
    }
    printf("%d",out.size()/2);
    if(!out.empty())
    {
        for(int i=0;i<=out.size()-1;i+=2)
            printf("\n%d %d",out[i],out[i+1]);
    }
    printf("\n%lld",ans);
}
