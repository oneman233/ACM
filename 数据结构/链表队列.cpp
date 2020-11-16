#include <bits/stdc++.h>
using namespace std;

struct slist
{
    int data;
    slist* next;
    slist* pre;
    void push(int x)
    {
        slist* p = this;
        while(p->next != NULL)
            p = p->next;
        slist* ne = (slist*)malloc(sizeof(slist));
        ne->data = x;
        ne->next = NULL;
        ne->pre = p;
        p->next = ne;
    }
    void pop()
    {
        slist* p = this->next;
        slist* q = this->next->next;
        this->next = q;
        q->pre = this;
        free(p);
    }
    void put()
    {
        slist* p = this->next;
        while(p != NULL)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<endl;
    }
};

int main()
{
    slist* head = (slist*)malloc(sizeof(slist));
    head->next = NULL;
    head->pre = NULL;
    ///³õÊ¼»¯
    head->push(5);
    head->push(9);
    head->push(2);
    head->put();
    head->pop();
    head->push(10);
    head->put();
    head->pop();
    head->put();
    return 0;
}
