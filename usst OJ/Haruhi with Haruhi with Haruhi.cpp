#include <bits/stdc++.h>
#define sci(a) scanf("%d",&a)
#define pri(a) printf("%d",a)
#define prn() printf("\n");
#define re(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int maxn=30010;

int n;
int m[maxn][6],r[6][maxn];
bitset<maxn> s[6][maxn];

int main()
{
    sci(n);
    re(i,1,n)
    {
        re(j,1,5)
        {
            sci(m[i][j]);
            r[j][m[i][j]]=i;
        }
    }
    re(i,1,5)
    {
        re(j,2,n)
        ///don't have to set rank 1
        ///no one wiil be higher than rank 1
        {
            s[i][j]|=s[i][j-1];
            ///the r wasn't sat when j-1
            ///if there is one,the ans will be one
            s[i][j].set(r[i][j-1]);
            ///the position starts at 0
        }
    }
    re(i,1,n)
    {
        bitset<maxn> tp=s[1][m[i][1]];
        re(j,2,5)
            tp&=s[j][m[i][j]];
        pri(tp.count());
        if(i!=n)
            prn();
    }
    return 0;
}
/*
10
2 4 8 1 3
10 10 1 10 7
6 8 7 6 9
3 5 4 5 8
7 3 2 4 10
4 6 3 7 5
8 2 5 2 4
5 9 6 3 2
9 1 9 9 6
1 7 10 8 1
*/
