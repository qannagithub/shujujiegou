/*******************************************
*	时间			2020年3月14日10:01:49
*	创建人			覃安娜
*	目的			实现顺序队列的基本操作
*	实例			键盘输入整数则入队，输入字母则出队，并且变化后都打印出来
*******************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10

typedef int datatype;

typedef struct seqqueue
{
	datatype data[MAXSIZE];
	int front,rear;
}seq_queue,*seq_pqueue;

//创建队

void create_seqqueue(seq_pqueue * Q)
{

	if((*Q = (seq_pqueue)malloc(sizeof(seq_queue))) == NULL)
	{
		printf("malloc failed!\n");
		return ;
	}

	(*Q)->front = MAXSIZE-1;
	(*Q)->rear = MAXSIZE-1;

	return ;
}

//判断队列是否为满

int is_full_seqqueue(seq_pqueue q)
{
	if((q->rear+1)%MAXSIZE == q->front)
	{
		return -1;
	}
	else
		return 0;
}

//入队

int in_seqqueue(datatype data,seq_pqueue q)//bool类型，所以return的返回值是false或者true!!!
{
	//先判断队是否为满
	if(is_full_seqqueue(q))//满为真,执行下面的
	{
		printf("full!\n");
		return -1;
	}

	q->rear = (q->rear+1)%MAXSIZE;
	q->data[q->rear] = data;
	return 1;
}

//断队列是否为空

int is_empty_seqqueue(seq_pqueue q)
{
	if(q->rear == q->front)
		return -1;
	else
		return 0;
}

//出队

int out_seqqueue(seq_pqueue q,datatype * D)
{
	//先判断队列是否为空
	if(is_empty_seqqueue(q)){
		printf("队列空\n");
		return -1;
	}

	q->front = (q->front+1)%MAXSIZE;
	*D = q->data[q->front];
	return 1;
}

//遍历

void show_seqqueue(seq_pqueue q)
{
	int i;

	//先判断队列是否为空
	if(is_empty_seqqueue(q)){
		printf("队列空\n");
		return ;
	}

	for(i = (q->front+1)%MAXSIZE;i != (q->rear+1)%MAXSIZE;i = (i+1)%MAXSIZE)
	{
		printf("%d\t",q->data[i]);

	}

	puts("");
}

int main(int argc,const char * argv[])
{
	seq_pqueue q;
	datatype data,t;
	int ret;//接收用户输入的返回值

	create_seqqueue(& q);

	while(1)
	{
		printf("请输入整数:");
		ret = scanf("%d",&data);
		if(ret == 1)//如果输入的是整数，继续执行入队
		{
			if(in_seqqueue(data,q))
				show_seqqueue(q);
			else
				printf("入队失败\n");
		}
		else//出队
		{
			if(out_seqqueue(q,&t))
			{
				printf("out: %d\n",t);
				show_seqqueue(q);
			}
			else
				printf("出队失败\n");
		//清空队
		while(getchar()!= '\n');
		}

	}

	return 0;
}