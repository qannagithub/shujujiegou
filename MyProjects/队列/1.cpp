/*******************************************
*	ʱ��			2020��3��14��10:01:49
*	������			������
*	Ŀ��			ʵ��˳����еĻ�������
*	ʵ��			����������������ӣ�������ĸ����ӣ����ұ仯�󶼴�ӡ����
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

//������

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

//���

int in_seqqueue(datatype data,seq_pqueue q)//bool���ͣ�����return�ķ���ֵ��false����true!!!
{
	//���ж϶��Ƿ�Ϊ��
	if(is_full_seqqueue(q))//��Ϊ��,ִ�������
	{
		printf("full!\n");
		return -1;
	}

	q->rear = (q->rear+1)%MAXSIZE;
	q->data[q->rear] = data;
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
	//���ж϶����Ƿ�Ϊ��
	if(is_empty_seqqueue(q)){
		printf("���п�\n");
		return -1;
	}

	q->front = (q->front+1)%MAXSIZE;
	*D = q->data[q->front];
	return 1;
}

//����

void show_seqqueue(seq_pqueue q)
{
	int i;

	//���ж϶����Ƿ�Ϊ��
	if(is_empty_seqqueue(q)){
		printf("���п�\n");
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