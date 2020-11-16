#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<b;++i)
#define _rep(i,a,b) for(int i=a;i<=b;++i)
#define sci(a) scanf("%d",&a)
#define scc(a) scanf("%c",&a)
#define prc(a) printf("%c",a)
#define prn() printf("\n")
using namespace std;
typedef long long ll;
const ll Max=1000000;

int n;
char c[110][110];
char check[7]={'y','i','z','h','o','n','g'};
set<char> clean;
bool isdel[110][110];

inline void read()
{
    cin>>n;
    _for(i,0,n)
    {
        _for(j,0,n)
        {
            cin>>c[i][j];
            isdel[i][j]=true;///��ʼһ�ж���ɾ����
        }
    }
    _for(i,0,7)
        clean.insert(check[i]);
    _for(i,0,n)
    {
        _for(j,0,n)
        {
            if(clean.count(c[i][j])==0)
                c[i][j]='*';///ϴ����yizhong�޹ص�����
        }
    }
}

inline bool dfs(int i,int j,int idx,int dir)
///���һ��������������������ǰ��
{
    if(i<0||i>=n||j<0||j>=n)///����
        return false;
    if(c[i][j]=='*')///�Ǻ��Ǿ�����������
        return false;
    if(c[i][j]!=check[idx])///�޷���check����ƥ��
        return false;
    if(c[i][j]=='g')
    {
        isdel[i][j]=false;
        return true;
        ///����·�ߵ�ͷ��
    }
    ///��һ��·��ͨ��
    if(dir==1&&dfs(i+1,j,idx+1,dir))
    {
        isdel[i][j]=false;///����ɾ��
        return true;
    }
    if(dir==2&&dfs(i-1,j,idx+1,dir))
    {
        isdel[i][j]=false;///����ɾ��
        return true;
    }
    if(dir==3&&dfs(i,j+1,idx+1,dir))
    {
        isdel[i][j]=false;///����ɾ��
        return true;
    }
    if(dir==4&&dfs(i,j-1,idx+1,dir))
    {
        isdel[i][j]=false;///����ɾ��
        return true;
    }
    if(dir==5&&dfs(i+1,j+1,idx+1,dir))
    {
        isdel[i][j]=false;///����ɾ��
        return true;
    }
    if(dir==6&&dfs(i+1,j-1,idx+1,dir))
    {
        isdel[i][j]=false;///����ɾ��
        return true;
    }
    if(dir==7&&dfs(i-1,j+1,idx+1,dir))
    {
        isdel[i][j]=false;///����ɾ��
        return true;
    }
    if(dir==8&&dfs(i-1,j-1,idx+1,dir))
    {
        isdel[i][j]=false;///����ɾ��
        return true;
    }
    return false;///û�ҵ�ͨ·��ֱ�ӷ���false�����Ҹ�λ���ϵ�Ԫ�ػ�Ҫ��ɾ��
}

inline void put()
{
    _for(i,0,n)
    {
        _for(j,0,n)
        {
            if(c[i][j]=='*')
                prc('*');
            else
            {
                if(isdel[i][j])
                    prc('*');
                else
                    prc(c[i][j]);
            }
        }
        if(i!=n-1)
            prn();
    }
}

int main()
{
    read();
    _for(i,0,n)
    {
        _for(j,0,n)
        {
            if(c[i][j]=='y')
            {
                dfs(i,j,0,1);
                dfs(i,j,0,2);
                dfs(i,j,0,3);
                dfs(i,j,0,4);
                dfs(i,j,0,5);
                dfs(i,j,0,6);
                dfs(i,j,0,7);
                dfs(i,j,0,8);
            }
            ///�������ܵ�y���ͼ�����y����Ҫ�İ˸�����
        }
    }
    put();
    return 0;
}
