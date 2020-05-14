/**************************************************
*	时间			2020年3月16日07:40:03
*	创建人			覃安娜
*	目的			熟悉各种查找的算法实现
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
		printf("请输入你要查找的:");
		scanf("%d",&key);
		
		i = seqsearch(a,key);
		if(i == -1){
			printf("查找失败\n");
		}
		else
			printf("查找成功：%d 在 %d\n",key,i);
		printf("继续查找？y/n");
		while(getchar() != '\n');
		scanf("%c",&ch);
		if(ch == 'y'|| ch == 'Y')
			continue;
		else
			break;

	}

	return 0;
}
