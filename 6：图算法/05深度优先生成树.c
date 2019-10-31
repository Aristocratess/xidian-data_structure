//�������������
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct node{
	int adjvex;
	struct node *next;
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
		g[i].firstedge=NULL;//��ʼ��ָ�򶥵�i���ڽӱ��ͷָ�� 
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
void DFSTree(VertexNode g[],int i)
{
	EdgeNode *p;
	visited[i]=1;
	p=g[i].firstedge;//���ݶ���i��ָ��firstedge�������ڽӱ�ĵ�һ���ڽӱ߽��
	while(p!=NULL) 
	{
		if(!visited[p->adjvex]){
			printf("(%d,%d),",i,p->adjvex);
			DFSTree(g,p->adjvex);
		}
		p=p->next;
	}
}

void DFSTraverse(VertexNode g[],int n)//����������������� 
{//������������������ڽӱ�洢��ͼ������gΪ�����nΪ�������
   int i;
   for(i=0;i<n;i++)
     visited[i]=0;
   for(i=0;i<n;i++)
     if(!visited[i])
	    DFSTree(g,i);//��δ���ʹ��Ķ���i��ʼ���� 
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
	DFSTraverse(g,n);
	printf("\n");
	return 0;
}
