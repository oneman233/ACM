#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int Max=10000;

string s,p;
///原字符串和待匹配字符串
int last[Max];
///next数组，储存最长相同前后缀

void cal_next()
{
    last[0] = -1;
    ///第一个字符没有最长前后缀，因为最长相同前后缀均不包括本身
    int val = -1;
    ///储存上一个最长相同前后缀的值
    int len = s.length();
    _for(i,1,len)
    ///第一个字符不可遍历！
    {
        while(val > -1 && s[val+1] != s[i])
            val = last[val];
        ///如果还有最长相同前后缀，则必须尽量查找，给出next[i]尽可能大的初始值
        ///每一次查找都直接跳到前缀字串的前缀字串里去即可
        if(s[val+1] == s[i])
            val++;
        ///如果找到相同的前缀和后缀，则加一
        ///如果未找到，则val一直是-1，说明它没有最长相同前后缀
        last[i] = val;
    }
/*
    _for(i,0,len)
        cout<<last[i]<<" ";
    cout<<endl;
*/
}

int kmp()
{
    cal_next();
    int val = -1;
    int len = s.length();
    _for(i,0,len)
    {
        while(val >-1 && p[val+1] != s[i])///向前回溯
            val = last[val];
        if(p[val+1] == s[i])///找到了最长相同前后缀
            ++val;
        if(val == p.length()-1)
        ///如果某一个最长相同前后缀长度为p.length()-1，说明已经找到
        ///因为在储存last数组的时候我都减了1
            return i-val;
            ///若需多次查找，令val=-1,i=i-val+1即可
    }
    return -1;///未找到
}

///最长相同前后缀如果增加，应该考虑是缓慢+1的形式

int main()
{
    while(cin>>s>>p)
        cout<<kmp()<<endl;
    return 0;
}
