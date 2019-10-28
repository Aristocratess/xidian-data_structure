//�ɶ������ı������лָ�������
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct node{
	char data;
	struct node *lchild,*rchild;
}BSTree;
char pred[MAXSIZE],ind[MAXSIZE];
int i=0,j=0;
void Preorder(BSTree *p)
{
	if(p!=NULL)
	{
		pred[i++]=p->data;
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
 } 

void Inorder(BSTree *p)
{
	if(p!=NULL)
	{
		Inorder(p->lchild);
		ind[j++]=p->data;
		Inorder(p->rchild);
	}
}

void Pre_In_order(char pre[],char ind[],int i,int j,int k,int h,BSTree **p)
{//i��j��k��h�ֱ�Ϊ��ǰ�����������к��������е��¡��Ͻ� 
	int m;
	*p=(BSTree*)malloc(sizeof(BSTree));
	(*p)->data=pred[i];
	(*p)->data=pred[i];
	m=k;//mָ��ind�������洢�����������еĵ�һ����� 
	while(ind[m]!=pred[i])//�ҵ�������������������ڵ�λ�� 
	   m++;
	if(m==k)//��������������еĵ�һ�����ʱ���������� 
	  (*p)->lchild=NULL;
	else
	  Pre_In_order(pred,ind,i+1,i+m-k,k,m-1,&(*p)->lchild);//���ݸ���������ֳ��������е��������ּ������������������� 
	if(m==h)//��������������е����һ�����ʱ����������
	  (*p)->rchild=NULL;
	else
	  Pre_In_order(pred,ind,i+m-k+1,j,m+1,h,&(*p)->rchild);//���ݸ���������ֳ��������е��������ּ������������������� 
}

void Print_Inorder(BSTree *p)
{
	if(p!=NULL)
	{
		Print_Inorder(p->lchild);
		printf("%3c",p->data);
		Print_Inorder(p->rchild);
	}
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
	BSTree *root,*root1;
	printf("Preorder enter bitree with'..':\n");
	Createb(&root);
	printf("Inorder output root:\n");
	Print_Inorder(root);
	printf("\n");
	Preorder(root);
	printf("Inorder output:\n");
	Inorder(root);
	if(i>0)
	   Pre_In_order(pred,ind,0,i-1,0,j-1,&root1);
	printf("Inorder output root1:\n");
	Print_Inorder(root1);
	printf("\n");
	return 0;
}
