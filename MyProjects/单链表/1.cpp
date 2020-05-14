/********************************************
*	时间			2020年3月13日07:54:45
*	创建人			覃安娜
*	实现			对单链表的操作
********************************************/

#include<stdio.h>
#include<stdlib.h>

typedef int datatype;

typedef struct node
{
	datatype data;
	struct node * next;
}listnode,*linklist;

linklist list_create()//创建一个只有头节点的空链表。①创建指针②申请空间③next部分为空
{
	linklist H;

	if((H = (linklist)malloc(sizeof(listnode)))==NULL)
	{
		puts("malloc failed\n");
		return H;
	}

	H->data = 0;
	H->next = NULL;

	return H;

}

/*******************************************
*	①先创建一个只有头结点的空链表，H指向链表，②再创建一个指针R等于H,且永远指向末节点的next,③由用户输入要插入的元素，此时封装好（用P指针），H->next=*,R就是这个节点的next,且next=NULL④再插入时，R->next=p
*******************************************/

linklist list_create2()
{
	linklist H,r,p;//r一直指向表尾,所以是从表尾插入
	datatype value;//value用来接收用户输入的值

	if((H = (linklist)malloc(sizeof(listnode)))==NULL)
	{
		puts("malloc failed\n");
		return H;
	}

	H->data = 0;
	H->next = NULL;
	r = H;

	while(1)
	{
		printf("please input your number(-1 exit):");
		scanf("%d",&value);
		if(value == -1)
			break;

		if((p = (linklist)malloc(sizeof(listnode)))==NULL)
		{
			puts("malloc failed\n");
			return H;
		}
		p->data = value;
		p->next = NULL;

		r->next = p;
		r = p;
	}


	return H;

}

void list_show(linklist H)//遍历链表，H指向头结点，此时是实现不带头结点的链表，所以从第二个开始遍历，H->next->data,当最后一个节点为空则结束
{
	int i=0;
	while(H->next)//当不是尾节点时一直遍历,为空时，0，不为真，退出循环
	{
		printf(" %d ",H->next->data);
		H = H->next;//循环，所以一直指向next
	}

	printf("\n");
}

//插入一个节点，①指针p，②则p->next=H->next（插入节点的后面那个节点也是前面节点的后面节点）,③H->next=p(插入节点的前面那个节点)
int list_head_insert(linklist H,datatype value)//先右后左
{
	linklist p;

	if((p=(linklist)malloc(sizeof(listnode))) == NULL)
	{
		printf("malloc failed\n");
		return -1;
	}
	p->data = value;//封装p指针指向的节点

	p->next = H->next;

	H->next = p;

	return 0;
}

//单链表的查找:①按序号找，比如我想找第二个节点看看里面存的什么②按指定的值查找，循环遍历
//链表头结点为H,从第二个节点开始标序号，0、1、2……（pos,所以查找的序号要在pos范围内)
linklist list_search(linklist H,int pos)
{
	int i = -1;//i是寻找过程中移动的值，pos是序号值，将第一次找的值设为-1，假如找的是pos值0，则只找一次：-1+1=0，就找到了0

	linklist p = H;

	if(pos<0)//不能找不在范围的（当前位置<0）
	{
		puts("input pos invalied\n");
		return NULL;
	}
	
	while(p->next && i < pos)//当p的next为空时，0退出循环
	{//在p不为空时继续循环,当i<pos时继续循环
		p = p->next;
		i++;
	}
	if(i == pos)//找到了
	{
		return p;
	}
	else//当i>pos时，不合法
	{
		printf("invalid\n");
		return NULL;
	}


}

//②按值查找,因为头结点是空的，是指针H指向的，所以创建一个p指针指向有效的下一个值，就是p=H->next，再判断p指针指向的p->data是不是要找的值，不是则一直找，直到p->next=NULL
linklist list_find(linklist H,datatype value)
{
	linklist p = H->next;

	while(p && p->data != value)//首先p是存在的，不是NULL,然后p的data不是已经找到的值，接下来才继续循环
	{
		p = p->next;
	}
	return p;
}

//按位置插入的实现：插入某个节点时，要知道前驱后继,先找到位置才能插入，当插入的位置是0时，前驱是0-1=-1

int list_insert(linklist H,datatype pos,datatype value)
{
	listnode *p,*q;//p是前驱，q是插入的节点
	if(pos == 0)//在查找时，不允许pos<0,但是插入时可以插入这个地方，所以要单独写，第0个前面也就是H
	{//此时插入在0节点，则插入后的节点就是0节点
		p = H;
	}
	else
	{
		p = list_find(H,pos-1);//p获取链表，如果不是0，就直接pos-1，找到前驱
	}


	if(p == NULL)//说明第pos-1的节点不存在，也就是要插入的节点不存在
	{
		printf("参数无效\n");
		return -1;
	}
	else//找到位置了
	{
		if((q = (linklist)malloc(sizeof(listnode))) == NULL)//q是插入的节点
		{
			printf("malloc failed\n");
			return -1;
		}
		q->data = value;
		q->next = p->next;//先写右边，再写左边
		p->next = q;
		return 0;
	}
}

//有序插入

int list_order_insert(linklist H,datatype value)
{
	linklist p,q;//q存储前驱节点的位置

	if((p == (linklist)malloc(sizeof(listnode))) == NULL)
	{
		printf("malloc failed\n");
		return -1;
	}
	p->data = value;//先封装一个插入的p节点
	
	q = H;//因为有可能插入比最小的还小的节点，也就是在头结点H后,所以应该把q等于H,从H开始
	while(q->next && q->next->data <value)//q与插入的节点的大小关系，q->next是尾部追加插入，
	{
		q = q->next;
	}
	
	p->next = q->next;
	q->next = p;
	return 0;
}


//链表按编号删除,要释放内存,先用q指针存储要删除的节点，然后前驱再直接指向后继，忽略中间这个删除的。q=p->next.p->next=q->next,free(q)
int list_delete(linklist H,int pos)
{
	linklist p,q;

	if(pos == 0)
	{
		p = H;
	}
	else
	{
		p = list_find(H,pos-1);
	}

	if(p == NULL || p->next == NULL)//p可以删除的是有效的，所以不为空，而且是last-1，因为下标是少一个，是不能是p的下一个为空，因为此时p已经是最后一个了
	{
		printf("非法\n");
		return -1;
	}
	else
	{
		q = p->next;
		p->next = q->next;
		free(q);
		q = NULL;

		return 0;
	}
}

/**********************************************
/按值删除
int list_value_delete(linklist H,datatype value)
{
	linklist p,q;
	while(p && p->data != value)//首先p是存在的，不是NULL,然后p的data不是已经找到的值，接下来才继续循环
	{
		p = H;
		p = p->next;
	}
	if(p->data == value)
	{

	
	return 0;
}
*************************************/

/***********************************

*	排序：将头结点拆分开，再将后面那个节点插入尾部，再按顺序插入后面的节点，依次插入即可排序。
*	利用指针p存储要插入的节点，插入后指针继续向后走。
*	指向后继的指针q。
*	在头结点有个指针r,存储最小的。

************************************/

void list_sort(linklist H)
{
	linklist p,q,r;

	p = H->next;//先定好p的位置
	H->next = NULL;//把头结点拆分，没有后继

	while(p)//当节点p不为空时执行循环
	{
		q = p;
		p = p->next;

		r = H;
		while(r->next && r->next->data < q->data)
		{
			r = r->next;
		}

		q->next = r->next;
		r->next = q;
	}
}

int main(int argc,const char * argv[])
{
	/*******************************
	静态实现，用的栈空间存储

	listnode n1;//第一个节点n1
	linklist p,q;//定义两个指针作为后面next部分

	n1.data = 10;//节点中data存放10
	n1.next = NULL;//没有下一个节点

	p = &n1;//p是指向这个n1节点的

	p->data = 20;//p指向的data部分是20

	**********************************/

	/*********************************

  动态分配空间，用malloc在堆上存储

	listnode n1;//第一个节点n1
	linklist q;

	q = (linklist)malloc(sizeof(listnode));
	q->data = 30;
	q->next = NULL;

	free(q);
	q = NULL;
  ************************************/
	//linklist p;
	linklist H;
	//int n;//接收用户输入的值

	H = list_create2();
	list_show(H);

	list_sort(H);
	list_show(H);
#if 0
	H = list_create();//创建空链表

	list_head_insert(H,10);//向H链表插入10
	list_head_insert(H,20);
	list_head_insert(H,30);
	list_show(H);


	printf("please input pos:");
	scanf("%d",&n);
	if((p = list_search(H,n)) != NULL)
	{
		printf("node data:%d\n",p->data);
	}
#endif

#if 0
	printf("please input value:");
	scanf("%d",&n);
	if((p = list_find(H,n)) != NULL)
	{
		printf("find:%d\n",p->data);
	}
	else
	{
		printf("no find %d\n",n);
	}


	printf("please input pos:");
	scanf("%d",&n);
	if(list_insert(H,n,90) == -1)
	{
		printf("insert failed!\n");
	}
	list_show(H);

	printf("please input pos:");
	scanf("%d",&n);
	if(list_delete(H,n) == -1)
	{
		printf("delete failed!\n");
	}
	list_show(H);


	list_order_insert(H,5);
	list_order_insert(H,35);
	list_order_insert(H,95);

	list_show(H);
#endif


	return 0;
}
