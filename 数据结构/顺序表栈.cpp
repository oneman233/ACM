#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

const int Max = 100;

struct ssta
{
    int data[Max];
    int topp;
    ssta()
    {
        _for(i,0,Max)
            data[i] = 0;
        topp = 0;
    }
    void push(int x)
    {
        if(topp == Max-1)/*出界判断*/
            return;
        data[topp] = x;
        ++topp;
    }
    void pop()
    {
        if(topp-1 < 0)/*出界判断*/
            return;
        data[topp] = 0;
        --topp;
    }
    int top()
    {
        return data[topp-1];
    }
};

int main()
{
    ssta ss;
    ss.push(5);
    ss.push(7);
    cout<<ss.top()<<endl;
    ss.pop();
    cout<<ss.top()<<endl;
    return 0;
}
