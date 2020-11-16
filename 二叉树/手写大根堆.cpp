#include <bits/stdc++.h>
using namespace std;
const int maxn=10000005;

int n;
int a[maxn],b[maxn];
int heap[maxn],sz=0;

void change(int i,int j)
{
    int tmp=heap[i];
    heap[i]=heap[j];
    heap[j]=tmp;
}

void up(int p)
{
    while(p/2>=1){
        if(heap[p]>heap[p/2]){
            change(p,p/2);
            p/=2;
        }
        else
            break;
    }
}

void lowin(int val)
{
    heap[++sz]=val;
    up(sz);
}

void down(int p)
{
    int s=p*2;
    while(s<=sz){
        if(s+1<=sz&&heap[s]<heap[s+1])
            s++;
        if(heap[s]>heap[p]){
            change(s,p);
            p=s;
            s=p*2;
        }
        else
            break;
    }
}

void highin(int val)
{
    heap[1]=val;
    down(1);
}

void del(int val)
{
    int p=1;
    while(p<=sz&&heap[p]!=val)
        p++;
    change(p,sz);
    sz--;
    down(p);
}

int top()
{
    return heap[1];
}

int main()
{
    lowin(5);
    lowin(9);
    lowin(2);
    lowin(10);
    lowin(6);
    lowin(11);
    cout<<top()<<endl;
    del(2);
    del(5);
    cout<<top()<<endl;
    return 0;
}
