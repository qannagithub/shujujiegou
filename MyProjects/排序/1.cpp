/**********************************************
*	时间			2020年3月16日15:52:29
*	创建人			覃安娜
*	目的				熟悉排序算法
**********************************************/

#include<stdio.h>
#include<stdlib.h>

#define N 8

void show(int a[])
{
	int i;

	for(i=0;i<N;i++)
		printf("%d\t",a[i]);
	printf("\n");
}

void search(int a[])
{
	int i,j,tmp;

	for(i=1;i<N;i++){
		tmp = a[i];
		for(j=i-1;j>=0;j--)
			if(tmp < a[j])
				a[j+1]= a[j];
			else
				break;
		a[j+1] = tmp;
		show(a);
	}

}

//shell排序

void shellsearch(int a[])
{
	int i,j,tmp;
	int d;
	
	for(d = N/2;d>0;d /= 2)
	{
		for(i=d;i<N;i++){
			tmp = a[i];
			for(j=i-d;j>=0;j-=d)
				if(tmp < a[j])
					a[j+d]= a[j];
				else
					break;
				a[j+d] = tmp;
			
		}
			show(a);
	}
	
}

//快速排序

//一趟快排

int quickpass(int a[],int i,int j)
{
	int tmp;
	tmp = a[i];//把a[i]做基准
	while(i < j)
	{
		
		while(i < j && tmp <= a[j])
			j--;
		if(i < j)
			a[i] = a[j];
		while(i < j && tmp >= a[i])
			i++;
		if(i < j)
			a[j] = a[i];
	}
	a[i] = tmp;
	return i;
}

void quicksort(int a[],int low,int high)
{
	int mid;
	if(low < high)
	{
		mid = quickpass(a,low,high);//一趟快排
		show(a);
		quicksort(a,low,mid-1);//基准值的左边序列快排
		quicksort(a,mid+1,high);//右边
	}
}

int main(int argc,const char * argv[])
{
	int a[N] = {50,36,66,76,36,12,25,95};
	
	printf("原来的无序排列：\n");
	show(a);
	printf("直接插入排序后序列：\n");
	quicksort(a,0,N-1);

	return 0;
}