//��������
#include<stdio.h>
#define MAXSIZE 30
#define Radix_MAX 10
#define d_MAX 3
typedef struct{
	int key;
	int keys[d_MAX]; //��Ų�ֺ�ĸ��ؼ����d_MAXΪ�ؼ���������ֵ 
	int next;
	char data;
}RecType;

void RadixSort(RecType R[],int d,int c1,int ct)
{//��R[1]~R[n]���л�������dΪ�ؼ���������c1~ctΪ����(��Ȩֵ)�ķ�Χ
    int i,j,k,m,p,t,f[Radix_MAX],e[Radix_MAX];
	p=1;
	for(i=0;i<d;i++) //����d�˷������ռ� 
	{
		for(j=c1;j<=ct;j++) //����ǰ��ն�ͷָ�� 
		   f[j]=0;
		while(p!=0)//δ���䵽���һ����¼R[n]������ΪR[n].next����0 
		{
			k=R[p].keys[i];  //kΪR[p]�е�i��ؼ���ֵ 
			if(f[k]==0)  //��k�������Ƿ�Ϊ�� 
			  f[k]=p;    //R[p]��Ϊ��k�����еĶ�ͷ������ 
			else
			  R[e[k]].next=p;  //��R[p]������k�����еĶ�β���
			e[k]=p;  //��k�����еĶ�βָ��e[k]ָ���µĶ�β���
			p=R[p].next;  //ȡ������R[p]֮��ļ�¼��������   
		}
		j=c1; //�ռ�c1~ct�������ϵļ�¼
		while(f[j]==0) //j����Ϊ��ʱ����������һ���ǿն���
		  j++;
		p=f[j];
		t=e[j]; //�ҵ���һ���ǿն���ʹpָ���ͷ��tָ���β
		while(j<ct) //δ�ռ������һ������ʱ������ռ�
		{
			j++;
			if(f[j]!=0)//��Ӧ�ö��в�Ϊ��ʱ
			{
				R[t].next=f[j];  //����һ�����еĶ�ͷ����ǰһ�����еĶ�β
				t=e[j];  //ʹtָ�����һ�����еĶ�β�������ж���һ�����е��ռ� 
			 } 
			R[t].next=0;  //�ռ���������һ����¼R[t]Ϊ�ռ����еĶ�β��־ 
		 } 
		m=p;   //mָ�������еĶ�ͷ
		printf("%5d",R[m].key);
		do
		{
			m=R[m].next;
			printf("%5d",R[m].key);
		 }while(R[m].next!=0);
		printf("\n");    
	 } 
 } 

void DistKeys(RecType R[],int n,int d,int c1,int ct)
{//�����ؼ��ַ���Ϊ��ؼ��ֵĻ������� 
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		R[i].next=i+1;  //����¼R[1]~R[n]������һ��������
		k=R[i].key; //ȡ��R[i]�ĵ��ؼ���
		for(j=0;j<d;j++)
		{
			R[i].keys[j]=k%(ct+1); //��R[i]�ĵ��ؼ���key����Ϊ��ؼ��ִ���R[i].keys[0]~R[i].keys[d]
			k=k/(ct+1); 
		 } 
	}
	R[n].next=0;  //�����һ����¼R[n]�Ķ�β��־
	RadixSort(R,d,c1,ct); 
 } 
 
 int main()
 {
 	int i=1,j,x;
 	RecType R[MAXSIZE];
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
	printf("\nSort, Output data in list after Sort:\n");
	DistKeys(R,i-1,d_MAX,0,9);  //���л�������
	return 0;    
 }
