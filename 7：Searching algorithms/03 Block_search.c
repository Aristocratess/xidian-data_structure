//�ֿ����
#include<stdio.h>
#define MAXSIZE 30
typedef struct{
	int key;
	char data;
}SeqList;
typedef  struct{
	int key; //���ڴ�ſ��ڵ����ؼ��� 
	int link; //����ָ������ʼλ�� 
}IndexType;

int IndexSearch(IndexType I[],int m,SeqList R[],int k)
{//������I����Ϊm
   int low=0,high=m-1,mid,i,j;
   while(low<=high)
   {
   	mid=(low+high)/2;
   	if(I[mid].key>=k)
   	   high=mid-1;
   	else
   	   low=mid+1;
	} 
	if(low<m)//�����������ҵ�����Ŀ飬��������˳���(������R)��˳�����
	{
		i=I[low+1].link-1;
		j=I[low].link;
		while(R[i].key!=k&&i>=j)
		  i--;
		if(i>=j)
		  return i;
	 } 
	return -1;
 } 
 
int main()
{
	int i;
	IndexType I[4]={18,0,38,4,71,9,90,11};
	SeqList R[16]={18,' ',6,' ',10,' ',11,' ',21,' ',31,' ',20,' ',38,' ',19,' ',60,' ',71,' ',75,' ',88,' ',73,' ',79,' ',90,' '};
	i=IndexSearch(I,4,R,38);
	if(i>-1)
	   printf("Site of 38 is %d\n",i);
	else
	   printf("Not find 38!\n");
	i=IndexSearch(I,4,R,26);
	if(i>-1)
	   printf("Site of 26 is %d\n",i);
	else
	   printf("Not find 26!\n");
	return 0; 
 } 
