#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;

typedef long long ll;
const int MAX=1000005;
ll dp[MAX][4];
char s[MAX+5];

int main()
{
    scanf("%s",s+1);
    int len=strlen(s+1);
    dp[0][0]=1;
    _for(i,1,len+1)
    {
        _for(j,0,4)
        {
            if(dp[i-1][j]==0)
            //�ٶ�ɾ���ַ��Ѿ�û��������
                continue;
            if(j<3)
            //ɾ����ǰ�ַ������������һ���ַ�
                dp[i][j+1]+=dp[i-1][j];
            dp[i][j]+=dp[i-1][j];
            for(int k=i-1;k>=1&&i-k<=j;k--)
            {
                if(s[k]==s[i])
                {
                    dp[i][j]-=dp[k-1][j-(i-k)];
                    //�ҵ���һ����i��ͬ���ַ�����������ɾ�����ַ�������
                    break;
                }
            }
        }
    }
    printf("%lld",dp[len][0]+dp[len][1]+dp[len][2]+dp[len][3]);
    return 0;
}
