#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int Max=100000;

string s;

string malache()
{
    string snew = "$#";
    _for(i,0,s.length())
    {
        snew.append(1,s[i]);
        snew.append(1,'#');
    }
    int len = snew.length();
    vector<int> p(len, 0);
    ///cout<<snew<<endl;
    int right_limit=0,center=0;
    ///�ұ߽�����ĵ�
    int ans_pos=0,ans_len=0;
    ///�����������Ӵ������ĵ�ͳ���
    _for(i,1,len)
    {
        if(i < right_limit)
            p[i] = min(p[2*center-i], right_limit-i);
            ///������ұ߽��ڣ����ǶԳƵ�İ뾶�Լ�Ŀǰ��֪�����뾶
        else
            p[i] = 1;
            ///�����ұ߽������޷������ж�
        ///ʵ���������ifelse��Ϊ��ȷ��һ��������׼ֵ��
        while(snew[i-p[i]] == snew[i+p[i]])
            ++p[i];
        ///��������p[i]
        if(i+p[i] > right_limit)
        {
            right_limit = i+p[i];
            center = i;
        }
        ///�����ұ߽��Լ����ĵ�
        if(ans_len < p[i])
        {
            ans_len = p[i];
            ans_pos = i;
        }
        ///���´�
    }
    string ans="";
    _for(i,ans_pos-ans_len+1,ans_pos+ans_len)
    ///���ڰ뾶�����˱������Ա�����Χʵ����Ӧ����[pos-len+1,pos+len-1]
    {
        if(snew[i] != '#' && snew[i] != '$')
            ans.append(1,snew[i]);
    }
    return ans;
}

int main()
{
    while(cin>>s)
        cout<<malache()<<endl;
    return 0;
}
