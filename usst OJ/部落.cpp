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
        father[i]=i;//�������
    while(n--)
    {
        int m;
        cin>>m;
        int num,root;
        cin>>root;
        //��ȡ���ڵ�
        s.insert(root);
        //�Ѹ��ڵ���뼯��
        //ֱ��ȡ��һ������Ϊ���ڵ�
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
        //�������жϴ���С��
        {
            s2.insert(zhao(*it));
            //��it�������ҵ��ĸ��ڵ����s2����
            //����ʱ���Զ�ȥ�أ���������һ��
            //����it��������������Ҫ*�����
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
