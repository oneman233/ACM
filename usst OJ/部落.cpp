#include <bits/stdc++.h>

using namespace std;

int father[10001];
set<int> s;

int zhao(int x)
{
    if(x!=father[x])
        return zhao(father[x]);
    else
        return x;
}

int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<10001;i++)
        father[i]=i;//清空数据
    while(n--)
    {
        int m;
        cin>>m;
        int num,root;
        cin>>root;
        //读取根节点
        s.insert(root);
        //把根节点插入集合
        //直接取第一个数作为根节点
        for(i=1;i<m;i++)
        {
            cin>>num;
            s.insert(num);
            father[zhao(num)]=root;
        }
    }
        cout<<s.size();
        set<int> s2;
        set<int>::iterator it;
        for(it=s.begin();it!=s.end();it++)
        //不能用判断大于小于
        {
            s2.insert(zhao(*it));
            //把it迭代器找到的根节点插入s2当中
            //插入时会自动去重，根结点个数一定
            //访问it迭代器的内容需要*运算符
        }
        cout<<" "<<s2.size()<<endl;
        int l;
        cin>>l;
        while(l--)
        {
            int a,b;
            cin>>a>>b;
            if(zhao(a)==zhao(b))
            {
                cout<<"Y"<<endl;
            }
            else
            {
                cout<<"N"<<endl;
            }
        }
    return 0;
}
