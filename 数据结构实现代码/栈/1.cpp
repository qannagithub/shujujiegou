/*****************************************
*	ʱ��			2020��3��14��07:32:40			
*	������			������
*	Ŀ��			ʵ��ջ�ĸ��ֳ�������
*****************************************/

#include<stdio.h>
#include<stdlib.h>

typedef int datatype;

typedef struct
{
	datatype *data;
	int maxlen;
	int top;
}sqstack;

//������ջ

sqstack * stack_create(int len)
{
	sqstack * s;

	if((s = (sqstack *)malloc(sizeof(sqstack))) == NULL)
	{
		printf("malloc failed!\n");
		return NULL;
	}

	if((s->data = (datatype *)malloc(len * sizeof(datatype))) == NULL)
	{
		printf("s-data malloc failed1!\n");
		return NULL;
	}

	s->maxlen = len;
	s->top = -1;

	return s;
}


//�ж�ջ�Ƿ�Ϊ��

int stack_empty(sqstack * s)
{
	return (s->top == -1 ? 1 : 0);//s->top == -1ʱ����1,1�����ջΪ�գ�0��Ϊ��
}

//���ջ

void stack_clear(sqstack * s)
{
	s->top = -1;//ֱ����topΪ-1
}

//�ж�ջ�Ƿ�Ϊ��

int stack_full(sqstack * s)//top�������Ч����+1
{
	return (s->top == s->maxlen-1 ? 1 : 0);//��ջ�����������������ʱ����0��ʼ�㣬����-1������Ϊ��
}

//��ջ

int stack_push(sqstack *s,datatype value)
{
	if(s->top == s->maxlen-1)
	{
		printf("stack is full!\n");
		return -1;
	}

	s->data[s->top+1] = value;
	s->top++;

	return 1;
}

//��ջ

datatype stack_pop(sqstack * s)
{
	s->top--;

	return (s->data[s->top+1]);
}

//ȡջ��

datatype stack_top(sqstack * s)
{
	return (s->data[s->top]);
}

//ջ����

void stack_free(sqstack * s)
{
	free(s->data);
	s->data = NULL;

	free(s);
	s = NULL;
}

int main(int argc,const char * argv[])
{
	sqstack * s;

	int n = 10;//�����û������ֵ

	s = stack_create(n);

	stack_push(s,10);
	stack_push(s,20);
	stack_push(s,30);
	stack_push(s,40);
	stack_push(s,50);

	while(!stack_empty(s))//��ջ��Ϊ��ʱִ��
	{
		printf(" %d ",stack_pop(s));
	}
	puts("");//����

	stack_free(s);

#if 0
	free(s->data);
	s->data = NULL;
	free(s);
	s = NULL;
#endif
	return 0;
}