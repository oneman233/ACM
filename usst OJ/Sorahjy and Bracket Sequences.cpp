#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
//我没想到十万就过了orz

int main()
{
    ll ans=0;
    //用来保存答案
    ll zuoyou[2][100005];
    //用来保存各个字符串剩余左括号和右括号数的数组
    //第一个下标0代表左括号，1代表右括号
    //最坏的情况是三十万个左括号或三十万个右括号
    int n;
    string temp;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        ll left=0,right=0;
        for(int j=0;j<temp.length();j++)
        {
            if(temp[j]==')')
            {
                if(left)
                    left--;
                    //如果查找到右括号并且前面有左括号
                    //则二者匹配，左括号剩余数减一
                else
                    right++;
                    //如果查找到右括号并且前面没有左括号
                    //则右括号剩余数加一
            }
            else
                left++;
                //检测到左括号的话直接加一
                //因为匹配永远是按照()的格式执行的
        }
        if(left&&right)
            continue;
            //如果左右均有剩余，那么它不能与任何一个括号匹配
            //直接从答案中排除即可
        if(left)
            zuoyou[0][left]++;//剩余left个左括号的情况加一
        else if(right)
            zuoyou[1][right]++;//剩余right个右括号的情况加一
        else
            ans++;
            //恰好完全匹配，这意味着他可以再与自身匹配一次
            //并且他可以与所有其他的完全匹配的字符串匹配
    }
    ans*=ans;
    //处理完全匹配的字符串
    //完全匹配的字符串可以互相两两匹配
    //匹配种数有n+2*(n-1)+2*(n-2)+...+2*1种
    //其中n是自己匹配，其余项是两两匹配
    for(int i=0;i<100005;i++)
        ans+=zuoyou[0][i]*zuoyou[1][i];
        //剩余相同右括号与左括号的字符串只能单向匹配
        //匹配种数只有m*n种
    cout<<ans<<endl;
    return 0;
}
