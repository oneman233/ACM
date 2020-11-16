#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;

int n;
char c[405];/*要把填法保存下来*/

void put()
{
    _for(i,0,2*n)
        cout<<c[i];
    cout<<endl;
}

void dfs(int zuo, int you, int flag,int i)/*i控制数组下标*/
{
    if(zuo > n || you > n || you > zuo)
    //左括号或右括号过多，右括号多于左括号
        return;
    if(i >= 2*n)
    //数组出界
        return;
    if(you > zuo)
        return;
    if(flag)
        c[i] = '(';
    else
        c[i] = ')';
    if(i == 2*n-1)
        put();
    dfs(zuo, you+1, 0, i+1);
    dfs(zuo+1, you, 1, i+1);
    /*传flag进去的时候直接传数字，不要1-flag*/
}

int main()
{
    cin>>n;
    dfs(1, 0, 1, 0);
    return 0;
}
