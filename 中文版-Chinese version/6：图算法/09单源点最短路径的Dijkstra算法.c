//��Դ�����·����Dijkstra�㷨
#include<stdio.h>
#define MAXSIZE 6
#define INF 32767
void Ppath(int path[],int i,int v0)
{//����ݹ�������·��(Դ��Ϊv0)�ϵĶ���
   int k;
   k=path[i];
   if(k!=v0)//����vk����Դ��v0ʱ
   {
   	Ppath(path,k,v0); //�ݹ���Ҷ���vk��ǰһ������
	printf("%d,",k); 
	} 
 } 
 
void Dispath(int dist[],int path[],int s[],int v0,int n)//������·���ĺ���
{
	int i;
	for(i=0;i<n;i++)
	if(s[i]==1)
	{
		printf("��%d��%d�����·������Ϊ��%d��·��Ϊ��",v0,i,dist[i]);
		printf("%d,",v0);   //���·���ϵ�Դ��v0 
		Ppath(path,i,v0);   //���·���ϵ��м䶥��vi 
		printf("%d\n",i);   //���·���ϵ��յ� 
	}
	else
	  printf("��%d��%d������·��\n",v0,i); 
 } 
 
void Dijkstra(int gm[][MAXSIZE],int v0,int n)
{
	int dist[MAXSIZE],path[MAXSIZE],s[MAXSIZE];
	int i,j,k,mindis;
	for(i=0;i<n;i++)
	{
		dist[i]=gm[v0][i];   //v0��vi�����·����ֵ����dist[i]
		s[i]=0;    //s[i]=0��ʾ����vi����T��
		if(gm[v0][i]<INF)  //·����ʼ����MAXCOSTΪ��ȡ������� 
		   path[i]=v0;   //Դ��v0��vi��ǰ���·���е�ǰһ������
		else
		   path[i]=-1;   //v0��viû�б� 
	}
	s[v0]=1;
	path[v0]=0;  //v0���뼯��S��v0�ĵ�ǰ���·������ǰһ������ 
	for(i=0;i<n;i++)//�Գ�v0���n-1����Ѱ�����·������ѭ��n-1�� 
	{
		mindis=INF;
		for(j=0;j<n;j++) //�ӵ�ǰ����T��ѡ��һ��·��������̵Ķ���vk
		  if(s[j]==0&&dist[j]<mindis)
		  {
		  	k=j;
		  	mindis=dist[j];
		   } 
		s[k]=1;   //����vk���뼯��S��
		for(j=0;j<n;j++)//����Դ��v0������T����һ��������·������
		    if(s[j]==0)  //����vj�ڼ���T��
		      if(gm[k][j]<INF&&dist[k]+gm[k][j]<dist[j])
			  {//��v0��vj��·������С��v0��vk��vk��vj��·������ʱ
			     dist[j]=dist[k]+gm[k][j];
				 path[j]=k;  //vk�ǵ�ǰ���·����vj��ǰһ������ 
			   } 
	}
	Dispath(dist,path,s,v0,n);//������·�� 
}

int main()
{
	int g[MAXSIZE][MAXSIZE]={{INF,20,15,INF,INF,INF},{2,INF,INF,INF,10,30},{INF,4,INF,INF,INF,10},
	                     {INF,INF,INF,INF,INF,INF},{INF,INF,INF,15,INF,INF},{INF,INF,INF,4,10,INF}};  //�����ڽӾ���g�����ڽӾ���g��ֵ
    Dijkstra(g,0,6);//�󶥵�0�����·�� 
	return 0;
}
