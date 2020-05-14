/********************************************
*	ʱ��			2020��3��13��07:54:45
*	������			������
*	ʵ��			�Ե�����Ĳ���
********************************************/

#include<stdio.h>
#include<stdlib.h>

typedef int datatype;

typedef struct node
{
	datatype data;
	struct node * next;
}listnode,*linklist;

linklist list_create()//����һ��ֻ��ͷ�ڵ�Ŀ������ٴ���ָ�������ռ��next����Ϊ��
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
*	���ȴ���һ��ֻ��ͷ���Ŀ�����Hָ���������ٴ���һ��ָ��R����H,����Զָ��ĩ�ڵ��next,�����û�����Ҫ�����Ԫ�أ���ʱ��װ�ã���Pָ�룩��H->next=*,R��������ڵ��next,��next=NULL���ٲ���ʱ��R->next=p
*******************************************/

linklist list_create2()
{
	linklist H,r,p;//rһֱָ���β,�����Ǵӱ�β����
	datatype value;//value���������û������ֵ

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

void list_show(linklist H)//��������Hָ��ͷ��㣬��ʱ��ʵ�ֲ���ͷ�����������Դӵڶ�����ʼ������H->next->data,�����һ���ڵ�Ϊ�������
{
	int i=0;
	while(H->next)//������β�ڵ�ʱһֱ����,Ϊ��ʱ��0����Ϊ�棬�˳�ѭ��
	{
		printf(" %d ",H->next->data);
		H = H->next;//ѭ��������һֱָ��next
	}

	printf("\n");
}

//����һ���ڵ㣬��ָ��p������p->next=H->next������ڵ�ĺ����Ǹ��ڵ�Ҳ��ǰ��ڵ�ĺ���ڵ㣩,��H->next=p(����ڵ��ǰ���Ǹ��ڵ�)
int list_head_insert(linklist H,datatype value)//���Һ���
{
	linklist p;

	if((p=(linklist)malloc(sizeof(listnode))) == NULL)
	{
		printf("malloc failed\n");
		return -1;
	}
	p->data = value;//��װpָ��ָ��Ľڵ�

	p->next = H->next;

	H->next = p;

	return 0;
}

//������Ĳ���:�ٰ�����ң����������ҵڶ����ڵ㿴��������ʲô�ڰ�ָ����ֵ���ң�ѭ������
//����ͷ���ΪH,�ӵڶ����ڵ㿪ʼ����ţ�0��1��2������pos,���Բ��ҵ����Ҫ��pos��Χ��)
linklist list_search(linklist H,int pos)
{
	int i = -1;//i��Ѱ�ҹ������ƶ���ֵ��pos�����ֵ������һ���ҵ�ֵ��Ϊ-1�������ҵ���posֵ0����ֻ��һ�Σ�-1+1=0�����ҵ���0

	linklist p = H;

	if(pos<0)//�����Ҳ��ڷ�Χ�ģ���ǰλ��<0��
	{
		puts("input pos invalied\n");
		return NULL;
	}
	
	while(p->next && i < pos)//��p��nextΪ��ʱ��0�˳�ѭ��
	{//��p��Ϊ��ʱ����ѭ��,��i<posʱ����ѭ��
		p = p->next;
		i++;
	}
	if(i == pos)//�ҵ���
	{
		return p;
	}
	else//��i>posʱ�����Ϸ�
	{
		printf("invalid\n");
		return NULL;
	}


}

//�ڰ�ֵ����,��Ϊͷ����ǿյģ���ָ��Hָ��ģ����Դ���һ��pָ��ָ����Ч����һ��ֵ������p=H->next�����ж�pָ��ָ���p->data�ǲ���Ҫ�ҵ�ֵ��������һֱ�ң�ֱ��p->next=NULL
linklist list_find(linklist H,datatype value)
{
	linklist p = H->next;

	while(p && p->data != value)//����p�Ǵ��ڵģ�����NULL,Ȼ��p��data�����Ѿ��ҵ���ֵ���������ż���ѭ��
	{
		p = p->next;
	}
	return p;
}

//��λ�ò����ʵ�֣�����ĳ���ڵ�ʱ��Ҫ֪��ǰ�����,���ҵ�λ�ò��ܲ��룬�������λ����0ʱ��ǰ����0-1=-1

int list_insert(linklist H,datatype pos,datatype value)
{
	listnode *p,*q;//p��ǰ����q�ǲ���Ľڵ�
	if(pos == 0)//�ڲ���ʱ��������pos<0,���ǲ���ʱ���Բ�������ط�������Ҫ����д����0��ǰ��Ҳ����H
	{//��ʱ������0�ڵ㣬������Ľڵ����0�ڵ�
		p = H;
	}
	else
	{
		p = list_find(H,pos-1);//p��ȡ�����������0����ֱ��pos-1���ҵ�ǰ��
	}


	if(p == NULL)//˵����pos-1�Ľڵ㲻���ڣ�Ҳ����Ҫ����Ľڵ㲻����
	{
		printf("������Ч\n");
		return -1;
	}
	else//�ҵ�λ����
	{
		if((q = (linklist)malloc(sizeof(listnode))) == NULL)//q�ǲ���Ľڵ�
		{
			printf("malloc failed\n");
			return -1;
		}
		q->data = value;
		q->next = p->next;//��д�ұߣ���д���
		p->next = q;
		return 0;
	}
}

//�������

int list_order_insert(linklist H,datatype value)
{
	linklist p,q;//q�洢ǰ���ڵ��λ��

	if((p == (linklist)malloc(sizeof(listnode))) == NULL)
	{
		printf("malloc failed\n");
		return -1;
	}
	p->data = value;//�ȷ�װһ�������p�ڵ�
	
	q = H;//��Ϊ�п��ܲ������С�Ļ�С�Ľڵ㣬Ҳ������ͷ���H��,����Ӧ�ð�q����H,��H��ʼ
	while(q->next && q->next->data <value)//q�����Ľڵ�Ĵ�С��ϵ��q->next��β��׷�Ӳ��룬
	{
		q = q->next;
	}
	
	p->next = q->next;
	q->next = p;
	return 0;
}


//�������ɾ��,Ҫ�ͷ��ڴ�,����qָ��洢Ҫɾ���Ľڵ㣬Ȼ��ǰ����ֱ��ָ���̣������м����ɾ���ġ�q=p->next.p->next=q->next,free(q)
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

	if(p == NULL || p->next == NULL)//p����ɾ��������Ч�ģ����Բ�Ϊ�գ�������last-1����Ϊ�±�����һ�����ǲ�����p����һ��Ϊ�գ���Ϊ��ʱp�Ѿ������һ����
	{
		printf("�Ƿ�\n");
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
/��ֵɾ��
int list_value_delete(linklist H,datatype value)
{
	linklist p,q;
	while(p && p->data != value)//����p�Ǵ��ڵģ�����NULL,Ȼ��p��data�����Ѿ��ҵ���ֵ���������ż���ѭ��
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

*	���򣺽�ͷ����ֿ����ٽ������Ǹ��ڵ����β�����ٰ�˳��������Ľڵ㣬���β��뼴������
*	����ָ��p�洢Ҫ����Ľڵ㣬�����ָ���������ߡ�
*	ָ���̵�ָ��q��
*	��ͷ����и�ָ��r,�洢��С�ġ�

************************************/

void list_sort(linklist H)
{
	linklist p,q,r;

	p = H->next;//�ȶ���p��λ��
	H->next = NULL;//��ͷ����֣�û�к��

	while(p)//���ڵ�p��Ϊ��ʱִ��ѭ��
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
	��̬ʵ�֣��õ�ջ�ռ�洢

	listnode n1;//��һ���ڵ�n1
	linklist p,q;//��������ָ����Ϊ����next����

	n1.data = 10;//�ڵ���data���10
	n1.next = NULL;//û����һ���ڵ�

	p = &n1;//p��ָ�����n1�ڵ��

	p->data = 20;//pָ���data������20

	**********************************/

	/*********************************

  ��̬����ռ䣬��malloc�ڶ��ϴ洢

	listnode n1;//��һ���ڵ�n1
	linklist q;

	q = (linklist)malloc(sizeof(listnode));
	q->data = 30;
	q->next = NULL;

	free(q);
	q = NULL;
  ************************************/
	//linklist p;
	linklist H;
	//int n;//�����û������ֵ

	H = list_create2();
	list_show(H);

	list_sort(H);
	list_show(H);
#if 0
	H = list_create();//����������

	list_head_insert(H,10);//��H�������10
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
