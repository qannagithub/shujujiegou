/**************************************************
*	ʱ��			2020��3��16��07:40:03
*	������			������
*	Ŀ��			��Ϥ���ֲ��ҵ��㷨ʵ��
**************************************************/

#include<stdio.h>
#include<stdlib.h>

#define N 10


int seqsearch(int *a,int key)
{
	int i;

	for(i=N-1;i>=0;i--)
	{
		if(key == a[i])
			return i;
	}
	return i;
}

int main(int argc,const char * argv[])
{
	int a[N] = {1,2,3,4,5,6,7};
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
		printf("�������ң�y/n");
		while(getchar() != '\n');
		scanf("%c",&ch);
		if(ch == 'y'|| ch == 'Y')
			continue;
		else
			break;

	}

	return 0;
}
