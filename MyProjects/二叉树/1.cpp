/************************************************
*	时间			2020年3月15日09:09:17
*	创建人			覃安娜
*	目的			熟悉二叉树的基本操作


*	结果
AB#CD###E#F#GH##K###
先序遍历序列：ABCDEFGHK
中序遍历序列：BDCAEFHGK
后序遍历序列：DCBHKGFEA
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
		//创建左子树
		new->lchild = create_btree();

		//创建右子树
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
		//创建左子树
		create_btree(&(*T)->lchild);

		//创建右子树
		create_btree(&(*T)->rchild);
	}
}

#endif

//先序遍历递归算法实现

void pre_order(btree_pnode t)//t是指向根节点的指针
{
	if(t != NULL){
		//先访问根节点
		printf("%c",t->data);
		//先序遍历左子树
		pre_order(t->lchild);
		//先序遍历右子树
		pre_order(t->rchild);
	}
}

//中序遍历

void mid_order(btree_pnode t)//t是指向根节点的指针
{
	if(t != NULL){
		
		//先序遍历左子树
		mid_order(t->lchild);
		//先访问左节点，再访问根节点
		printf("%c",t->data);
		
		//先序遍历右子树
		mid_order(t->rchild);
	}
}

//后序遍历

void last_order(btree_pnode t)//t是指向根节点的指针
{
	if(t != NULL){
		
		//先序遍历左子树
		last_order(t->lchild);
		
		//先序遍历右子树
		last_order(t->rchild);

		//再访问根节点
		printf("%c",t->data);

	}
}


int main(int argc,const char *argv[])
{
	btree_pnode t;

	create_btree(&t);

	printf("先序遍历序列：");
	pre_order(t);
	puts("");

	printf("中序遍历序列：");
	mid_order(t);
	puts("");

	printf("后序遍历序列：");
	last_order(t);
	puts("");



	return 0;
}
