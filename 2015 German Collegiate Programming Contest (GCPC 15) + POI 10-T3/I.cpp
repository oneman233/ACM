#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define elif else if

int w,s;
int x,y;
vector<int> workpiece[10005];
int program[10005]={0};

int main()
{
    int tmp;
    scanf("%d %d",&w,&s);
    scanf("%d %d",&x,&y);
    for(int i=0;i<w;i++)
    {
        for(int j=0;j<x;j++)
        {
            scanf("%d",&tmp);
            workpiece[i].push_back(tmp);
        }
    }
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<x;j++)
        {
            scanf("%d",&tmp);
            program[j]=max(program[j],tmp);
        }
    }
    for(int i=0;i<w;i++)
    {
        for(int j=0;j<x;j++)
        {
            printf("%d ",min(workpiece[i][j],y-program[j]));
        }
        printf("\n");
    }
    
    return 0;
}
