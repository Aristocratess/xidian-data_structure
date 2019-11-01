//��С��������Kruskal�㷨
#include<stdio.h>
#define MAXSIZE 30
#define MAXCOST 32767
typedef struct{
	int u;
	int v;
	int w;
}Edge;

void Bubblesort(Edge R[],int e)
{//������R�еģ����߰�Ȩֵ��������
    Edge temp;
    int i,j,swap;
	for(i=0;i<e-1;j++)
	{
		swap=0;
		for(j=0;j<e-i-1;j++)
		   if(R[j].w>R[j+1].w)
		   {
		   	temp=R[j];
		   	R[j]=R[j+1];
		   	R[j+1]=temp;
		   	swap=1;
		   }
		   if(swap==0)break;//���˱Ƚ���δ���ֽ���������������źã� 
	 } 
 } 

void Kruskal(int gm[][6],int n)
{//�ڶ���Ϊn����ͨͼ�й�����С��������gmΪ��ͨ�����ڽӾ���
  int i,j,u1,v1,sn1,sn2,k;
  int vest[MAXSIZE];
  Edge E[MAXSIZE];
  k=0;
  for(i=0;i<n;i++)  //������E�洢��ͨ����ÿ���ߵ��������㼰���ϵ�Ȩֵ��Ϣ 
    for(j=0;j<n;j++) 
      if(i<j&&gm[i][j]!=MAXCOST)
	  {
	  	E[k].u=i;
	  	E[k].v=j;
	  	E[k].w=gm[i][j];
	  	k++;
	   } 
	Bubblesort(E,k);//����ð�����������E�е�k���߰�Ȩֵ�������� 
	for(i=0;i<n;i++)
	   vest[i]=i;  //��ÿ�������ò�ͬ��ͨ������ţ�����ʼʱ��n����ͨ����
	k=1;    //k��ʾ��ǰ�����������ĵ�n���ߣ���ֵΪ1 
	j=0;    //����E��Ԫ�ص��±꣬��ֵΪ0
	while(k<n)
	{
		u1=E[j].u;
		v1=E[j].v;
		sn1=vest[u1];
		sn2=vest[v1];
		if(sn1!=sn2)//������ ������ͬ���ϣ���ͨ��������ñ�Ϊ��С��������һ����
		{
			printf("Edge:(%d,%d),Weight:%d\n",u1,v1,E[j].w);
			k++;
			for(i=0;i<n;i++)
			  if(vest[i]==sn2)//���ϱ��Ϊsn2�ĵ�i�ű����Ÿ�Ϊsn1 
			    vest[i]=sn1; 
		 } 
		j++; //ɨ����һ���� 
	 } 
 } 

int main()
{
	int g[6][6]={{100,6,1,5,100,100},{6,100,5,100,3,100},{1,5,100,5,6,4},{5,100,5,100,100,2},{100,3,6,100,100,6},{100,100,4,2,6,100}};
	Kruskal(g,6);
	return 0;
}
