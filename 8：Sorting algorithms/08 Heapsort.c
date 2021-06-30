//������
#include<stdio.h>
#define MAXSIZE 30
typedef struct{
	int key;
	char data;
}RecordType;

void HeapAdjust(RecordType R[],int s,int t)
{//��R[s]~R[t]��R[s]�������ѵĶ��壬��ֻ��R[s]���е���ʹR[s]Ϊ������ȫ��������Ϊһ���� 
	int i,j;
	R[0]=R[s];
	i=s;
	for(j=2*i;j<=t;j=2*j) //�عؼ��ֽϴ�ĺ������µ������ȼٶ�Ϊ���� 
	{
		if(j<t&&R[j].key<R[j+1].key)
		  j=j+1;         //�Һ��ӽ��Ĺؼ��ִ������Һ������µ��� 
		if(R[0].key>R[j].key)  //R[0](��R[s])�Ĺؼ����Ѵ���R[j]�Ĺؼ���ֵ����������ѵĶ��壬�ʲ������µ��� 
		  break;
		R[i]=R[j];  //���ؼ��ִ�ĺ��ӽ��R[j]������˫�׽��R[i]
		i=j;  //��λ�ں��ӽ��������µ���   
	 } 
	R[i]=R[0];   //�ҵ�����Ѷ����R[0](��R[s])����λ��i����R[s]�����ڴ� 
 } 

void HeapSort(RecordType R[],int n)
{
    int i;
	for(i=n/2;i>0;i--) //����ȫ���������ն˽�㰴R[n/2],R[n/2-1],...,R[1]��˳������ʼ�� 
		HeapAdjust(R,i,n);
    for(i=n;i>1;i--)
	{
	  R[0]=R[1]; //�Ѷ���R[1]��ѵ׵�R[i]���� 
	  R[1]=R[i];
	  R[i]=R[0];
	  HeapAdjust(R,1,i-1);  //��δ�����ǰi-1��������µ���Ϊ��	
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
	HeapSort(R,i-1);
	printf("\nOutput data in list after Sort:\n"); 
	for(j=1;j<i;j++)
	  printf("%4d",R[j].key);
	printf("\n");
	return 0;     
}
