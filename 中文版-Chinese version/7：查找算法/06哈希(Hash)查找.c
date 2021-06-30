//��ϣ(Hash)����
#include<stdio.h>
#define MAXSIZE 11
#define key 11   //��ϣ���Ҳ��ó���ȡ�෨(x%key) 
void Hash_Insert(int Hash[],int x)
{
	int i=0,t;
	t=x%key;
	while(i<MAXSIZE)
	{
		if(Hash[t]<=-1)//�ҵ����λ��
		{
			Hash[t]=x;
			break;
		 } 
		else
		  t=(t+1)%key;
		i++;
	 } 
	if(i==MAXSIZE)
	  printf("Hashlist is full!\n");
}

void Hash_search(int Hash[],int x)
{
	int i=0,t;
	t=x%key;
	while(Hash[t]!=-1&&i<MAXSIZE)
	{
		if(Hash[t]==x)
		{
			printf("Hash position of %d is %d\n",x,t);//�ҵ�������ùؼ��ּ�����λ��
			break; 
		}
		else
		  t=(t+1)%key;  //�ÿ��Ŷ�ַ��ȷ����һ��Ҫ���ҵ�λ�� 
		i++;
	}
	if(Hash[t]==-1||i==MAXSIZE) //�鵽��λ�ñ��-1���ѵ�������ֵ
	  printf("No found!\n"); 
}

void Hash_Delete(int Hash[],int x)//��ϣ���ɾ��
{
	int i=0,t;
	t=x%key;
	while(Hash[t]!=-1&&i<MAXSIZE)  //�����ҵ�λ�ñ�ǲ�Ϊ-1��δ��������ֵ
	{
		if(Hash[t]==x)
		{
			Hash[t]=-2;
			printf("%d in Hashlist is deleted!\n",x);
			break;
		}
		else
		  t=(t+1)%key;
		i++;
	 }
	 if(i==MAXSIZE)
	    printf("Delete fail!\n"); 
 } 

int main()
{
	int i,x,Hash[MAXSIZE];
	for(i=0;i<MAXSIZE-1;i++)
	   Hash[i]=-1;
	i=0;
	printf("Make Hashlist,Input data(-1 stop):\n");
	scanf("%d",&x);
	while(x!=-1&&i<MAXSIZE)
	{
		Hash_Insert(Hash,x);
		scanf("%d",&x);
	}
	printf("Output Hashlist:\n");
	for(i=0;i<MAXSIZE;i++)
	  printf("%4d",Hash[i]);
	printf("\nInput search data:\n");
	scanf("%d",&x);
	Hash_search(Hash,x);
	printf("\nDelete record in Hashlist,Input key:\n");
	scanf("%d",&x);
	Hash_Delete(Hash,x);
	printf("Output Hashlist after record deleted:\n");
	for(i=0;i<MAXSIZE;i++)
	  printf("%4d",Hash[i]);
	printf("\nInsert key of record in Hashlist:\n");
	scanf("%d",&x);
	Hash_Insert(Hash,x);
	printf("Output Hashlist after record inserted:\n");
	for(i=0;i<MAXSIZE;i++)
	  printf("%4d",Hash[i]);
	printf("\n");
	return 0;
}
