//ѡ������
#include<stdio.h>
#define MAXSIZE 30
typedef struct{
	int key;
	char data;
}RecordType;

void SelectSort(RecordType R[],int n)
{
	int i,j,k;
	for(i=1;i<n;i++)
	{
		k=i;
		for(j=i+1;j<=n;j++)//�ӵ�i����¼��ʼ��n-i+1�������¼��ѡ���ؼ�����С�ļ�¼
		   if(R[j].key<R[k].key)
		      k=j;        //��¼�ؼ�����С�ļ�¼����λ��
		if(i!=k)
		{
		   R[0]=R[k];
		   R[k]=R[i];
		   R[i]=R[0];	
		}	   
	}
 } 
 
int main()
{
	int i=1,j,x;
	RecordType R[MAXSIZE];
	printf("Input data of list(-1 stop):\n");
	scanf("%d",&x);
	while(x!=-1)
	{
		R[i].key=x;
		scanf("%d",&x);
		i++;
	}
	printf("Output data in list:\n");
	for(j=1;j<i;j++)
	   printf("%4d",R[i].key);
	printf("\nSort:\n");
	SelectSort(R,i-1);
	printf("\nOutput data in list after Sort:\n");
	for(j=1;j<i;j++)
	   printf("%4d",R[j].key);
	printf("\n");
	return 0;      
 } 
