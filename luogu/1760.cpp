#include<bits/stdc++.h>
using namespace std;
    int a;
    stringstream b;
    string c;
int main()
{
    cin>>a;
    b.precision(0);//�����С��λ
    b<<fixed<<pow(2.0L,a);
    //fixed����һ�㷽ʽ��������������ǿ�ѧ������
    //2.0L������long double
    c=b.str();
    c[c.length()-1]--;//��һ����
    cout<<c;
}
