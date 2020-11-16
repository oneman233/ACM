#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

struct tree
{
    int data;
    tree* l;
    tree* r;
};

int main()
{
    tree* head = (tree*)malloc(sizeof(tree));
    head->l = NULL;
    head->r = NULL;
    /*头节点初始化*/
    return 0;
}
