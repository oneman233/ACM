#include <bits/stdc++.h>
#define _rep(i,a,b) for(int i=a;i<=b;++i)
#define pub(a) push_back(a)
#define puf(a) push_front(a)
#define pof() pop_front()
#define pob() pop_back()
using namespace std;
typedef long long ll;
const int Max=1000000;

int s,t;
ll sum[Max+10];
deque<int> q;
///����������к͵��±�
///�����С
ll ans=-1000000;

int main()
{
    cin>>s>>t;
    sum[0]=0;
    _rep(i,1,s)
    {
        cin>>sum[i];
        sum[i]+=sum[i-1];
    }
    ///��ǰ׺������
    bool allnega=true;
    _rep(i,0,s-1)
    {
        if(sum[i+1]-sum[i]>0)
        {
            allnega=false;
            break;
        }
    }
    if(allnega)
    ///����һ��ȫΪ���������
    {
        _rep(i,0,s-1)
            ans=max(ans,sum[i+1]-sum[i]);
        cout<<ans;
        return 0;
    }
    q.pub(0);
    _rep(i,1,s)
    ///������ǰ׺�ͽ�С��λ�ñ�������
    ///����취������λ��
    ///��֤���д��ڵ���״̬
    {
        while(!q.empty()&&sum[i]<q.front())
            q.pof();///�ȶ����
        q.puf(i);
        ///q�����±��Ƿ������
        while(!q.empty()&&q.front()-q.back()>t)
            q.pob();///�ٶ�С��
        ans=max(ans,sum[q.front()]-sum[q.back()]);
    }
    cout<<ans;
    return 0;
}
