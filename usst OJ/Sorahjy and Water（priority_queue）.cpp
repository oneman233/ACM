#include <bits/stdc++.h>

using namespace std;

long n,v,c;

int main()
{
	scanf("%ld %ld %ld",&n,&v,&c);
	long a[n],h[n];
	long s;
	for(int i = 0; i< n;i++)
    {
		scanf("%ld",&a[i]);
		s+=a[i];//���
	}
	for(int i = 0; i< n;i++)
	{
		scanf("%ld",&h[i]);
	}
	double rc = (double)v*a[0]/s;//Ŀǰ�ĳ�ˮ��
	if(rc >= c)//����Ҫ�ر�
    {
		printf("0");
		return 0;
	}
	else//��Ҫ�ر�
	{
        priority_queue<long> pq;
        for(int i = 0; i < n;i++)
        {
            if(h[i] == 0)
            {
                pq.push(a[i]);//�������
            }
        }
		long count = 0;
		while(1)
		{
			long m = pq.top();
            pq.pop();
			s -= m;
			count++;
			rc = (double)v*a[0]/s;
			if(rc >= c)
            {
				printf("%ld",count);
				break;
			}
            else
            {
				continue;
			}
		}
	}
	return 0;
}
