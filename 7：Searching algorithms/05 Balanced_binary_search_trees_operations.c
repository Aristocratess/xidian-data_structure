//ƽ��������Ľ��������Ĳ��Һ�ɾ��
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct node{
	int key;
	struct node *lchild,*rchild;
}BSTree;
int Depth(BSTree *p)//������������(�������) 
{
	int lchild,rchild;
	if(p==NULL)
	   return 0;
	else
	{
		lchild=Depth(p->lchild); //���������߶� 
		rchild=Depth(p->rchild); //���������߶�
		return lchild>rchild?(lchild+1):(rchild+1); 
	}
 } 

void AVL_Revolve(BSTree **p,int k)//�Զ���������ƽ�⴦��
{
	BSTree *q,*r;
	switch(k){
		case 1:r=(*p)->lchild;
		       (*p)->lchild=r->rchild;
		       r->rchild=*p;
		       break;   //LL����ת����
		case 2:q=(*p)->lchild;
		       r=q->lchild;
			   (*p)->lchild=r->rchild;
			   q->rchild=r->lchild;
			   r->lchild=q;
			   r->rchild=*p;
			   break;  //LR����ת���� 
		case 3:q=(*p)->rchild;
		       r=q->lchild;
		       (*p)->rchild=r->lchild;
			   q->lchild=r->lchild;
			   r->rchild=q;
			   r->lchild=*p;
			   break;  //RL����ת���� 
		case 4:r=(*p)->rchild;
		       (*p)->rchild=r->lchild;
			   r->lchild=*p;  //RR����ת����   
	}
	*p=r;   //������ת���������������ָ�� 
 } 
 
int Preorder_AVL(BSTree **t)//�����������������ƽ�⴦��
{
	BSTree *stack[MAXSIZE],*p=*t,*r=p;
	int i=0,k,m=0,b=0;
	stack[0]=NULL;
	while(p!=NULL||i>0) //��ָ��p���ջ�ջ����(i>0)
	  if(p!=NULL)
	  {
	  	k=0;
	  	if(Depth(p->lchild)-Depth(p->rchild)==2)  //����������Ȳ�ֵΪ2ʱ
		   if(Depth(p->lchild->lchild)>Depth(p->lchild->rchild))
		       k=1;     //LL��
		   else
		       k=2;     //LR��
		if(Depth(p->lchild)-Depth(p->rchild)==-2)  //����������Ȳ�ֵΪ-2ʱ
		   if(Depth(p->rchild->lchild)>Depth(p->rchild->rchild))
		       k=3;    //RL�� 
		   else
		       k=4;   //RR��
	    if(k>0)
		{
			if(*t==p)
			  m=1; //��ƽ�⴦��������������ƽ��������ĸ����ʱ��m=1
			AVL_Revolve(&p,k);   //������p����ƽ�⴦��
			if(m)
			  *t=p;  //m=1Ӧ��ƽ���������������Ϊƽ��������ĸ���� 
			if(b&&p!=*t)
			   r->rchild=p;  //��������㲻Ϊ�����ʱ������Ϊ�������Һ���
			if(!b&&p!=*t)
			   r->lchild=p;  //��������㲻Ϊ�����ʱ������Ϊ����������
			return 1;   //��ƽ�⴦�� 
			} 
			stack[++i]=p;  //���ý��ѹջ
			r=p,b=0; //rָ��*p�ĸ���㣬b=0��ʾ*p��*r������
		    p=p->lchild; //�����������±���   
	   } 
	   else
	   {
	   	 p=stack[i--];  //��������������Ľ����ջ�е��� 
	   	 r=p;b=1;   //rָ��*p�ĸ���㣬b=1��ʾ*p��*r���Һ���
	     p=p->rchild;  //�Ӹý���������ĸ���ʼ���������������±��� 
		} 
		return 0;   //��ƽ�⴦�� 
 }
 
void AVL_TreeCreat(BSTree **t,int key)
{
	BSTree *p,*q;
	q=*t;
	while(q!=NULL)
	  if(key==q->key)
	     goto L1;   //���ҳɹ����������½��
	  else
	if(key<q->key)//kС�ڽ��*q�Ĺؼ���ֵ��t������������ 
	{
		p=q;
		q=q->lchild;
	 } 
	else //k���ڽ��*q�Ĺؼ���ֵ��t������������
	{
		p=q;
		q=p->rchild;
	 } 
	q=(BSTree*)malloc(sizeof(BSTree));
	q->key=key;
	q->lchild=NULL; //����ΪҶ�����룬������ָ���Ϊ��
	q->rchild=NULL;
	if(p->key>key)
	  p->lchild=q;  //��ΪԭҶ���*p�����Ӳ���
	else
	  p->rchild=q;  //��ΪԭҶ���*p���Һ��Ӳ���
	while(Preorder_AVL(t)); //����ƽ�⴦��
   L1: ; 
  }  
  
BSTree *BSTSearch(BSTree *t,int k)//��������������
{//��ָ��t��ָ�Ķ����������в��ҹؼ���ֵΪk�Ľ�� 
	while(t!=NULL)
	if(k==t->key)
	   return t;  
	else
	  if(k<t->key)
	     t=t->lchild;  //kС�ڸ����*t�Ĺؼ���ֵ��t������������
	  else
	     t=t->rchild;
	return NULL; 
 } 
 
void Preorder(BSTree *p)
{
	if(p!=NULL)
	{
		printf("%4d",p->key);
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
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

void BSTDelete(BSTree **t,int key)//��ƽ���������ɾȥ��� 
{
	BSTree *p,*q,*r;
	q=*t;
	p=*t;
	if(q==NULL)
	 goto L2;
	if(q->lchild==NULL&&q->rchild==NULL&&q->key==key)
	{//��t�н���һ����ɾ���*q
	   q=NULL;
	   goto L2; 
	 } 
	while(q!=NULL)
	  if(key==q->key)
	     goto L1;
	  else
	    if(key<q->key)
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
	  goto L2; //�����޴˴�ɾ���*q
	L1:if(q->lchild==NULL&&q->rchild==NULL) //��ɾ���*qΪҶ��㣬����(1)�����
		  if(p->lchild==q)
		    p->lchild=NULL;
		  else
		    p->rchild=NULL;
	   else
	    if(q->lchild==NULL) //��ɾ���*q�������������ڣ�2�������
		  if(p->lchild==q) //��ɾ���*q������������ȡ����ɾ���*q
		    p->lchild=q->rchild;
		  else
		    p->rchild= q->rchild;
		else
		  if(q->rchild==NULL) //��ɾ���*q�������������ڣ�3�������
		     if(p->lchild==q)//��ɾ���*q������������ȡ����ɾ���*q 
			   p->lchild=q->lchild;
			 else
			   p->rchild=q->lchild;
		  else //��ɾ���*q����������������(4)�����
		  {
		    r=q->rchild;
			if(r->lchild==NULL&&r->rchild==NULL)
			{//��ɾ���*q������������һ�������
			   q->key=r->key; //����������������ȡ����ɾ���*q
			   q->rchild=NULL; 
			}
			else
			{
			  p=q; //��pָ��"�����½��"��˫�׽��
			  while(r->lchild!=NULL) //����"�����½��"
			  {
			  	p=r;
			  	r=r->lchild;
			   } 
			  q->key=r->key;  //"�����½��"�Ĺؼ���ֵ�ʹ�ɾ���*q�Ĺؼ���
			  if(p->lchild==r)  //ɾȥ"�����½�㡱
			     p->lchild=r->rchild;
			  else
			     p->rchild=r->rchild; 
			}	
		  }			 
	while(Preorder_AVL(t));//����ƽ�⴦�� 
   L2: ;		  	 
}

int main()
{
	BSTree *p,*root;
	int i,n,x;
	printf("Input number of BSTree keys:\n");  //����һ��ƽ�������
	scanf("%d",&n);
	printf("Input key of BSTree:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(i==0)
		{//����ƽ��������ĸ����
		  root=(BSTree*)malloc(sizeof(BSTree));
		  root->lchild=NULL;
		  root->rchild=NULL;
		  root->key=x; 
		}
		else
		  AVL_TreeCreat(&root,x);//�ǿ�ƽ��������в���һ����� 
	 } 
	printf("Output keys of BSTree by Preorder:\n");
	Preorder(root);
	printf("\nOutput keys of BSTree by Inorder:\n");
	Inorder(root);
	printf("\nDepth=%d\n",Depth(root));  //���ƽ������������
	printf("Input key for search:\n");
	scanf("%d",&x);
	p=BSTSearch(root,x);
	if(p!=NULL)
	  printf("Found!Key is %d!\n",p->key);
	else
	  printf("No found!\n");
	printf("Input key for delete:\n");
	scanf("%d",&x);
	BSTDelete(&root,x);  //��ƽ���������ɾ���ùؼ��ֵļ�¼
	printf("Output keys of BSTree by Preorder:\n");
	Preorder(root);
	printf("\nOutput keys of BSTree by deleted:\n");
	Inorder(root);
	printf("\nDepth=%d\n",Depth(root)); //���ƽ������������
	return 0; 
}
