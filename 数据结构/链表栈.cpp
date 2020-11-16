#include <bits/stdc++.h>
using namespace std;

struct sta
{
    int data;
    sta* next;
    void push(int x)
    {
        sta* p = this;
        while(p->next != NULL)
            p = p->next;
        sta* ne = (sta*)malloc(sizeof(sta));
        ne->data = x;
        ne->next = NULL;
        p->next = ne;
    }
    void pop()
    {
        if(this->next == NULL)
            return;
        sta* p = this;
        while(p->next != NULL)
            p = p->next;
        sta* q = this;
        while(q->next != p)
            q = q->next;
        free(p);
        q->next = NULL;
    }
    int top()
    {
        sta* p = this;
        while(p->next != NULL)
            p = p->next;
        return p->data;
    }
};

int main()
{
    sta* head = (sta*)malloc(sizeof(sta));
    head->next = NULL;
    head->push(5);
    head->push(9);
    head->push(3);
    cout<<head->top()<<endl;
    head->pop();
    cout<<head->top()<<endl;
    return 0;
}
