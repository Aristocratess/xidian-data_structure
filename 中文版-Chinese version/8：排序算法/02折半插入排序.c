//�۰��������
#include<stdio.h>
#define MAXSIZE 30
typedef struct{
	int key;
	char data;
}RecordType;
void B_InsertSort(RecordType R[],int n)
{//��n����¼����R[1]~R[n]�����۰�������� 
	int i,j,low,high,mid;
	for(i=2;i<=n;i++)//����n-1������
	{
		R[0]=R[i];  //���ò��Ҽ����ڲ�����������¼R[i]ֵ
		low=1,high=i-1; //���ó�ʼ��������
		while(low<=high)
		{
			mid=(low+high)/2;
			if(R[0].key>R[mid].key)
			  low=mid+1;
			else
			  high=mid-1;  
		}
		for(j=i-1;j>=high+1;j--)//high+1Ϊ����λ�ã���R[i-1],R[i-2],...,R[high+1]˳�����һ��λ��
		  R[j+1]=R[j];
		R[high+1]=R[0];  //��R[i](��ΪR[0]����Ӧ�����λ��high+1)   
	 } 
 } 

int main()
{
	int i=1,j,x;
	RecordType R[MAXSIZE];
	printf("Input data of list(-1 stop):\n");  //��ÿһ����¼����ؼ���ֱ��-1���� 
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
	B_InsertSort(R,i-1); //�����۰��������
	for(j=1;j<i;j++)
	  printf("%4d",R[j].key);
	printf("\n");
	return 0;     
}
