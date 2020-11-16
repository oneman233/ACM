#include <iostream>
#include <string>
#include <vector>

using namespace std;

int huiwen(string str)
{
    int len=str.length();
    vector<vector<int> > dp(len,vector<int>(len));
     //dp����len��ֵΪvector<int>(len)��vector<int>����Ԫ��
     //����ÿ��vector<int>����len����
     //�൱��һ����ά����
    for(int j=0;j<len;j++)
    //j�Ǵ�ǰ����
    {
        dp[j][j]=1;
        //��ʼ����
        for(int i=j-1;i>=0;i--)
        //i�ǴӺ���ǰ
        {
            dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
            if(str[i]==str[j])
                dp[i][j]+=1+dp[i+1][j-1];
        }
    }
    return dp[0][len-1];
    //�����������еĳ���
}
int main()
{
    string str;
    cin>>str;
    cout<<huiwen(str);
    return 0;
}
