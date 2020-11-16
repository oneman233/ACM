#include <bits/stdc++.h>
using namespace std;

struct node
{
    int n;
    node* next;
    void inser(int x, int idx)//插入某一个数字到指定位置的节点后
    {
        int cnt=1;
        node* p = this->next;
        while(cnt != idx)
        {
            cnt++;
            p=p->next;
            if(p == NULL)
                return;//出界判断
        }
        node* ne = (node*)malloc(sizeof(node));
        ne->n = x;
        ne->next = p->next;
        p->next = ne;
    }
    void inser(int x)//尾插
    {
        node* p = this;
        while(p->next != NULL)
            p = p->next;
        node* ne = (node*)malloc(sizeof(node));
        ne->n = x;
        ne->next = NULL;
        p->next = ne;
    }
    void del(int pos)//删除指定位置的节点
    {
        int cnt=1;
        node* p = this->next;
        while(cnt != pos-1)
        {
            p = p->next;
            if(p == NULL)
                return;//出界判断
            ++cnt;
        }
        node* q = p->next;
        p->next = p->next->next;
        free(q);
    }
    int quest(int val)//查找某一值对应的下一个节点
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
    int put()//按序输出
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
    head->inser(10, 2);//把10插在第二个位置后面的节点
    head->put();
    cout<<endl;
    head->del(head->quest(10));
    head->put();
    return 0;
}
/*malloc需要强制类型转换一下*/
