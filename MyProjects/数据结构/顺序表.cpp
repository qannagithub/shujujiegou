/********************************************
*	创建时间		2020年3月12日21:11:12
*	创建人			覃安娜
*	功能			顺序表的实现
********************************************/

#include<stdio.h>
#include<stdlib.h>

#define N 100	//线性表的最大长度为100

typedef int data_t;

typedef struct
{
	data_t data[N];//用连续的数组空间来定义表的存储空间
	int last;//既是指表中的有效数值个数，也是最最后一个有效数值（表尾）的下标
}sqlist_t;

/*********************************************
*	创建顺序表
*********************************************/

sqlist_t *create_sqlist(void)
{
	sqlist_t *L = NULL;//定义一个空的顺序表
	L = (sqlist_t *)malloc(sizeof(sqlist_t));
	if(L == NULL)
	{
		printf("malloc failed!\n");
		return NULL;
	}

	L ->last = -1;
	return L;
}

/*********************************************
*	释放（清空）顺序表
*********************************************/

void clear_sqlist(sqlist_t * L)
{
	if(L == NULL)
	{
		puts("is null\n");
		return ;
	}
	free(L);
	return ;
}

/*********************************************
*	判断是否为空
*********************************************/

int is_empty_sqlist(sqlist_t *L)//测试表是否为空
{
	if(L == NULL)
	{
		puts("faileed\n");
		return -1;
	}
	return (L->last == -1);//为空时为真，返回-1
}

/*********************************************
*	是否为满,插入元素前，第一件事是判断是否满
*********************************************/

int is_full_sqlist(sqlist_t *L)
{
	if(L == NULL)
	{
		puts("failed!\n");
		return -1;
	}
	return (L->last == N-1);//如果最后一个值(last)为最大值，则满。返回真。	
}

/*********************************************
*	设置为空，置空
*********************************************/

void set_empyt_sqlist(sqlist_t *L)
{
	if(L == NULL)
	{
		puts("failed\n");
		return;
	}
	L->last = -1;
	return;
}


/*********************************************
*	求表长
*********************************************/

int get_length_sqlist(sqlist_t *L)
{
	if(L == NULL)
	{
		puts("failed\n");
		return -1;
	}
	return (L->last+1);
}

/*********************************************
*	显示所有的有效元素,实际上就是循环遍历来显示
*********************************************/

void show_sqlist(sqlist_t *L)
{
	int i = 0;
	if(L ==NULL)
	{
		puts("show failed\n");
		return ;
	}
	for(i=0;i<=L->last;i++)
	{
		printf("L-data[%d] = %d\n",i,L->data[i]);
	}
	return;
}

/*********************************************
*	增删改查,可以先调用search查到值，再操作
*********************************************/

int insert_sqlist(sqlist_t *L,data_t x,int pos)//插入那个表，那个元素，按位置插入
{
	int i = 0;
	if((is_full_sqlist(L))||(pos<0)||(pos>L->last+1))//调用判断是否为满的函数，并且插入的位置不能是非法空间
	{
		puts("insert failed!\n");
		return -1;
	}
	for(i=L->last;i>=pos;i--)//从最后一个有效的数开始向后移动，从当前插入的pos位置开始，再到前一位开始移动
	{
		L->data[i+1] = L->data[i];//向后移动的本质就是下一个元素给前一个元素赋值
	}
	L->data[pos] = x;//腾出位置后，可以在指定位置pos插入指定元素x
	L->last++;//最后一个有效值一直往后走
	return 0;	
}
int delete_sqlist(sqlist_t *L,int pos)//按位置删除
{
	//实际上就是从要删除元素的位置pos开始，后面的元素覆盖前面的
	int i=0;
	if((pos<0)||(pos>L->last+1))
	{
		puts("delete failed\n");
		return -1;
	}
	for(i=pos;i<=L->last;i++)//中间那个也可以调用刚刚写的获取length函数,i<get_length_sqlist(L)
	{
		L->data[i] = L->data[i+1];
	}
	L->last--;//最后一个有效值一直往前走
	return 0;		
}

int change_sqlist(sqlist_t *L,data_t x,int pos)
{
	if((pos<0)||(pos>L->last+1))//位置必须是合法的，在这个数组范围中
	{
		puts("delete failed\n");
		return -1;
	}
	L->data[pos] = x;//获取当前要修改元素的位置，直接赋值即可
	return 0;
}

int search_sqlist(sqlist_t *L,data_t x)//查到某个值
{
	int i=0;
	for(i=0;i<=L->last;i++)//循环遍历
	{
		if(L->data[i] == x)//比较当前遍历到的元素是否等于要查的
		{
			return i;
		}
	}
	return -1;
}


int main(int argc,const char *argv[])
{
	int i=0;
	sqlist_t *L = NULL;
	L=create_sqlist();

	for(i=0;i<=4;i++)
	{
		insert_sqlist(L,i,0);//插入i到L顺序表中，从第0个开始插入,因为一直在0的地方插入，所以最先插入的0会被往后推，所以顺序是43210
	}

	printf("sqlist length is %d\n",get_length_sqlist(L));
	show_sqlist(L);
	puts("*********************************************");

	printf("search data 3:");
	printf("data = pos 3 is %d\n",search_sqlist(L,3));

	printf("sqlist length is %d\n",get_length_sqlist(L));
	show_sqlist(L);
	puts("*********************************************");

	printf("delete data 3");
	delete_sqlist(L,search_sqlist(L,3));

	printf("sqlist length is %d\n",get_length_sqlist(L));
	show_sqlist(L);
	puts("*********************************************");

	printf("change data[2] = 99");
	change_sqlist(L,99,2);

	printf("sqlist length is %d\n",get_length_sqlist(L));
	show_sqlist(L);
	puts("*********************************************");

	clear_sqlist(L);

	return 0;
}

/************************************************************
*	结果
*	sqlist length is 5
L-data[0] = 4
L-data[1] = 3
L-data[2] = 2
L-data[3] = 1
L-data[4] = 0
*********************************************
search data 3:data = pos 3 is 1
sqlist length is 5
L-data[0] = 4
L-data[1] = 3
L-data[2] = 2
L-data[3] = 1
L-data[4] = 0
*********************************************
delete data 3sqlist length is 4
L-data[0] = 4
L-data[1] = 2
L-data[2] = 1
L-data[3] = 0
*********************************************
change data[2] = 99sqlist length is 4
L-data[0] = 4
L-data[1] = 2
L-data[2] = 99
L-data[3] = 0
*********************************************
************************************************************/
