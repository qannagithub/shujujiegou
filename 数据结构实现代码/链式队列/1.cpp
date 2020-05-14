/************************************************
*	ʱ��			2020��3��14��21:50:10
*	������			������
*	Ŀ��			ʵ����ʽ���еĻ�������
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

//������

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
//�ж϶����Ƿ�Ϊ��

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
//���

int in_seqqueue(datatype data,seq_pqueue q)//bool���ͣ�����return�ķ���ֵ��false����true!!!
{
	link_pnode new;

	new = (link_pnode)malloc(sizeof(link_node));
	if(NULL == new){
		printf("���ʧ��\n");
		return -1;
	}

	new->data = p->rear->next;

	new->next = q->rear->next;
	q->rear->next = new;

	return 1;
}


//�϶����Ƿ�Ϊ��

int is_empty_seqqueue(seq_pqueue q)
{
	if(q->rear == q->front)
		return -1;
	else
		return 0;
}

//����

int out_seqqueue(seq_pqueue q,datatype * D)
{
	link_pnode p;

	//���ж϶����Ƿ�Ϊ��
	if(is_empty_seqqueue(q)){
		printf("���п�\n");
		return -1;
	}

	p = q->front;
	q->front = q->front->next;
	*D = q->front->data;
	free(p);

	return 1;
}

//����

void show_seqqueue(seq_pqueue q)
{
	link_pnode p;
	int i;

	//���ж϶����Ƿ�Ϊ��
	if(is_empty_seqqueue(q)){
		printf("���п�\n");
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
	int ret;//�����û�����ķ���ֵ

	create_seqqueue(& q);

	while(1)
	{
		printf("����������:");
		ret = scanf("%d",&data);
		if(ret == 1)//��������������������ִ�����
		{
			if(in_seqqueue(data,q))
				show_seqqueue(q);
			else
				printf("���ʧ��\n");
		}
		else//����
		{
			if(out_seqqueue(q,&t))
			{
				printf("out: %d\n",t);
				show_seqqueue(q);
			}
			else
				printf("����ʧ��\n");
		//��ն�
		while(getchar()!= '\n');
		}

	}

	return 0;
}