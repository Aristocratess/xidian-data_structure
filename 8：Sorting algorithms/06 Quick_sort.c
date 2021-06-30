//��������
#include<stdio.h>
#define MAXSIZE 30
typedef struct{
	int key;
	char data;
}RecordType;
int Partition(RecordType R[],int i,int j)
{//��R[i]~R[j]����R[i]Ϊ��׼��¼���л��֣�������R[i]�ڻ��ֺ����ȷλ�� 
	R[0]=R[i];   //�ݴ��׼��¼
	while(i<j)
	{
		while(i<j&&R[j].key>=R[0].key)
		    j--;
		if(i<j)
		{
		  R[i]=R[j];
		  i++;	
		}
		while(i<j&&R[i].key<=R[0].key)
		    i++;
		if(i<j)
		{
			R[j]=R[i];
			j--;
		}	    
	 }
	R[i]=R[0];   //����׼��¼R[0]��������(ָ�ź���ʱ)Ӧ���õ�λ��
	return i;   //���ػ�׼��¼R[0]���շ��õ�λ��  
 }

void QuickSort(RecordType R[],int s,int t)
{
	int i;
	if(s<t)
	{
		i=Partition(R,s,t); //iΪ��׼��¼��λ�ò��ɴ˽����ΪR[s]~R[i-1]��R[i+1]~R[t]������
		QuickSort(R,s,i-1);
		QuickSort(R,i+1,t); 		
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
  QuickSort(R,1,i-1);
  printf("\nOutput data in list after Sort:\n");
  for(j=1;j<i;j++)
    printf("%4d",R[j].key);
  printf("\n");
  return 0;			
}  
