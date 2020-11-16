#include <iostream>

using namespace std;

static int num[10]={5,6,9,2,3,4,7,8,1,0};

void quicksort(int num[],int first,int last)
{
    if(first>=last)
        return;
    //只有一个数据时，该数组已经是有序的了
    int mid=num[first];
    //选择第一个元素作为分界
    //大于或等于mid的移动到后段，否则移动到前段
    int p=first,q=last;
    while(1)
    {
        while(num[q]>=mid)
        {
            q--;
            if(q<=p)
                break;
                //如果q扫到了p前，说明数组已有序
                //跳出内层循环
        }
        //从后往前扫描数组
        if(q<=p)
        {
            num[p]=mid;
            break;
            //跳出外层循环
        }
        num[p]=num[q];
        //较小的数移动到前段
        p++;
        while(num[p]<=mid)
        {
            p++;
            if(p>=q)
                break;
                //如果p扫到了q后，说明数组已有序
                //跳出内层循环
        }
        //从前往后扫描数组
        if(p>=q)
        {
            p=q;
            //把p和q统一在中间值位置，方便下面递归调用
            //中间值本身是不需要再排序了的
            num[q]=mid;
            //更新中间值
            break;
            //跳出外层循环
        }
        num[q]=num[p];
        //较大的数向后甩
    }
    quicksort(num,first,q-1);
    quicksort(num,p+1,last);
}

int main()
{
    quicksort(num,0,9);
    for(int i=0;i<10;i++)
        printf("%d ",num[i]);
    return 0;
}
