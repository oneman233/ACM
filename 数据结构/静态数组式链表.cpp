#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;

const int Max = 100;

struct snode
{
    int data[Max];
    int next[Max];
    bool fre[Max];
    snode()
    {
        _for(i,0,Max)//数据区清空
            data[i] = 0;
        _for(i,0,Max)//指针区清空
            next[i] = -1;
        _for(i,0,Max)//空闲区重置
            fre[i] = true;
        fre[0] = false;//头指针默认被占用
    }
    void inser(int x)
    {
        int frep = 0;
        while(fre[frep] != true)//找到第一个空闲区的指针
            frep++;
        data[frep] = x;
        int p = 0;
        while(next[p] != -1)//找到链表末尾
            p = next[p];
        next[p] = frep;
        fre[frep] = false;
    }
    void put()
    {
        int p = next[0];
        while(p != -1)
        {
            cout<<data[p]<<" " ;
            p = next[p];
        }
        cout<<endl;
    }
};

int main()
{
    snode head;
    head.inser(5);
    head.inser(9);
    head.inser(7);
    head.put();
    return 0;
}
