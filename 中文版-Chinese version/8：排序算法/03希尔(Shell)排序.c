//ϣ��(Shell)����
#include<stdio.h>
#define MAXSIZE 30
typedef struct{
	int key;
	char data;
}RecordType;
void ShellInsert(RecordType R[],int n,int d)
{//��R[1]~R[n]�еļ�¼����ϣ������dΪ����(����)����
   int i,j;
   for(i=d+1;i<=n;i++)
     if(R[i].key<R[i-d].key)
	 {//��R[i].keyС��ǰһ����d��R[i-d].keyӦ��ǰ��Ѱ�����λ�� 
	 	R[0]=R[i];  //�ݴ�������¼R[i]��ֵ
		for(j=i-d;j>0&&R[0].key<R[j].key;j=j-d)
		  R[j+d]=R[j];
		  /*��λ��R[i]֮ǰ�±��ֵΪ���������ı����ҹؼ��ִ���R[0].key(��ԭR[i].key)������ R[j]��˳�����һ����������λ��*/
		R[j+d]=R[0];   
	  } 
 } 

void ShellSort(RecordType R[],int n)
{//����������d[0]��d[1]��...��d[t-1]��˳���R[1]~R[n]��ϣ������
   int d[10],t,k;
   printf("\n�����������ӵĸ�����\n");
   scanf("%d",&t);
   printf("�ɴ�С����ÿһ���������ӣ�\n");
   for(k=0;k<t;k++)
      scanf("%d",&d[k]);  //�ɴ�С����ÿһ����������
   for(k=0;k<t;k++)
     ShellInsert(R,n,d[k]); //����������d[k]��˳���R����һ��ϣ������	   
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
	ShellSort(R,i-1);
	printf("\nOutput data in list after Sort:\n");
	for(j=1;j<i;j++)
	  printf("%4d",R[j].key);
	printf("\n");
	return 0;     
 } 
