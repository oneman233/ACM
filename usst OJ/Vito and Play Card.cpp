#include <bits/stdc++.h>

using namespace std;

double p[25];

int main()
{
	int n,geshu=0;
	int i,j;
	double fenmu=0.0,out=0.0;
	//fenmu���ڱ����ĸ��out���������ֵ
	scanf("%d",&n);
	for(i=0;i<n;i++)
        scanf("%lf",&p[i]);
    for(i=1;i<(1<<n);i++)
    //i����1��ʼ�Ƿ�ֹ����ֵ������0�Ĺ������
    //���������fenmu=0
    {
        geshu=0;
        fenmu=0.0;
        for(j=0;j<n;j++)
        {
            if(i&(1<<j))//i&10��ʾȡ������i�ĵ����ڶ�λ���Դ�����
            {
                fenmu+=p[j];
                geshu++;
            }
        }
        //���ż��
        if((geshu&1)==1)//������һλ��1����ô������
            out+=1.0/fenmu;
        else
            out-=1.0/fenmu;
    }
    printf("%.5lf",out);
    return 0;
}
