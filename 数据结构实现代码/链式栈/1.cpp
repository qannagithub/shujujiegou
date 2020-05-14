/**************************************
*	时间			2020年3月14日08:35:16
*	创建人			覃安娜
*	目的			实现链式栈的基本操作
**************************************/

#include<stdio.h>
#include<stdlib.h>

typedef int datatype;

typedef struct node
{
	datatype data;
	struct node * next;
}listnode,*linklist;

//栈的创建

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

//判断空

int linkstack_empty(linklist s)
{
	return (s->next == NULL ? 1 : 0);
}


//入栈

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

//出栈

datatype linkstack_pop(linklist s)
{
	linklist p;
	datatype ret;//存出栈的值

	p = s->next;
	s->next = p->next;

	ret = p->data;
	free(p);
	p = NULL;

	return ret;
}

//查看栈顶

datatype linkstack_top(linklist s)
{
	return (s->next->data);
}


//清空

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

//释放栈

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