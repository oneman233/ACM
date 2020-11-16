#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define sci(a) scanf("%d",&a)
#define scll(a) scanf("%lld",&a)
#define scc(a) scanf("%c",&a)
#define pb(a) push_back(a)
#define prti(a) printf("%d\n",a)
#define prtll(a) printf("%lld\n",a)
using namespace std;
typedef long long ll;
const int Max=100000;
const ll mod=998244353;

bool cmp(int a,int b)
{
    return a>b?true:false;
}

int minswap(vector<int> a,bool flag)
{
    vector<int> b(a);///��������
    if(flag)
        sort(b.begin(),b.end());
    else
        sort(b.begin(),b.end(),cmp);
    ///flagΪ1����С����Ϊ0���ɴ�С
    map<int,int> m;
    int len=b.size();
    _for(i,0,len)
        m[b[i]]=i;
    ///m������������е�ĳ������Ӧ���ڵ�λ��
    vector<bool> isask(len,false);///��ʾ�Ƿ񱻷���
    int loop=0;///ѭ���ڸ���
    _for(i,0,len)
    {
        if(!isask[i])
        {
            int j=i;
            while(!isask[j])
            {
                isask[j]=true;
                j=m[a[j]];
                ///jҪ���������Ӧ���ڵ�λ����ȥ��������
                ///���������ֱ�����������ռ�ݣ���Ҫȥ�����Ǹ�����Ӧ���ڵ�λ��
                ///ֱ������һ��������û�л����������ֶ���������һ��
            }
            loop++;
        }
    }
    return len-loop;
}

int main()
{
    int n,read;
    vector<int> a,b;
    sci(n);
    _for(i,0,n)
    {
        sci(read);
        a.pb(read);
    }
    _for(i,0,n)
    {
        sci(read);
        b.pb(read);
    }
    prti(min((minswap(a,1)+minswap(b,0)),(minswap(a,0)+minswap(b,1))));
    ///��һ������ֻ��Ҫ��������ƥ�����
    return 0;
}
