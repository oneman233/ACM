#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a[100010],ans=10000000;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    int ansi;
    for(int i=1;i<=100000;++i)///��ÿһ�����ܵ��յ�
    {
        int cnt=0;///������
        bool can=true;///�ܷ�ʹ��ȫ�����ִֵ��յ�
        for(int j=0;j<n;++j)///ö�ٸ����еĸ���ֵ
        {
            int tmp=a[j];
            int contri=
            for(int i=0;tmp>=1;++i)
            {

            }
            ///�޸�����
            if(tmp!=i)
            {
                can=false;
                break;
            }
        }
        if(cnt==0)
        {
            printf("0");
            return 0;
        }
        if(ans>cnt&&can)
        {
            ans=cnt;
            ansi=i;
        }
    }
    cout<<ansi<<endl;
    printf("%d",ans);
    return 0;
}
