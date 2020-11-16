#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;

const int MAX=100;

struct slist
{
    int num[MAX];
    int len;
    slist()
    {
        memset(num,0,sizeof(num));
        len=0;
    }
    void inser(int x)
    {
        if(len+1 == MAX)
            return;
        num[len] = x;
        ++len;
    }
    void inser(int x,int pos)
    {
        for(int i=len;i>=pos+1;i--)
            num[i] = num[i-1];
        num[pos] = x;
        len++;
    }
    void del(int pos)
    {
        _for(i,pos,len-1)
            num[i] = num[i+1];
        num[len-1] = 0;
        len--;
    }
    void qsor(int s, int e)/*¿ìÅÅ*/
    {
        int i=s,j=e;
        int flag = num[s];
        if(s>e)
            return;
        while(i < j)
        {
            while(i < j && num[j] >= flag)
                j--;
            num[i] = num[j];
            while(i < j && num[i] <= flag)
                i++;
            num[j] = num[i];
        }
        num[i] = flag;
        qsor(s, i-1);
        qsor(i+1, e);
    }
    void put()
    {
        _for(i,0,len)
            cout<<num[i]<<" ";
        cout<<endl;
    }
    int quest(int val)
    {
        _for(i,0,len)
        {
            if(num[i] == val)
                return i;
        }
        return -1;
    }
};

int main()
{
    slist sl = slist();
    int read;
    while(1){
        if(!scanf("%d",&read)){
            fflush(stdin);
            cout<<"Error!"<<endl;
            continue;
        }
        sl.inser(read);
        sl.qsor(0,sl.len-1);
        sl.put();
    }
    return 0;
}
