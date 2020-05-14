/********************************************
*	����ʱ��		2020��3��12��21:11:12
*	������			������
*	����			˳����ʵ��
********************************************/

#include<stdio.h>
#include<stdlib.h>

#define N 100	//���Ա����󳤶�Ϊ100

typedef int data_t;

typedef struct
{
	data_t data[N];//������������ռ��������Ĵ洢�ռ�
	int last;//����ָ���е���Ч��ֵ������Ҳ�������һ����Ч��ֵ����β�����±�
}sqlist_t;

/*********************************************
*	����˳���
*********************************************/

sqlist_t *create_sqlist(void)
{
	sqlist_t *L = NULL;//����һ���յ�˳���
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
*	�ͷţ���գ�˳���
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
*	�ж��Ƿ�Ϊ��
*********************************************/

int is_empty_sqlist(sqlist_t *L)//���Ա��Ƿ�Ϊ��
{
	if(L == NULL)
	{
		puts("faileed\n");
		return -1;
	}
	return (L->last == -1);//Ϊ��ʱΪ�棬����-1
}

/*********************************************
*	�Ƿ�Ϊ��,����Ԫ��ǰ����һ�������ж��Ƿ���
*********************************************/

int is_full_sqlist(sqlist_t *L)
{
	if(L == NULL)
	{
		puts("failed!\n");
		return -1;
	}
	return (L->last == N-1);//������һ��ֵ(last)Ϊ���ֵ�������������档	
}

/*********************************************
*	����Ϊ�գ��ÿ�
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
*	���
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
*	��ʾ���е���ЧԪ��,ʵ���Ͼ���ѭ����������ʾ
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
*	��ɾ�Ĳ�,�����ȵ���search�鵽ֵ���ٲ���
*********************************************/

int insert_sqlist(sqlist_t *L,data_t x,int pos)//�����Ǹ����Ǹ�Ԫ�أ���λ�ò���
{
	int i = 0;
	if((is_full_sqlist(L))||(pos<0)||(pos>L->last+1))//�����ж��Ƿ�Ϊ���ĺ��������Ҳ����λ�ò����ǷǷ��ռ�
	{
		puts("insert failed!\n");
		return -1;
	}
	for(i=L->last;i>=pos;i--)//�����һ����Ч������ʼ����ƶ����ӵ�ǰ�����posλ�ÿ�ʼ���ٵ�ǰһλ��ʼ�ƶ�
	{
		L->data[i+1] = L->data[i];//����ƶ��ı��ʾ�����һ��Ԫ�ظ�ǰһ��Ԫ�ظ�ֵ
	}
	L->data[pos] = x;//�ڳ�λ�ú󣬿�����ָ��λ��pos����ָ��Ԫ��x
	L->last++;//���һ����Чֵһֱ������
	return 0;	
}
int delete_sqlist(sqlist_t *L,int pos)//��λ��ɾ��
{
	//ʵ���Ͼ��Ǵ�Ҫɾ��Ԫ�ص�λ��pos��ʼ�������Ԫ�ظ���ǰ���
	int i=0;
	if((pos<0)||(pos>L->last+1))
	{
		puts("delete failed\n");
		return -1;
	}
	for(i=pos;i<=L->last;i++)//�м��Ǹ�Ҳ���Ե��øո�д�Ļ�ȡlength����,i<get_length_sqlist(L)
	{
		L->data[i] = L->data[i+1];
	}
	L->last--;//���һ����Чֵһֱ��ǰ��
	return 0;		
}

int change_sqlist(sqlist_t *L,data_t x,int pos)
{
	if((pos<0)||(pos>L->last+1))//λ�ñ����ǺϷ��ģ���������鷶Χ��
	{
		puts("delete failed\n");
		return -1;
	}
	L->data[pos] = x;//��ȡ��ǰҪ�޸�Ԫ�ص�λ�ã�ֱ�Ӹ�ֵ����
	return 0;
}

int search_sqlist(sqlist_t *L,data_t x)//�鵽ĳ��ֵ
{
	int i=0;
	for(i=0;i<=L->last;i++)//ѭ������
	{
		if(L->data[i] == x)//�Ƚϵ�ǰ��������Ԫ���Ƿ����Ҫ���
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
		insert_sqlist(L,i,0);//����i��L˳����У��ӵ�0����ʼ����,��Ϊһֱ��0�ĵط����룬�������Ȳ����0�ᱻ�����ƣ�����˳����43210
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
*	���
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
