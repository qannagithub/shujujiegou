/************************************************
*	时间			2020年3月14日21:50:10
*	创建人			覃安娜
*	目的			实现链式队列的基本操作
************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef int datatype;

typedef struct node
{
	datatype data;
	struct node *next;
}link_node,*link_pnode;

typedef struct seqqueue
{
	link_pnode front,rear;
}seq_queue,*seq_pqueue;

//创建队

void create_seqqueue(seq_pqueue * Q)
{

	if((*Q = (seq_pqueue)malloc(sizeof(seq_queue))) == NULL)
	{
		printf("malloc failed!\n");
		return ;
	}

	(*Q)->front->next = NULL;
	(*Q)->rear = (*Q)->front;

	return ;
}
/*
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
*/
//入队

int in_seqqueue(datatype data,seq_pqueue q)//bool类型，所以return的返回值是false或者true!!!
{
	link_pnode new;

	new = (link_pnode)malloc(sizeof(link_node));
	if(NULL == new){
		printf("入队失败\n");
		return -1;
	}

	new->data = p->rear->next;

	new->next = q->rear->next;
	q->rear->next = new;

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
	link_pnode p;

	//先判断队列是否为空
	if(is_empty_seqqueue(q)){
		printf("队列空\n");
		return -1;
	}

	p = q->front;
	q->front = q->front->next;
	*D = q->front->data;
	free(p);

	return 1;
}

//遍历

void show_seqqueue(seq_pqueue q)
{
	link_pnode p;
	int i;

	//先判断队列是否为空
	if(is_empty_seqqueue(q)){
		printf("队列空\n");
		return ;
	}

	for(p = q->front->next; p != NULL; p = p->next)
	{
		printf(" %d\t ",p->data);
	}

	puts("");
}


int main(int argc,const char *argv[])
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