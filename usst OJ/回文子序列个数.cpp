#include <iostream>
#include <string>
#include <vector>

using namespace std;

int huiwen(string str)
{
    int len=str.length();
    vector<vector<int> > dp(len,vector<int>(len));
     //dp包含len个值为vector<int>(len)的vector<int>类型元素
     //其中每个vector<int>包含len个零
     //相当于一个二维数组
    for(int j=0;j<len;j++)
    //j是从前往后
    {
        dp[j][j]=1;
        //初始条件
        for(int i=j-1;i>=0;i--)
        //i是从后往前
        {
            dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
            if(str[i]==str[j])
                dp[i][j]+=1+dp[i+1][j-1];
        }
    }
    return dp[0][len-1];
    //返回整个队列的长度
}
int main()
{
    string str;
    cin>>str;
    cout<<huiwen(str);
    return 0;
}
