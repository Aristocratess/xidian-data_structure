//�鲢����ݹ�ʵ��
#include<stdio.h>
#define MAXSIZE 30
typedef struct{
	int key;
	char data;
}RecordType;

void Merge(RecordType R[],RecordType R1[],int s,int m,int t)
{//�������R[s]~R[m]��R[m+1]~R[t]�ϲ�Ϊһ�������R1[s]~R1[t] 
	int i,j,k;
	i=s;
	j=m+1;
	k=s;
	while(i<=m&&j<=t)
	//�����������ļ�¼���ؼ��ִ�С�ռ�����R1��ʹ��R1ҲΪ�����
     if(R[i].key<=R[j].key)
	    R1[k++]=R[i++];
     else
	    R1[k++]=R[j++];
	while(i<=m)
	   R1[k++]=R[i++];
	while(j<=t)
	   R1[k++]=R[j++];   				 
}

void MSort(RecordType R[],RecordType R1[],int s,int t)
{//�������R[s]~R[t]�鲢Ϊһ�������R1[s]~R1[t] 
	int m;
	RecordType R2[MAXSIZE];
	if(s==t)
	   R1[s]=R[s];
	else
	{
		m=(s+t)/2;  //�ҵ������R[s]~R[t]���м�λ�� 
		MSort(R,R2,s,m);
		MSort(R,R2,m+1,t);
		Merge(R2,R1,s,m,t);  //����һ�˽������R2[s]~R2[m]��R2[m+1]~R2[t]�鲢�������R1[s]~R1[t]�Ĳ��� 
		}    
}

int main()
{
	int i=1,j,x;
	RecordType R[MAXSIZE],R1[MAXSIZE];
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
	MSort(R,R1,1,i-1);
	printf("\nOutput data in list after Sort:\n");
	for(j=1;j<i;j++)
	   printf("%4d",R[j].key);
	printf("\n");
	return 0;      
 } 
