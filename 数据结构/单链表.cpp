#include <bits/stdc++.h>
using namespace std;

struct node
{
    int n;
    node* next;
    void inser(int x, int idx)//����ĳһ�����ֵ�ָ��λ�õĽڵ��
    {
        int cnt=1;
        node* p = this->next;
        while(cnt != idx)
        {
            cnt++;
            p=p->next;
            if(p == NULL)
                return;//�����ж�
        }
        node* ne = (node*)malloc(sizeof(node));
        ne->n = x;
        ne->next = p->next;
        p->next = ne;
    }
    void inser(int x)//β��
    {
        node* p = this;
        while(p->next != NULL)
            p = p->next;
        node* ne = (node*)malloc(sizeof(node));
        ne->n = x;
        ne->next = NULL;
        p->next = ne;
    }
    void del(int pos)//ɾ��ָ��λ�õĽڵ�
    {
        int cnt=1;
        node* p = this->next;
        while(cnt != pos-1)
        {
            p = p->next;
            if(p == NULL)
                return;//�����ж�
            ++cnt;
        }
        node* q = p->next;
        p->next = p->next->next;
        free(q);
    }
    int quest(int val)//����ĳһֵ��Ӧ����һ���ڵ�
    {
        int cnt=1;
        node* p = this->next;
        while(p->n != val && p->next != NULL)
        {
            p = p->next;
            ++cnt;
        }
        if(p == NULL)
            return -1;
        else
            return cnt;
    }
    int put()//�������
    {
        node* p = this->next;
        while(p != NULL)
        {
            cout<<p->n<<" ";
            p = p->next;
        }
    }
};

int main()
{
    node* head = (node*)malloc(sizeof(node));
    head->next = NULL;
    head->inser(1);
    head->inser(3);
    head->inser(9);
    head->inser(10, 2);//��10���ڵڶ���λ�ú���Ľڵ�
    head->put();
    cout<<endl;
    head->del(head->quest(10));
    head->put();
    return 0;
}
/*malloc��Ҫǿ������ת��һ��*/
