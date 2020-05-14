/*********************************************
*	时间			2020年3月13日17:11:50
*	创建人			覃安娜
*	创建目的		实现双向循环链表
*********************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node * prior;
	struct node * next;
}dlistnode;

dlistnode *dlist_create()
{
	dlistnode * H,*p,*r;
	int n;

	if((H = (dlistnode *)malloc(sizeof(dlistnode))) == NULL)
	{
		printf("malloc failed\n");
		return NULL;
	}

	H->prior = H;
	H->next = H;
	r = H;

	while(1)
	{
		printf("please input value:(-1exit)");
		scanf("%d",&n);

		if(n == -1)
			break;

		if((p = (dlistnode *)malloc(sizeof(dlistnode))) == NULL)
		{
			printf("malloc failed\n");
			return NULL;
		}
		p->data = n;

		p->prior = r;
		p->next = r->next;
		r->next = p;
		H->prior = p;
		r=p;//r向后移
	}

	return H;

}

void dlist_show(dlistnode * H)
{
	dlistnode * p ;

	p = H->next;

	while(p != H)
	{
		printf(" %d ",p->data);
		p = p->next;
	}
	puts("\n");
}

dlistnode *dlist_get(dlistnode *H,int pos)
{
	int i = -1;
	dlistnode *p = H;

	if(pos < 0)
	{
		puts("无效\n");
		return NULL;
	}
	
	while(i < pos)
	{
		p = p->next;
		i++;
		if(p == H)
		{
			puts("无效\n");
			return NULL;
		}
	}
return p;

}

int dlist_insert(dlistnode *H,int value,int pos)
{
	dlistnode *p,*q;

	p = dlist_get(H,pos);
	if(p == NULL)
	{
		return -1;
	}
	
	if((q=(dlistnode *)malloc(sizeof(dlistnode))) == NULL)
	{
		puts("malloc failed\n");
		return -1;
	}

	q->data = value;

	q->prior = p->prior;
	q->next = p;
	p->prior->next = q;
	p->prior = q;

	return 0;
}

int dlist_delete(dlistnode * H,int pos)
{
	dlistnode *p;

	p = dlist_get(H,pos);
	if(p == NULL)
		return -1;

	p->prior->next = p->next;
	p->next->prior = p->prior;

	free(p);
	p=NULL;

	return 0;
}

int main(int argc,const char * argv[])
{
	dlistnode * H,* p;
	int pos;

	H = dlist_create();

	dlist_show(H);
#if 0
	while(1)
	{
		printf("pos:");
		scanf("%d",&pos);
		p = dlist_get(H,pos);
		if(p)
		{
			printf(" %d\n ",p->data);
		}
		
	}
#endif

	while(1)
	{
		printf("value:");
		scanf("%d",&pos);
		dlist_delete(H,pos);
		dlist_show(H);
	}
	

	return 0;
}
