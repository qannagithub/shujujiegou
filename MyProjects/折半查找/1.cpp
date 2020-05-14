/**************************************************
*	时间			2020年3月16日07:40:03
*	创建人			覃安娜
*	目的			熟悉各种查找的算法实现
*	折半查找
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
		mid = (low+high)/2;//除不尽时，都是int类型，会舍弃小数部分
		if(key == a[mid])
			return mid;
		else if(key < a[mid])
			high = mid - 1;
		else
			low = mid + 1;

	}
	return -1;//查找失败
}

int main(int argc,const char * argv[])
{
	int a[N] = {1,13,32,41,52,61,78};
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
		printf("继续查找？y/n \n");
		while(getchar() != '\n');
		scanf("%c",&ch);
		if(ch == 'y'|| ch == 'Y')
			continue;
		else
			break;

	}

	return 0;
}
