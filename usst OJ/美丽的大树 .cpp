#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i;
    int hang1[101];
    int hang2[101];
    //��������-1��ʾ���ﱾ����û����0��ʾ����͵��
    memset(hang1,-1,sizeof(hang1));
    memset(hang2,-1,sizeof(hang2));
    for(i=1;i<=100;i++)
    {
        if(i%2==0)
            hang2[i]=1;//ż����
        else
            hang1[i]=1;//������
    }
    int n,dao;//���汻����ľ�����ͱ��������
    int tou,wei,maxlen=0,len=0;
    cin>>n;
    while(n--)//͵��
    {
        scanf("%d",&dao);
        if(dao%2==0)
            hang2[dao]=0;
        else
            hang1[dao]=0;
    }
    for(i=1;i<=99;i+=2)
    {
        if(hang1[i]==1)
        {
            len++;
            if(len>maxlen)
            {
                wei=i;
                maxlen=len;
            }
        }
        else
            len=0;
    }
    len=0;
    for(i=2;i<=100;i+=2)
    {
        if(hang2[i]==1)
        {
            len++;
            if(len>maxlen)
            {
                wei=i;
                maxlen=len;
            }
        }
        else
            len=0;
    }
    if(wei%2==0)
        tou=(wei/2-maxlen+1)*2;
    else
        tou=((wei-1)/2-maxlen+1)*2+1;
    printf("%d %d",tou,maxlen);
    return 0;
}
