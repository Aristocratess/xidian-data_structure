//Լɪ������(Josephus)���⣺����n����Χ��һȦ��˳����1~n���ɱ��Ϊk���˽���1��m�ı���������m���˳�Ȧ��
//�����ٴ�������һ�������¿�ʼ1��m�ı�����ֱ�������˶���ȦΪֹ���������Ȧ�˵ĳ�Ȧ���� 
#include<stdio.h> 
#include<stdlib.h>
typedef struct node{
	char data;
	struct node *next;
}LNode;

void Josephus(int n,int m,int k)
{
	LNode *p,*q;
	int i;
	p=(LNode*)malloc(sizeof(LNode));
	q=p;
	for(i=1;i<n;i++)
	{
	   q->data=k;
	   k=k%n+1;
	   q->next=(LNode*)malloc(sizeof(LNode));
	   q=q->next;
	}
	q->data=k;
	q->next=p;
	while(p->next!=p)
	{
		for(i=1;i<=m;i++)
		{
			q=p;
			p=p->next;
		}
		q->next=p->next;
		printf("%4d",p->data);
		free(p);
		p=q->next;
	}
	printf("%4d",p->data);
}

int main()
{
	int n,m,k;
	printf("Please input n,m,k:\n");
	scanf("%d,%d,%d",&n,&m,&k);
	Josephus(n,m,k);
	printf("\n");
	return 0;
}
