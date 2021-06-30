//��������
#include<stdio.h>
#define MAXSIZE 30
typedef struct{
	int key;
	char data;
}RecordType;
void D_Insert(RecordType R[],int n)
{//��n����¼����R[1]~R[n]����ֱ�Ӳ������� 
   	int i,j;
   	for(i=2;i<=n;i++)//����n-1������ 
   	   if(R[i].key<R[i-1].key)
   	   {//R[i].keyС��R[i-1].keyʱ�轫R[i]���뵽��������R[1]~R[i-1]�� 
   	   	  R[0]=R[i];   //���ò��Ҽ����ڲ�����������¼R[i]ֵ
		  j=i-1;		 
		  while(R[j].key>R[0].key)
		  {//���ؼ���ֵ����R[i].key(����ʱ��R[0].key)������R[j](j=i-1,i-2,...)˳�����һ����¼λ�� 
		  	R[j+1]=R[j];
		  	j--;
		  }		
		  R[j=1]=R[0];   //��R[i](Ҳ����ʱ��R[0]������Ӧ�嵽��λ���� 
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
	   printf("%4d",R[j].key);
	printf("\nSort:\n");
	D_Insert(R,i-1);  //����ֱ�Ӳ�������
	printf("\nOutput data in list after Sort:\n");
	for(j=1;j<i;j++)
	   printf("%4d",R[j].key);
	printf("\n");
	return 0;    
}

