//�������������������Ĳ��Һ�ɾ��
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct node{
	int key;
	struct node *lchild,*rchild;
}BSTree;
void BSTreeCreat(BSTree *t,int k)
{//�ǿն����������в���һ����� 
	BSTree *p,*q;
	q=t;
	while(q!=NULL)
	  if(k==q->key)
	    goto L1;
	  else if(k<q->key){//kС�ڽ��*q�Ĺؼ�����t������������ 
	  	p=q;
	  	q=q->lchild;
	  }
	  else
	  {//k���ڽ��*q�Ĺؼ���ֵ��t������������ 
	  	p=q;
	  	q=p->rchild;
	  }
	  q=(BSTree*)malloc(sizeof(BSTree));
	  q->key=k;
	  q->lchild=NULL;
	  q->rchild=NULL;
	  if(p->key>k)
	     p->lchild=q;//��ΪԭҶ���*p�����Ӳ��� 
	  else
	     p->rchild=q;//��ΪԭҶ���*p���Һ��Ӳ���
	  L1: ;   
 } 
BSTree *BSTSearch(BSTree *t,int k)
{//��ָ��t��ָ�Ķ����������в��ҹؼ���ֵΪk�Ľ�� 
	while(t!=NULL)
	if(k==t->key)
	   return t;
	else
	   if(k<t->key)
	     t=t->lchild;//kС�ڽ��*q�Ĺؼ�����t������������ 
	   else 
	     t=t->rchild;//k���ڽ��*q�Ĺؼ�����t������������
	return NULL; 
}

void Inorder(BSTree *p)
{
	if(p!=NULL)
	{
		Inorder(p->lchild);
		printf("%4d",p->key);
		Inorder(p->rchild);
	}
}

void BSTDelete(BSTree **t,int k)//�ڶ�����������ɾȥ���
{
	BSTree *p,*q,*r;
	q=*t;
	p=*t;
	if(q==NULL)
	  goto L2;
	if(q->lchild==NULL&&q->rchild==NULL&&q->key==k)
	{
		q=NULL;
		goto L2;
	}
	while(q!=NULL)
	 if(k==q->key)
	   goto L1;
	 else
	   if(k<q->key)
	   {
	   	 p=q;
	   	 q=q->lchild;
	   }
	   else
	   {
	   	 p=q;
	   	 q=q->rchild;
	   }
	if(q==NULL)
	  goto L2;   //�����޴˴�ɾ���*q 
	L1:if(q->lchild==NULL&&q->rchild==NULL) //��ɾ���*qΪҶ���,��һ����� 
	  if(p->lchild==q)
	    p->lchild=NULL; 
	  else
	    p->rchild=NULL;
	else
	  if(q->lchild==NULL)//��ɾ���*q�����������ڶ������ 
	    if(p->lchild==q)
		  p->lchild=q->rchild;
		else
		  p->rchild=q->rchild;
	  else
	    if(q->rchild==NULL)//��ɾ���*q������������������� 
		  if(p->lchild==q) //�ô�ɾ���*q������������ȡ����ɾ���*q
		    p->lchild=q->lchild;
		  else
		    p->rchild=q->lchild;
		else//��ɾ���*q��������������������� 
		{
			r=q->rchild;
			if(r->lchild==NULL&&r->rchild==NULL)
			{
				q->key=r->key;
				q->rchild=NULL;
			}
			else
			{
				p=q;
				while(r->lchild!=NULL)
				{
					p=r;
					r=r->lchild;
				}
				q->key=r->key;
				if(p->lchild==r)
				  p->lchild=r->rchild;
				else
				  p->rchild=r->rchild;
			}
		  }  
    L2: ;
 } 
 
int main()
{
	BSTree *p,*root;
	int i,n,x;
	printf("Input number of BSTree keys��\n");
	scanf("%d",&n);
	printf("Input key of BSTree:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(i==0)
		{
			root=(BSTree*)malloc(sizeof(BSTree));//���ɶ����������ĸ���� 
			root->lchild=NULL;
			root->rchild=NULL;
			root->key=x;
		}
		else
		   BSTreeCreat(root,x); 
	}
	printf("Output keys of BSTree by inorder:\n");
	Inorder(root);
	printf("\nInput key for search:\n");
	scanf("%d",&x);
	p=BSTSearch(root,x);
	if(p!=NULL)
	  printf("Found,key is %d!\n",p->key);
	else
	  printf("No found!\n");
	printf("\nInput key for delete:\n");
	scanf("%d",&x);
	BSTDelete(&root,x);
	printf("Output keys of BSTree by deleted:\n");
	Inorder(root);
	printf("\n");
	return 0; 
}
