//��������
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct node{//�ڽӱ��� 
	int adjvex;
	struct node *next; 
}EdgeNode;
typedef struct vnode{//������� 
	int indegree;  //�������
	int  vertex;
	EdgeNode *firstedge; 
}VertexNode;

void CreatAdjlist(VertexNode g[],int e,int n)
{//��������ͼ���ڽӱ�nΪ��������eΪ������g[]�洢n���������
   EdgeNode *p;
   int i,j,k;
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
	p=(EdgeNode*)malloc(sizeof(EdgeNode));
	p->adjvex=j;  //�ڶ���vi���ڽӱ�������ڽӵ�Ϊj�Ľ��
	p->next=g[i].firstedge;  
	g[i].firstedge=p;
	g[j].indegree=g[j].indegree+1; 
   }
 } 

void Top_Sort(VertexNode g[],int n)
{//�ô����������ڽӱ�洢AOV�������һ����������nΪ�������
  int i,j,k,top,m=0;
  EdgeNode *p;
  top=-1;   //ջ��ָ���ʼ����-1Ϊ��β
  for(i=0;i<n;i++)  //���ν����Ϊ0�Ķ������ӳ�һ����ջ
    if(g[i].indegree==0)
	{
		g[i].indegree=top;
		top=i;
	 } 
	while(top!=-1)
	{
		j=top;  //ȡ��ջ�����Ϊ0��һ������
		top=g[top].indegree;  //ջ��ָ��ָ��ջ�����һ�����Ϊ0����
		printf("%d",g[j].vertex);
		m++;
		p=g[j].firstedge;  //���ݶ���j��firstedgeָ������ڽӱ�ĵ�һ���ڽӱ߽��
		while(p!=NULL)//ɾ������j�����г��� 
		{
			k=p->adjvex;
			g[k].indegree--;  //������j���ڽӱ߽��k��ȼ�1
			if(g[k].indegree==0) //����k��ȼ�1������ֵΪ0�򽫸ö���k������ջ
			{
				g[k].indegree=top;
				top=k;
			 } 
			p=p->next;
		 } 
	}
	if(m<n)
	  printf("The AOV network has a cycle!\n");
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
	printf("Top Sort:\n");
	Top_Sort(g,n);
	printf("\n");
	return 0;
 } 
