#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;

int n;
char c[405];/*Ҫ�����������*/

void put()
{
    _for(i,0,2*n)
        cout<<c[i];
    cout<<endl;
}

void dfs(int zuo, int you, int flag,int i)/*i���������±�*/
{
    if(zuo > n || you > n || you > zuo)
    //�����Ż������Ź��࣬�����Ŷ���������
        return;
    if(i >= 2*n)
    //�������
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
    /*��flag��ȥ��ʱ��ֱ�Ӵ����֣���Ҫ1-flag*/
}

int main()
{
    cin>>n;
    dfs(1, 0, 1, 0);
    return 0;
}
