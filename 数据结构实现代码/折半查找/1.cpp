/**************************************************
*	ʱ��			2020��3��16��07:40:03
*	������			������
*	Ŀ��			��Ϥ���ֲ��ҵ��㷨ʵ��
*	�۰����
**************************************************/

#include<stdio.h>
#include<stdlib.h>

#define N 10


int seqsearch(int *a,int key)
{
	int low,high,mid;
	low = 0;
	high = N-1;
	

	while(low <= high)
	{
		mid = (low+high)/2;//������ʱ������int���ͣ�������С������
		if(key == a[mid])
			return mid;
		else if(key < a[mid])
			high = mid - 1;
		else
			low = mid + 1;

	}
	return -1;//����ʧ��
}

int main(int argc,const char * argv[])
{
	int a[N] = {1,13,32,41,52,61,78};
	int i,key;
	char ch;

	while(1)
	{
		printf("��������Ҫ���ҵ�:");
		scanf("%d",&key);
		
		i = seqsearch(a,key);
		if(i == -1){
			printf("����ʧ��\n");
		}
		else
			printf("���ҳɹ���%d �� %d\n",key,i);
		printf("�������ң�y/n \n");
		while(getchar() != '\n');
		scanf("%c",&ch);
		if(ch == 'y'|| ch == 'Y')
			continue;
		else
			break;

	}

	return 0;
}
