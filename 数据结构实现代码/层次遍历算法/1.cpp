/*********************************************
*	时间			2020年3月15日20:33:19
*	创建人			覃安娜
*	目的			熟悉层次遍历算法
*********************************************/

#include<stdio.h>
#include<stdlib.h>

typedef btree_pnode datatype;

typedef struct node
{
	datatype data;
	struct node *next;
}link_node,*link_pnode;

typedef struct seqqueue
{
	link_pnode front,rear;
}seq_queue,*seq_pqueue;

//创建队

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
//判断队列是否为满

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
//入队

int in_seqqueue(datatype data,seq_pqueue q)//bool类型，所以return的返回值是false或者true!!!
{
	link_pnode new;

	new = (link_pnode)malloc(sizeof(link_node));
	if(NULL == new){
		printf("入队失败\n");
		return -1;
	}

	new->data = p->rear->next;

	new->next = q->rear->next;
	q->rear->next = new;

	return 1;
}


//断队列是否为空

int is_empty_seqqueue(seq_pqueue q)
{
	if(q->rear == q->front)
		return -1;
	else
		return 0;
}

//出队

int out_seqqueue(seq_pqueue q,datatype * D)
{
	link_pnode p;

	//先判断队列是否为空
	if(is_empty_seqqueue(q)){
		printf("队列空\n");
		return -1;
	}

	p = q->front;
	q->front = q->front->next;
	*D = q->front->data;
	free(p);

	return 1;
}

//遍历

/*
void show_seqqueue(seq_pqueue q)
{
	link_pnode p;
	int i;

	//先判断队列是否为空
	if(is_empty_seqqueue(q)){
		printf("队列空\n");
		return ;
	}

	for(p = q->front->next; p != NULL; p = p->next)
	{
		printf(" %d\t ",p->data);
	}

	puts("");
}

*/

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

//层次遍历

void level_order(btree_pnode t)
{
	link_pqueue q;

	create_seqqueue(&q);

	while(t !== NULL)
	{
		printf("%c",t->data);


	if(t->lchild != NULL)
		in_seqqueue(t->lchild,q);

	if(t->rchild != NULL)
		in_seqqueue(t->rchild,q);

	if(!is_empty_linkqueue(q))
		out_seqqueue(q,&t);
	else
		break;
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

	printf("层次遍历序列：");
	level_order(t);
	puts("");

	return 0;
}
