#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,k;//������
    int dif=0;//��ͬ�Ķ���
    unsigned long long n;//�ַ�������
    string s1,s2;
    cin>>n;
    cin>>s1;
    cin>>s2;
    if(s1==s2)//ÿ����һ��
    {
        cout<<(n+1)*n/2;
        return 0;
    }
    else
    {
        for(i=0;i<n;i++)
        {
            if(s1[i]==s2[i])
                break;
        }
        if(i==n)//ÿ������һ��
        {
            cout<<(n-1)*2;
            return 0;
        }
        else
        {
            i=0;
            int len=0;//��ͬ���ַ����ĳ���
            while(i<n)
            {
                if(s1[i]!=s2[i])
                {
                    dif++;
                    if(dif==3)
                    {
                        cout<<0;
                        return 0;
                    }
                    while(s1[i]!=s2[i])
                    {
                        i++;
                        len++;
                    }
                    continue;
                }
                i++;
            }
            if(dif==2)
            {
                cout<<6;
                return 0;
            }
            else
            {
                cout<<(len-1)*2+(n-len)*2;
            }
        }
    }
    return 0;
}
