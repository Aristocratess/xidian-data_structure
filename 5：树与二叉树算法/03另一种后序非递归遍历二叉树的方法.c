//��һ�ֺ���ǵݹ�����������ķ��� 
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct node{
	char data;
	struct node *lchild,*rchild;
}BSTree;

void Postorder1(BSTree *p)
{
	BSTree *stack[MAXSIZE],*q;
	int b,i=-1;
	do{
		while(p!=NULL)
		{
			stack[++i]=p;
			p=p->lchild;
		}
		//ջ�������û�����ӻ����������ϵĽ�㶼�ѷ��ʹ�
		q=NULL;
		b=1;
		while(i>=0&&b)
		{
			p=stack[i];
			if(p->rchild==q)
			{
				printf("%3c",p->data);
				i--;
				q=p;
			}
			else
			{
				p=p->rchild;
				b=0;
			}
		 } 
	}while(i>=0);
 } 
 
 void Createb(BSTree **p)
 {
 	char ch;
 	scanf("%c",&ch);
 	if(ch!='.')
 	{
 		*p=(BSTree*)malloc(sizeof(BSTree));
 		(*p)->data=ch;
 		Createb(&(*p)->lchild);
 		Createb(&(*p)->rchild);
	 }
	else
	  *p=NULL;
 }
 
int main()
{
	BSTree *root;
	printf("Make a tree:\n");
	Createb(&root);
	printf("Postorder output:\n");
	Postorder1(root);
	printf("\n");
	return 0;
}
