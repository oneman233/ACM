#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<b;++i)
using namespace std;

int cur=0;
char ans[100010];
string s;
bool vis[1000];
int n[1000];
///字符型数据实际上是int型数据，大小不会太大
///也许查找速度快于map？

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
        ///插入的判断
        ///下标大于0,当前ans位置上的数字还有剩余,并且s[i]字典序小
        {
            vis[ans[cur]]=false;
            cur--;
        }
        ///对每一个s[i]都进行回退直到找到插入位置
        cur++;
        ans[cur]=s[i];
        ///把s[i]放在这样一个位置：
        ///若她是最小的字典序，则放在1的位置
        ///否则放在小于她的最后一个字符的尾巴后面
        ///前提是ans[cur]当前位置上的字符在后面还有出现的机会
        vis[s[i]]=true;
    }
    _for(i,1,cur+1)
    ///上面下标控制是从1开始
        cout<<ans[i];
    return 0;
}
