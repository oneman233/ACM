#include <bits/stdc++.h>
using namespace std;

struct dnode
{
    int n;
    dnode* pre;
    dnode* next;
    void inser(int x)//Î²²å
    {
        dnode* ne = (dnode*)malloc(sizeof(dnode));
        dnode* p = this;
        while(p->next != NULL)
            p = p->next;
        ne->n = x;
        ne->next = NULL;
        ne->pre = p;
        p->next = ne;
    }
    void put()//Êä³ö
    {
        dnode* p = this->next;
        while(p != NULL)
        {
            cout<<p->n<<" ";
            p = p->next;
        }
    }
    int quest(int x)
    {
        dnode* p = this->next;
        int cnt=1;
        while(p->n != x)
        {
            p = p->next;
            if(p == NULL)
                return -1;
            ++cnt;
        }
        return cnt;
    }
    int del(int pos)
    {
        int cnt=1;
        dnode* p = this->next;
        while(cnt < pos)
        {
            ++cnt;
            p = p->next;
        }
        p->pre->next = p->next;
        p->next->pre = p->pre;
        free(p);
    }
};

int main()
{
    dnode* head = (dnode*)malloc(sizeof(dnode));
    head->pre = NULL;
    head->next = NULL;
    head->inser(1);
    head->inser(5);
    head->inser(9);
    cout<<head->quest(5)<<endl;
    head->put();
    cout<<endl;
    head->del(head->quest(5));
    head->put();
    return 0;
}
