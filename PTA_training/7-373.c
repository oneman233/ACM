#include <stdio.h>
#include <string.h>

int main()
{
    int x,y,len,max1=1,ans=0,i;
    char s[2000];
    gets(s);
    len=strlen(s);
        for(i=0;i<len;i++)
        {
            ans=0;
            x=i;
            y=i+1;
            while(s[x]==s[y]&&x>=0&&y<len)
            {
                x--;
                y++;
                ans+=2;
            }
            if(ans>max1)
                max1=ans;
        }
        for(i=1;i<len-1;i++)
        {
            ans=1;//����������е�ʱ������1��ʼ
            x=i-1;
            y=i+1;
            while(s[x]==s[y]&&x>=0&&y<len)
                {
                x--;
                y++;
                ans+=2;
            }
            if(ans>max1)
                max1=ans;
        }
        printf("%d",max1);//������ż�����ж�Ҫ���м�飬����������
    return 0;
}
