#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<b;++i)
using namespace std;

int cur=0;
char ans[100010];
string s;
bool vis[1000];
int n[1000];
///�ַ�������ʵ������int�����ݣ���С����̫��
///Ҳ������ٶȿ���map��

int main()
{
    cin>>s;
    int len=s.length();
    _for(i,0,len)
    {
        vis[s[i]]=false;
        n[s[i]]++;
    }
    _for(i,0,len)
    {
        n[s[i]]--;
        if(vis[s[i]]==true)
            continue;
        while(cur>0&&n[ans[cur]]>0&&s[i]<ans[cur])
        ///������ж�
        ///�±����0,��ǰansλ���ϵ����ֻ���ʣ��,����s[i]�ֵ���С
        {
            vis[ans[cur]]=false;
            cur--;
        }
        ///��ÿһ��s[i]�����л���ֱ���ҵ�����λ��
        cur++;
        ans[cur]=s[i];
        ///��s[i]��������һ��λ�ã�
        ///��������С���ֵ��������1��λ��
        ///�������С���������һ���ַ���β�ͺ���
        ///ǰ����ans[cur]��ǰλ���ϵ��ַ��ں��滹�г��ֵĻ���
        vis[s[i]]=true;
    }
    _for(i,1,cur+1)
    ///�����±�����Ǵ�1��ʼ
        cout<<ans[i];
    return 0;
}
