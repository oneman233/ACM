#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int Max=10000;

string s,p;
///ԭ�ַ����ʹ�ƥ���ַ���
int last[Max];
///next���飬�������ͬǰ��׺

void cal_next()
{
    last[0] = -1;
    ///��һ���ַ�û���ǰ��׺����Ϊ���ͬǰ��׺������������
    int val = -1;
    ///������һ�����ͬǰ��׺��ֵ
    int len = s.length();
    _for(i,1,len)
    ///��һ���ַ����ɱ�����
    {
        while(val > -1 && s[val+1] != s[i])
            val = last[val];
        ///����������ͬǰ��׺������뾡�����ң�����next[i]�����ܴ�ĳ�ʼֵ
        ///ÿһ�β��Ҷ�ֱ������ǰ׺�ִ���ǰ׺�ִ���ȥ����
        if(s[val+1] == s[i])
            val++;
        ///����ҵ���ͬ��ǰ׺�ͺ�׺�����һ
        ///���δ�ҵ�����valһֱ��-1��˵����û�����ͬǰ��׺
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
        while(val >-1 && p[val+1] != s[i])///��ǰ����
            val = last[val];
        if(p[val+1] == s[i])///�ҵ������ͬǰ��׺
            ++val;
        if(val == p.length()-1)
        ///���ĳһ�����ͬǰ��׺����Ϊp.length()-1��˵���Ѿ��ҵ�
        ///��Ϊ�ڴ���last�����ʱ���Ҷ�����1
            return i-val;
            ///�����β��ң���val=-1,i=i-val+1����
    }
    return -1;///δ�ҵ�
}

///���ͬǰ��׺������ӣ�Ӧ�ÿ����ǻ���+1����ʽ

int main()
{
    while(cin>>s>>p)
        cout<<kmp()<<endl;
    return 0;
}
