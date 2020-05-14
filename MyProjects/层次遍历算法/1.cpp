/*********************************************
*	ʱ��			2020��3��15��20:33:19
*	������			������
*	Ŀ��			��Ϥ��α����㷨
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

//������

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
*/
//���

int in_seqqueue(datatype data,seq_pqueue q)//bool���ͣ�����return�ķ���ֵ��false����true!!!
{
	link_pnode new;

	new = (link_pnode)malloc(sizeof(link_node));
	if(NULL == new){
		printf("���ʧ��\n");
		return -1;
	}

	new->data = p->rear->next;

	new->next = q->rear->next;
	q->rear->next = new;

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
	link_pnode p;

	//���ж϶����Ƿ�Ϊ��
	if(is_empty_seqqueue(q)){
		printf("���п�\n");
		return -1;
	}

	p = q->front;
	q->front = q->front->next;
	*D = q->front->data;
	free(p);

	return 1;
}

//����

/*
void show_seqqueue(seq_pqueue q)
{
	link_pnode p;
	int i;

	//���ж϶����Ƿ�Ϊ��
	if(is_empty_seqqueue(q)){
		printf("���п�\n");
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

//��α���

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

	printf("����������У�");
	pre_order(t);
	puts("");

	printf("����������У�");
	mid_order(t);
	puts("");

	printf("����������У�");
	last_order(t);
	puts("");

	printf("��α������У�");
	level_order(t);
	puts("");

	return 0;
}
