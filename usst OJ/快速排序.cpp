#include <iostream>

using namespace std;

static int num[10]={5,6,9,2,3,4,7,8,1,0};

void quicksort(int num[],int first,int last)
{
    if(first>=last)
        return;
    //ֻ��һ������ʱ���������Ѿ����������
    int mid=num[first];
    //ѡ���һ��Ԫ����Ϊ�ֽ�
    //���ڻ����mid���ƶ�����Σ������ƶ���ǰ��
    int p=first,q=last;
    while(1)
    {
        while(num[q]>=mid)
        {
            q--;
            if(q<=p)
                break;
                //���qɨ����pǰ��˵������������
                //�����ڲ�ѭ��
        }
        //�Ӻ���ǰɨ������
        if(q<=p)
        {
            num[p]=mid;
            break;
            //�������ѭ��
        }
        num[p]=num[q];
        //��С�����ƶ���ǰ��
        p++;
        while(num[p]<=mid)
        {
            p++;
            if(p>=q)
                break;
                //���pɨ����q��˵������������
                //�����ڲ�ѭ��
        }
        //��ǰ����ɨ������
        if(p>=q)
        {
            p=q;
            //��p��qͳһ���м�ֵλ�ã���������ݹ����
            //�м�ֵ�����ǲ���Ҫ�������˵�
            num[q]=mid;
            //�����м�ֵ
            break;
            //�������ѭ��
        }
        num[q]=num[p];
        //�ϴ�������˦
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
