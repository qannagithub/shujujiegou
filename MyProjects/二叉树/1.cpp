/************************************************
*	ʱ��			2020��3��15��09:09:17
*	������			������
*	Ŀ��			��Ϥ�������Ļ�������


*	���
AB#CD###E#F#GH##K###
����������У�ABCDEFGHK
����������У�BDCAEFHGK
����������У�DCBHKGFEA
************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef char datatype;

typedef struct btreenode
{
	datatype data;
	struct btreenode *lchild,*rchild;
}btree_node,*btree_pnode;

#if 0

btree_pnode create_btree(void)
{
	datatype ch;
	btree_pnode new;

	scanf("%c",&ch);
	if('#' == ch)
		return NULL;
	else
	{
		new = (btree_pnode)malloc(sizeof(btree_node));
		if(NULL == new)
		{
			printf("malloc failed!\n");
			return -1;
		}

		new->data = ch;
		//����������
		new->lchild = create_btree();

		//����������
		new->rchild = create_btree();
	}
}

#else

void create_btree(btree_pnode *T)
{
	datatype ch;

	scanf("%c",&ch);
	if('#' == ch)
		*T = NULL;
	else
	{
		*T = (btree_pnode)malloc(sizeof(btree_node));
		if(NULL == *T)
		{
			printf("malloc failed!\n");
		}

		(*T)->data = ch;
		//����������
		create_btree(&(*T)->lchild);

		//����������
		create_btree(&(*T)->rchild);
	}
}

#endif

//��������ݹ��㷨ʵ��

void pre_order(btree_pnode t)//t��ָ����ڵ��ָ��
{
	if(t != NULL){
		//�ȷ��ʸ��ڵ�
		printf("%c",t->data);
		//�������������
		pre_order(t->lchild);
		//�������������
		pre_order(t->rchild);
	}
}

//�������

void mid_order(btree_pnode t)//t��ָ����ڵ��ָ��
{
	if(t != NULL){
		
		//�������������
		mid_order(t->lchild);
		//�ȷ�����ڵ㣬�ٷ��ʸ��ڵ�
		printf("%c",t->data);
		
		//�������������
		mid_order(t->rchild);
	}
}

//�������

void last_order(btree_pnode t)//t��ָ����ڵ��ָ��
{
	if(t != NULL){
		
		//�������������
		last_order(t->lchild);
		
		//�������������
		last_order(t->rchild);

		//�ٷ��ʸ��ڵ�
		printf("%c",t->data);

	}
}


int main(int argc,const char *argv[])
{
	btree_pnode t;

	create_btree(&t);

	printf("����������У�");
	pre_order(t);
	puts("");

	printf("����������У�");
	mid_order(t);
	puts("");

	printf("����������У�");
	last_order(t);
	puts("");



	return 0;
}
