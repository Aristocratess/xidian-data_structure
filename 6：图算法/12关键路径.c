//�ؼ�·��
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct node{
	int adjvex;
	int info;
	struct node *next;
}EdgeNode;
typedef struct vnode{
	int indegree;
	int vertex;
	EdgeNode *firstedge;
}VertexNode;
typedef struct{
	char data[MAXSIZE];
	int top;
}SeqStack;

void Init_SeqStack(SeqStack **s)
{
	*s=(SeqStack*)malloc(sizeof(SeqStack));
	(*s)->top=-1;
 } 

int Empty_SeqStack(SeqStack *s)
{
	if(s->top==-1)
	  return 1;
	else
	  return 0;
}

void Push_SeqStack(SeqStack *s,int x)
{
	if(s->top==MAXSIZE-1)
	   printf("Stack is full!\n");
	else
	{
		s->top++;
		s->data[s->top]=x; 
	}
}

void Pop_SeqStack(SeqStack *s,int *x)
{//��ջ*s�е�ջԪ�س�ջ��ͨ������x���ظ���������
   if(s->top==-1)
     printf("Stack is empty!\n");
	else
	{
		*x=s->data[s->top];
		s->top--;
	 } 
}

void print(VertexNode g[],int ve[],int vl[],int n)
{
	int i,j,e,l,dut;
	char tag;
	EdgeNode *p;
	printf("(vi,vj)dut���翪ʼʱ��  ����ʼʱ��  �ؼ��\n");
	for(i=0;i<n;i++)
	  for(p=g[i].firstedge;p!=NULL;p=p->next)
	  {
	  	j=p->adjvex;
	  	dut=p->info;
	  	e=ve[i];
	  	i=vl[j]-dut;
	  	tag=(e==l)?'*':' ';
	  	printf("(%d,%d)%4d%11d%11d%8c\n",g[i].vertex,g[j].vertex,dut,e,l,tag);
	  }
	for(i=0;i<n;i++)
	  printf("����%d�����緢��ʱ�����ٷ���ʱ��:%5d%5d\n",i,ve[i],vl[i]);
}

void CreatAdjlist(VertexNode g[],int e,int n)
{//��������ͼ���ڽӱ�nΪ��������eΪ������g[]�洢n���������
   EdgeNode *p;
   int i,j,k,w;
   printf("Input data of vertex(0~n-1):\n");
   for(i=0;i<n;i++)
   {
   	g[i].vertex=i;
   	g[i].firstedge=NULL;
   	g[i].indegree=0;
	} 
   for(k=1;k<=e;k++)
   {
   	printf("Input edge of(i,j):");
   	scanf("%d,%d",&i,&j);
   	printf("Input weight of(%d,%d):",i,j);
   	scanf("%d",&w);
   	p=(EdgeNode*)malloc(sizeof(EdgeNode));
   	p->adjvex=j;   //�ڶ���vi���ڽӱ�������ڽӵ�Ϊj�Ľ��
	p->info=w;
	p->next=g[i].firstedge;
	g[i].firstedge=p;
	g[j].indegree=g[j].indegree+1;
   }
}

void Toplogicalorder(VertexNode g[],int n){
	//AOE�����ڽӱ�洢����������¼������緢��ʱ��ve��Ϊȫ�ֱ������飩
	int i,j,k,dut,count,*x=&j;
	int ve[MAXSIZE],vl[MAXSIZE];
	EdgeNode *p;
	SeqStack *s,*t;
	Init_SeqStack(&s);
	Init_SeqStack(&t);
	count=0;
	for(i=0;i<n;i++)
	  ve[i]=0;
	for(i=0;i<n;i++)
	  if(g[i].indegree==0)
	    Push_SeqStack(s,i);
	while(!Empty_SeqStack(s))//����ȶ���ջs��Ϊ��ʱ
	{
	 Pop_SeqStack(s,x); //��������ȶ��� 
	 Push_SeqStack(t,j);  //������jѹ���������ж���ջt
	 count++; 
	 g[i].firstedge;//���ݶ���j��firstedgeָ������ڽӱ��е�һ���ڽӱ߽�� 
   	 while(p!=NULL)
	 {
		k=p->adjvex;
		g[k].indegree--;  //����j���ڽӱ߽��k����ȼ�1
		if(g[k].indegree==0)
		   Push_SeqStack(s,k); //����k��ȼ�1������ֵΪ0����ѹ������ȶ���ջs
		if(ve[j]+p->info>ve[k])
		   ve[k]=ve[j]+p->info;   //���㶥���¼������緢��ʱ��ve[k]
		p=p->next; 
	}
    }
    if(count<n)//�������ж������δ�ﵽnʱ��AOE���л�·
    {
   	 printf("The AOE network has a cycle!\n");
   	 goto L1;
	} 
    for(i=0;i<n;i++) //��ʼ������vl
      vl[i]=ve[n-1];
    while(!Empty_SeqStack(t))//�����������������������vlֵ 
    {
   	 Pop_SeqStack(t,x); 
   	 for(p=g[j].firstedge;p!=NULL;p=p->next)//���㶥���¼�����ٷ���ʱ��vl[j]
	 {
	 	k=p->adjvex;
	 	dut=p->info;
	 	if(vl[k]-dut<vl[j])
	 	   vl[j]=vl[k]-dut;
	  } 
   	 } 
    print(g,ve,vl,n);
    L1: ;
}

int main()
{
	int e,n;
	VertexNode g[MAXSIZE];
	printf("Input number of node:\n");
	scanf("%d",&n);
	printf("Input number of edge:\n");
	scanf("%d",&e);
	printf("Make adjlist:\n");
	CreatAdjlist(g,e,n);
	Toplogicalorder(g,n);  //������������ؼ�·��
	printf("\n");
	return 0; 
}
