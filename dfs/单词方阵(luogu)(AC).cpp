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
            isdel[i][j]=true;///初始一切都被删光了
        }
    }
    _for(i,0,7)
        clean.insert(check[i]);
    _for(i,0,n)
    {
        _for(j,0,n)
        {
            if(clean.count(c[i][j])==0)
                c[i][j]='*';///洗掉与yizhong无关的数据
        }
    }
}

inline bool dfs(int i,int j,int idx,int dir)
///最后一个参数是我在向着哪里前进
{
    if(i<0||i>=n||j<0||j>=n)///出界
        return false;
    if(c[i][j]=='*')///星号是绝对无用数据
        return false;
    if(c[i][j]!=check[idx])///无法与check数组匹配
        return false;
    if(c[i][j]=='g')
    {
        isdel[i][j]=false;
        return true;
        ///这条路走到头了
    }
    ///这一条路走通了
    if(dir==1&&dfs(i+1,j,idx+1,dir))
    {
        isdel[i][j]=false;///不可删除
        return true;
    }
    if(dir==2&&dfs(i-1,j,idx+1,dir))
    {
        isdel[i][j]=false;///不可删除
        return true;
    }
    if(dir==3&&dfs(i,j+1,idx+1,dir))
    {
        isdel[i][j]=false;///不可删除
        return true;
    }
    if(dir==4&&dfs(i,j-1,idx+1,dir))
    {
        isdel[i][j]=false;///不可删除
        return true;
    }
    if(dir==5&&dfs(i+1,j+1,idx+1,dir))
    {
        isdel[i][j]=false;///不可删除
        return true;
    }
    if(dir==6&&dfs(i+1,j-1,idx+1,dir))
    {
        isdel[i][j]=false;///不可删除
        return true;
    }
    if(dir==7&&dfs(i-1,j+1,idx+1,dir))
    {
        isdel[i][j]=false;///不可删除
        return true;
    }
    if(dir==8&&dfs(i-1,j-1,idx+1,dir))
    {
        isdel[i][j]=false;///不可删除
        return true;
    }
    return false;///没找到通路，直接返回false，并且该位置上的元素还要被删除
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
            ///遇到可能的y，就检查这个y所需要的八个方向
        }
    }
    put();
    return 0;
}
