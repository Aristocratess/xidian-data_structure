//��С��������Prim�㷨
#include<stdio.h>
#define MAXNODE 30
#define MAXCOST 32767
void Prim(int gm[][6],int closevertex[],int n)
{//�Ӵ洢���Ϊ0�Ķ������������ͨ������С��������gm���ڽӾ���nΪ�������������0~n-1�����㣩
//���ս�������С��������������closevertex�� 
	int lowcost[MAXNODE];
	int i,j,k,mincost;
	for(i=1;i<n;i++)
	{
		lowcost[i]=gm[0][i];  //��(u0,u1)��Ȩֵ��lowcost[i]
		closevertex[i]=0;  //�ٶ�����ui������u0��һ���� 
	}
	lowcost[0]=0;//�����Ϊ0�Ķ���u0����������С����������ʱu0�Ѿ�����U�� 
	closevertex[0]=0;
	for(i=1;i<n;i++)//��n��������������n-1���ߵ���С������(��n-1�ɣ� 
	{
		mincost=MAXCOST;
		j=1;k=0;
		while(j<n)
		{
			if(lowcost[j]!=0&&lowcost[j]<mincost)
			{
				mincost=lowcost[j];
				k=j;//������СȨֵ����V-U���еĶ������j 
			}
			j++; 
		 } 
		printf("Edge:(%d,%d),Weight:%d\n",k,closevertex[k],mincost);
		lowcost[k]=0;
		for(j=1;j<n;j++)
		  if(lowcost[j]!=0&&gm[k][j]<lowcost[j])
		  {//������k����U����ʹ����k����һ����j(��V-U����)���ɵı�Ȩֵ��С��ı�lowcost[j]Ϊ���Сֵ��
		   //��������СȨֵ�ı�(j,k)����closevertex����
		   lowcost[j]=gm[k][j];
		   closevertex[j]=k; 
		  }
	 } 
 } 

int main()
{
	int closevertex[MAXNODE];
	int g[6][6]={{100,6,1,5,100,100},{6,100,5,100,3,100},{1,5,100,5,6,4},{5,100,5,100,100,2},{100,3,6,100,100,6},{100,100,4,2,6,100}};
	Prim(g,closevertex,6);
	return 0;
}
