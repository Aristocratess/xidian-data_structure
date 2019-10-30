//�������������� 
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	char data;
	int ltag,rtag;
	struct node *lchild;
	struct node *rchild;
}TBTree;
TBTree *pre;
void Thread(TBTree *p)
{
	if(p!=NULL)
	{
		Thread(p->lchild);//�ȶ�*p�������������������ˣ�*p���������������ڻ�������������������*p������
		if(p->lchild==NULL)
		{
			p->lchild=pre;
			p->ltag=1;
		 } 
		else
		   p->ltag=0;
		if(pre->rchild==NULL)
		{
			pre->rchild=p;
			pre->rtag=1;
		}
		else
		   pre->rtag=0;
	    pre=p;
	    Thread(p->rchild);
	}
 } 
 
TBTree *CreaThread(TBTree *b)
{
	TBTree *root;
	root=(TBTree*)malloc(sizeof(TBTree));
	root->ltag=0;
	root->rtag=1;
	if(b==NULL)
	{
		root->lchild=root;
	}
	else
	{
		root->lchild=b;  //root��lchildָ��ָ����������*b 
		pre=root;     //*pre��*p��ǰ����㣬preָ���������� 
		Thread(b);   //�Զ�����b�������������� 
		pre->rchild=root;//���������ָ��ͷ�������� 
		pre->rtag=1;
		root->rchild=pre;//ͷ����rchildָ��������Ϊָ�����һ����� 
	}
	return root;//������������ָ���������ͷ����ָ�� 
}

void Inorder(TBTree *b)
{//*bΪ����������������ͷ���
   TBTree *p;
   p=b->lchild;
   while(p!=b)//��p������ָ��ͷ����ָ��bʱ 
   {
   	  while(p->ltag==0)
   	     p=p->lchild;
   	  printf("%3c",p->data);
   	  while(p->rtag==1&&p->rchild!=b)
   	  {
   	  	p=p->rchild;
   	  	printf("%3c",p->data);
		 }
	  p=p->rchild;
   }
}

void Preorder(TBTree *p)
{
	if(p!=NULL)
	{
		printf("%3c",p->data);
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
}

void Createb(TBTree **p)
{
	char ch;
	scanf("%c",&ch);
	if(ch!='.')
	{
		*p=(TBTree*)malloc(sizeof(TBTree));
		(*p)->data=ch;
		Createb(&(*p)->lchild);
		Createb(&(*p)->rchild);
	}
	else
	   *p=NULL;
}

int main()
{
	TBTree *root,*p;
	printf("Preorder enter bitree with'...':\n");
	Createb(&root);
	printf("Preorder output:\n");
	Preorder(root);
	printf("\n");
	p=CreaThread(root);//����������
	printf("Inorder output:\n");
	Inorder(p);
	printf("\n");
	return 0; 
}
