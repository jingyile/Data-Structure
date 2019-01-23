#include <stdio.h>
#include <malloc.h>
#define MaxSize 50
typedef char ElemType;
typedef struct{
	ElemType data[MaxSize];
	int length;
}SqList;
void CreateList(SqList *&L,ElemType a[],int n)
{
	int i;
	//L=(SqList *)malloc(sizeof(SqList));//�Ƚ��й���ʼ������Ҫ 
	for(int i=0;i<n;i++)
	L->data[i]=a[i];
	L->length=n;
 } 
void InitList(SqList *&L)//��ʼ�� 
{
	L=(SqList *)malloc(sizeof(SqList));
	L->length=0;
}
void DestroyList(SqList *&L)//���� 
{
	free(L);
}
bool ListEmpty(SqList *L)//�ж��Ƿ�Ϊ�� 
{
	return(L->length==0);
} 
int ListLength(SqList *L)//�󳤶� 
{
	return L->length; 
}
void DispList(SqList *L)//��� 
{
	for(int i=0;i<L->length;i++)
	{
		printf("%c",L->data[i]);
	}
	printf("\n"); 
}
bool GetElem(SqList *L,int i,ElemType &e)//��ĳ������Ԫ��ֵ����e���ص�i��Ԫ�ص�ֵ 
{
	if(i<0||i>L->length)
	return false;
	e=L->data[i-1];
	return true;
}
int LocateElem(SqList *L,ElemType e)//��Ԫ��ֵ���ң�˳����ҵ�һ��ֵ��e��ȵ�Ԫ�ص��߼���ţ��������򷵻�0 
{
	int i=0;
	while(i<L->length&&L->data[i]!=e)
	i++;
	if(i>L->length)
	return 0;
	else
	return i+1;
}
bool ListInsert(SqList *&L,int i,ElemType e)//��L�ĵ�i��λ���ϲ����µ�Ԫ��e 
{
	int j;
	if(i<1||i>L->length+1)
	return false;
	i--; //�߼����ת��Ϊ������ţ�
	for(int j=L->length;j>i;j--)
	 L->data[j]=L->data[j-1];
	 L->data[i]=e;
	 L->length++;
	 return true;
}
bool ListDelete(SqList *&L,int i,ElemType &e)//ɾ��L�ĵ�i��Ԫ��
{
	int j;
	if(i<1||i>L->length+1)
	return false;
	i--;
	e=L->data[i];
	for(int j=i;j<L->length;j++)
	L->data[j]=L->data[j+1];
	L->length--;
	return true;	
} 
int main()
{ 
	SqList *L;
	ElemType e='X';
	InitList(L);
	char a[5]={'Z','X','C','V','B'};
	CreateList(L,a,5);
	if(ListEmpty(L))
	printf("�գ�\n");
	else
	{ 
	printf("���գ�\n");
	DispList(L);
	printf("��ǰ����Ϊ��%d\n",ListLength(L)); 
//	ListInsert(L,1,'B');
//	ListInsert(L,1,'A');
//	ListInsert(L,1,'B');
	ListDelete(L,1,e);//�˴�e������Ǳ�ɾ����Ԫ�� 
	printf("��ɾ����Ϊ%c\n",e);
	printf("��ǰ����Ϊ��%d\n",ListLength(L)); 
	printf("�����");
	DispList(L);
	} 
	return 0;
} 


