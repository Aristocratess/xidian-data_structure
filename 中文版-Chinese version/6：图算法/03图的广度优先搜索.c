//ͼ�Ĺ���������� 
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct node1{
	int adjvex;
	struct node1 *next; 
}EdgeNode;
typedef struct vnode{
	int vertex;
	EdgeNode *firstedge; //ָ���ڽӱ��һ���ڽӱ߽���ָ���� 
}VertexNode;

void CreatAdjlist(VertexNode g[],int e,int n)
{//��������ͼ���ڽӱ�nΪ��������eΪ������g[]�洢n��������� 
	EdgeNode *p;
	int i,j,k;
	printf("Input dataof vertex(0~n-1):\n");
	for(i=0;i<n;i++)
	{
		g[i].vertex=i;
		g[i].firstedge=NULL;
	}
	for(k=1;k<=e;k++)
	{
		printf("Input edge of(i,j):");
		scanf("%d,%d",&i,&j);
		p=(EdgeNode*)malloc(sizeof(EdgeNode));
		p->adjvex=j;   //�ڶ���vi���ڽӱ�������ڽӵ�Ϊj�Ľ�� 
		p->next=g[i].firstedge;
		g[i].firstedge=p;
		p=(EdgeNode*)malloc(sizeof(EdgeNode));
		p->adjvex=i;    //�ڶ���vj���ڽӱ�������ڽӵ�Ϊi�Ľ��
		p->next=g[j].firstedge;
		g[j].firstedge=p;
	}
}

typedef struct node{
	int data;
	struct node *next;
}QNode;
typedef struct{
	QNode *front,*rear;
}LQueue;

void Init_LQueue(LQueue **q)//����һ����ͷ���Ŀն���
{
	QNode *p;
	*q=(LQueue*)malloc(sizeof(LQueue));
	p=(QNode*)malloc(sizeof(QNode));
	p->next=NULL;
	(*q)->front=p;
	(*q)->rear=p;
 } 

int Empty_LQueue(LQueue *q)
{
	if(q->front==q->rear)
	   return 1;
	else
	   return 0;
}

void In_LQueue(LQueue *q,int x)
{
	QNode *p;
	p=(QNode*)malloc(sizeof(QNode));
	p->data=x;
	p->next=NULL;
	q->rear->next=p;
	q->rear=p;
}

void Out_LQueue(LQueue *q,int *x)
{
	QNode *p;
	if(Empty_LQueue(q))
	   printf("Queue is empty!\n");
	else
	{
		p=q->front->next;
		q->front->next=p->next;
		*x=p->data;
		free(p);
		if(q->front->next==NULL)//���Ӻ��Ϊ�գ�����Ϊ�ն���
		   q->rear=q->front; 
	}
}
int visited[MAXSIZE];
void BFS(VertexNode g[],LQueue *Q,int i)
{//����������������ڽӱ�洢��ͼ��gΪ�����QΪ��ָ�룬iΪ��i������
   int j,*x=&j;
   EdgeNode *p;
   printf("%4d",g[i].vertex);
   visited[i]=1;
   In_LQueue(Q,i);
   while(!Empty_LQueue(Q))
   {
   	Out_LQueue(Q,x);
   	p=g[j].firstedge;//���ݶ���j�ı�ͷָ��������ڽӱ�ĵ�һ���ڽӱ߽��
	while(p!=NULL)
	{
		if(!visited[p->adjvex])
		{
			printf("%4d",g[p->adjvex].vertex);
			visited[p->adjvex]=1;
			In_LQueue(Q,p->adjvex);
		}
		p=p->next;
	 } 
	} 
}

int main()
{
	int e,n;
	VertexNode g[MAXSIZE];
	LQueue *q;
	printf("Input number of node:\n");
	scanf("%d",&n);
	printf("Input number of edge:\n");
	scanf("%d",&e);
	printf("Make adjlist:\n");
	CreatAdjlist(g,e,n);
	Init_LQueue(&q);
	printf("BFSTraverse:\n");
	BFS(g,q,0);    //������ȱ������ڽӱ�洢������ͼ 
	printf("\n");
	return 0;
}
