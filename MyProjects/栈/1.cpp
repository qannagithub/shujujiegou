/*****************************************
*	时间			2020年3月14日07:32:40			
*	创建人			覃安娜
*	目的			实现栈的各种常见操作
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

//创建空栈

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


//判断栈是否为空

int stack_empty(sqstack * s)
{
	return (s->top == -1 ? 1 : 0);//s->top == -1时返回1,1则代表栈为空，0不为空
}

//清空栈

void stack_clear(sqstack * s)
{
	s->top = -1;//直接让top为-1
}

//判断栈是否为满

int stack_full(sqstack * s)//top存的是有效个数+1
{
	return (s->top == s->maxlen-1 ? 1 : 0);//当栈顶等于最大容量长度时（从0开始算，所以-1），则为满
}

//入栈

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

//出栈

datatype stack_pop(sqstack * s)
{
	s->top--;

	return (s->data[s->top+1]);
}

//取栈顶

datatype stack_top(sqstack * s)
{
	return (s->data[s->top]);
}

//栈销毁

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

	int n = 10;//接收用户输入的值

	s = stack_create(n);

	stack_push(s,10);
	stack_push(s,20);
	stack_push(s,30);
	stack_push(s,40);
	stack_push(s,50);

	while(!stack_empty(s))//当栈不为空时执行
	{
		printf(" %d ",stack_pop(s));
	}
	puts("");//换行

	stack_free(s);

#if 0
	free(s->data);
	s->data = NULL;
	free(s);
	s = NULL;
#endif
	return 0;
}