//ÿһ�Զ�������·����Floyd�㷨
#include<stdio.h>
#define MAXSIZE 6
#define INF 32767
void Ppath(int path[][MAXSIZE],int i,int j)
{//ǰ��ݹ����·���ϵĶ��㣬MAXSIZEΪ����
   int k;
   k=path[i][j];
   if(k!=-1)  //����vk������� 
   {
   	Ppath(path,i,k);
   	printf("%d,",k);  
   	Ppath(path,k,j);
	} 
 } 
 
void Dispath(int A[][MAXSIZE],int path[][MAXSIZE],int n)//������·��
{
	int i,j;
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	    if(A[i][j]==INF)
	    {
	    	if(i!=j)
	    	  printf("��%d��%dû��·����\n",i,j);
	    	else
	    	{
	    		printf("��%d��%d��·�����ȣ�%d��·����",i,j,A[i][j]);
	    		printf("%d",i);   //���·���ϵ�������i 
	    		Ppath(path,i,j); //���·���ϵĸ��м����� 
	    		printf("%d\n",j); //���·���ϵ��յ����j 
			}
		}
 } 
 
void Floyd(int gm[][MAXSIZE],int n) //Floyd�㷨
{
	int A[MAXSIZE][MAXSIZE],path[MAXSIZE][MAXSIZE];
	int i,j,k;
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	  {
	  	A[i][j]=gm[i][j];  //A-1[i][j]�ó�ֵ 
	  	path[i][j]=-1; //��ʼʱ��ʾû���м䶥�� 
	   } 
	for(k=0;k<n;k++)  //��������k�����Ĵ�����ҵ�ǰ����֮������·������ 
	  for(i=0;i<n;i++)
	    for(j=0;j<n;j++)
	      if(A[i][j]>A[i][k]+A[k][j])
	      {
	      	A[i][j]=A[i][k]+A[k][j];//��vi��vj����vkʱ·�����ȸ���
			path[i][j]=k;  //��¼�м䶥��vk�ı�� 
		  }
	Dispath(gm,path,n);
 } 
 
int main()
{
	int g[MAXSIZE][MAXSIZE]={{INF,20,15,INF,INF,INF},{2,INF,INF,INF,10,30},{INF,4,INF,INF,INF,10},
	                      {INF,INF,INF,INF,INF,INF},{INF,INF,INF,15,INF,INF},{INF,INF,INF,4,10,INF}};
	Floyd(g,MAXSIZE);  //���ÿһ�Զ���֮������·��
	return 0; 
}
