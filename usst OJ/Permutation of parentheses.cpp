#include <bits/stdc++.h>

using namespace std;

int sumout=0;
int n;
int out[405];//最多输出400个字符

void shuchu(int * out,int n)
{
    for(int i=0;i<2*n;i++)
    {
        if(out[i]==1)
            cout<<"(";
        else if(out[i]==2)
            cout<<")";
    }
    cout<<"\n";
}

void dfs(int tian,int i,int zuo,int you)
//后两个参数用于记录目前左括号个数和右括号个数
{
    if(zuo>n||you>n||you>zuo)
    //出界的滚啊
    //右括号多于左括号，退出
        return;
    if(tian==1)
    {
        out[i]=1;
        dfs(2,i+1,zuo,you+1);
        //填了左括号就优先填右括号
        dfs(1,i+1,zuo+1,you);
    }
    if(tian==2)
    {
        out[i]=2;
        dfs(2,i+1,zuo,you+1);
        //填了右括号也优先填右括号
        dfs(1,i+1,zuo+1,you);
    }
    if((zuo==you)&&(zuo+you==2*n)&&(i==(2*n-1)))
    //搞定了满足条件的一种情况
    //全部填完了再输出他
    {
        shuchu(out,n);
        sumout++;
        return;
    }
}

int main()
{
    cin>>n;
    dfs(1,0,1,0);//从0开始填左括号
    cout<<sumout;
    return 0;
}
