#include <bits/stdc++.h>
using namespace std;

/*交换数据的模板函数*/
template <typename T>
void chan(T& a,T& b)
{
    T c = a;
    a = b;
    b = c;
}

/*由小到大排序*/
void qsort(int n[], int s, int e)
{
    if(s > e)
        return;/*预防出界*/
    int i = s,j = e;/*两个指针*/
    int flag = n[s];/*找到根*/
    while(i < j)
    {
        while(j > i && n[j] >= flag)
            j--;
        n[i]=n[j];/*较小的移到左边*/
        while(i < j && n[i] <= flag)
            i++;
        n[j]=n[i];/*较大的移到左边*/
    }
    /*遍历终点是i==j*/
    n[i] = flag;
    /*i下标的位置实际上作为了一个“坑”，用来临时存储数据，现在需要把根还原*/
    for(int i=0;i<5;i++)
        cout<<n[i]<<" ";
    cout<<endl;
    /*查看排序结果*/
    qsort(n, s, i-1);
    qsort(n, i+1, e);
}

int main()
{
    int n[5]={5,6,3,8,4};
    qsort(n, 0, 4);
    return 0;
}
