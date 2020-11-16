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
    ///右边界和中心点
    int ans_pos=0,ans_len=0;
    ///储存最大回文子串的中心点和长度
    _for(i,1,len)
    {
        if(i < right_limit)
            p[i] = min(p[2*center-i], right_limit-i);
            ///如果在右边界内，则考虑对称点的半径以及目前已知的最大半径
        else
            p[i] = 1;
            ///不在右边界内则无法进行判断
        ///实际上上面的ifelse是为了确定一个“最大基准值”
        while(snew[i-p[i]] == snew[i+p[i]])
            ++p[i];
        ///更新最大的p[i]
        if(i+p[i] > right_limit)
        {
            right_limit = i+p[i];
            center = i;
        }
        ///更新右边界以及中心点
        if(ans_len < p[i])
        {
            ans_len = p[i];
            ans_pos = i;
        }
        ///更新答案
    }
    string ans="";
    _for(i,ans_pos-ans_len+1,ans_pos+ans_len)
    ///由于半径包括了本身，所以遍历范围实际上应该是[pos-len+1,pos+len-1]
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
