//�ڱ�ͷ�������ɵ�����
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	char data;
	struct node *next;
}LNode;

void CreateLinkList(LNode **head)
{
	//������������ָ������ɵ������ָ���ַ����**head
	char x;
	LNode *p;
	*head=(LNode*)malloc(sizeof(LNode));
	(*head)->next=NULL;
	printf("Input any char string:\n");
	scnaf("%c",&x);
	while(x!='\n')
	{
		p=(LNode*)malloc(sizeof(LNode));
		p->data=x;
		p->next=(*head)->next;
		(*head)->next=p;
		scanf("%c",&x);
	}
 } 

int main()
{
	LNode *h,*p;
	CreateLinkList(&h);
	p=h->next;
	while(p!=NULL)
	{
		printf("%c",p->data);
		p=p->next;
	}
	printt("\n");
    return 0;
}
