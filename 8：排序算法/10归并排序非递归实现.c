//�鲢����ǵݹ�ʵ��
#include<stdio.h>
#define MAXSIZE 30
typedef struct{
	int key;
	char data;
}RecordType;

void Merge(RecordType R[],RecordType R1[],int k,int n)
{//R1Ϊ�鲢��ʹ�õ��ݴ����� 
	int i,j,l1,u1,l2,u2,m;//l1��l2��u1��u2�ֱ�Ϊ���й鲢�����������ӱ���ϡ��½�
	l1=0;  //��ʼʱl1Ϊ��һ�������ӱ���½�ֵ0 
    m=0;  //mΪ����R1�Ĵ��ָ�� 
	while(l1+k<n) //�鲢�е������ӱ����һ���ӱ���Ϊkʱ 
	{
	  l2=l1+k;  //l2ָ��鲢�еڶ����ӱ�Ŀ�ʼ��
	  u1=l2-1;  //u1ָ��鲢�е�һ���ӱ��ĩ��(��ڶ����ӱ�����)
	  if(l2+k-1<n)
	    u2=l2+k-1; //u2ָ��鲢�еڶ����ӱ��ĩ��
      else 
	    u2=n-1; //�鲢�еڶ����ӱ�Ϊ���һ���ӱ��ҳ���С��k
      for(i=l1,j=l2;i<=u1&&j<=u2;m++)//�������ӱ�鲢Ϊһ�������ӱ����ݴ���R1 
	     if(R[i].key<=R[j].key)
		    R1[m]=R[i++];
	     else
		    R1[m]=R[j++];
	  while(i<=u1) //�ڶ����ӱ��ѹ鲢�꣬����һ���ӱ��ʣ���¼���Ƶ�R1
	     R1[m++]=R[j++];
	  while(j<=u2) //��һ���ӱ��ѹ鲢�꣬���ڶ����ӱ��ʣ���¼���Ƶ�R1
	     R1[m++]=R[j++];
	  l1=u2+1;    //��l1������������δ�鲢�ӱ�Ŀ�ʼ���������й鲢	 	 									
	} 	
 } 

void MergeSort(RecordType R[],int n)
{//�������R[s]~R[t]�鲢Ϊһ�������R1[s]~R1[t]
    int i,k;
	RecordType R1[MAXSIZE];
	k=1;   //��ʼʱ���鲢�������ӱ��Ⱦ�Ϊ1
	while(k<n)  //������δ�鲢Ϊһ�������ʱ(�ӱ���kС��n)�����鲢 
	{
		Merge(R,R1,k,n);  //�������ӱ����һ�˶�·�鲢
		for(i=0;i<n;i++)  //���ݴ���R1��һ�˹鲢������Ƶ�R�� 
		  R[i]=R1[i]; 
		k=2*k;  //һ�˹鲢�������ӱ�����ԭ�ӱ��ȵ�2�� 
	} 
 }

int main()
{
	int i=1,j,x;
	RecordType R[MAXSIZE];
	printf("Input data of list ��-1 stop):\n");
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
	MergeSort(R,i-1);
	printf("\nOutput data in list after Sort:\n");  //����鲢�����Ľ��
	for(j=1;j<i;j++)
	  printf("%4d",R[j].key);
	printf("\n");
	return 0;     
 } 
  
