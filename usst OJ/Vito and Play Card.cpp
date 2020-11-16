#include <bits/stdc++.h>

using namespace std;

double p[25];

int main()
{
	int n,geshu=0;
	int i,j;
	double fenmu=0.0,out=0.0;
	//fenmu用于保存分母，out是最后的输出值
	scanf("%d",&n);
	for(i=0;i<n;i++)
        scanf("%lf",&p[i]);
    for(i=1;i<(1<<n);i++)
    //i等于1开始是防止所有值都等于0的鬼畜情况
    //这种情况下fenmu=0
    {
        geshu=0;
        fenmu=0.0;
        for(j=0;j<n;j++)
        {
            if(i&(1<<j))//i&10表示取二进制i的倒数第二位，以此类推
            {
                fenmu+=p[j];
                geshu++;
            }
        }
        //奇加偶减
        if((geshu&1)==1)//如果最后一位是1，那么是奇数
            out+=1.0/fenmu;
        else
            out-=1.0/fenmu;
    }
    printf("%.5lf",out);
    return 0;
}
