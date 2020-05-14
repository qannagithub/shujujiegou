/**************************************
*	ʱ��			2020��3��14��08:35:16
*	������			������
*	Ŀ��			ʵ����ʽջ�Ļ�������
**************************************/

#include<stdio.h>
#include<stdlib.h>

typedef int datatype;

typedef struct node
{
	datatype data;
	struct node * next;
}listnode,*linklist;

//ջ�Ĵ���

linklist linkstack_create()
{
	linklist s;

	if((s = (linklist)malloc(sizeof(listnode))) == NULL)
	{
		printf("malloc failed!\n");
		return NULL;
	}

	s->data = 0;
	s->next = NULL;
	return s;
}

//�жϿ�

int linkstack_empty(linklist s)
{
	return (s->next == NULL ? 1 : 0);
}


//��ջ

int linkstack_push(linklist s,datatype value)
{
	linklist p;

	if((p = (linklist)malloc(sizeof(listnode))) == NULL)
	{
		printf("malloc failed!\n");
		return NULL;
	}

	p->data = value;

	p->next = s->next;
	s->next = p;

	return 0;
}

//��ջ

datatype linkstack_pop(linklist s)
{
	linklist p;
	datatype ret;//���ջ��ֵ

	p = s->next;
	s->next = p->next;

	ret = p->data;
	free(p);
	p = NULL;

	return ret;
}

//�鿴ջ��

datatype linkstack_top(linklist s)
{
	return (s->next->data);
}


//���

void linkstack_clear(linklist s)
{
	linklist p;

	printf("clear:");

	p = s->next;
	while(p)
	{
		s->next = p->next;
		printf(" %d ",p->data);
		free(p);
		p = s->next;
	}
	puts("");
}

//�ͷ�ջ

void linkstack_free(linklist s)
{
	linklist p;

	printf("free:");
	p = s;
	while(p)
	{
		s = s->next;
		printf(" %d ",p->data);
		free(p);
		p = s;
	}
	puts("");
}



int main(int argc,const char * argv[])
{
	linklist s;

	s = linkstack_create();

	linkstack_push(s,10);
	linkstack_push(s,20);
	linkstack_push(s,30);
	linkstack_push(s,40);
	linkstack_push(s,50);

	//linkstack_clear(s);
	linkstack_free(s);
#if 0
	while(!linkstack_empty(s))
	{
		printf(" %d ",linkstack_pop(s));
	}

	puts("");

#endif

	return 0;
}