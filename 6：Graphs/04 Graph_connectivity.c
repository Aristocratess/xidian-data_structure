//ͼ����ͨ��
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct node1{
	int adjvex;
	struct node1 *next;
}EdgeNode;
typedef struct vnode{
	int vertex;
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
		g[i].firstedge=NULL;   //��ʼ��ָ�򶥵�i���ڽӱ��ͷָ�� 
	}
	for(k=1;k<=e;k++)
	{
		printf("Input edge of(i,j):");
		scanf("%d,%d",&i,&j);
		p=(EdgeNode*)malloc(sizeof(EdgeNode));
		p->adjvex=j;
		p->next=g[i].firstedge;
		g[i].firstedge=p;
		p=(EdgeNode*)malloc(sizeof(EdgeNode));
		p->adjvex=i;
		p->next=g[j].firstedge;
		g[j].firstedge=p;
	}
 } 
int visited[MAXSIZE];
void DFS(VertexNode g[],int i)
{
	EdgeNode *p;
	printf("%4d",g[i].vertex);
	visited[i]=1;
	p=g[i].firstedge; //���ݶ���i��ָ��firstedge�������ڽӱ�ĵ�һ���ڽӱ߽��
	while(p!=NULL)
	{
		if(!visited[p->adjvex])
		   DFS(g,p->adjvex);
		p=p->next; 
	 } 
}
int count=0;
void ConnectEdge(VertexNode g[],int n)
{//������������������ڽӱ�洢��ͼ������gΪ�����nΪ�������
  int i;
  for(i=0;i<n;i++) 
     visited[i]=0;
  for(i=0;i<n;i++)
     if(!visited[i])
     {
     	DFS(g,i);//��δ���ʹ��Ķ���i��ʼ����
		count++;  //����һ����ͨ������count+1 
	 }
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
	printf("DFSTraverse:\n");
	ConnectEdge(g,n);//��ͼ����ͨ���� 
	printf("\nNumber of connect is %d\n",count);
	return 0;
}
