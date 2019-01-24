/*�ļ���:algo2-1.cpp
2079/1/24*/
#include <stdio.h>
#include <malloc.h>
#define MaxSize 50
typedef char ElemType;
typedef struct 
{
	ElemType data[MaxSize];
   	int length;
} SqList;
void InitList(SqList *&L)	//��ʼ�����Ա�
{
	L=(SqList *)malloc(sizeof(SqList));	//���������Ա�Ŀռ�
	L->length=0;						//�ÿ����Ա���Ϊ0
}
void DestroyList(SqList *L)		//�������Ա�
{
	free(L);
}
bool ListEmpty(SqList *L)	//�����Ա��Ƿ�Ϊ�ձ�
{
	return(L->length==0);
}
int ListLength(SqList *L)	//�����Ա�ĳ���
{
	return(L->length);
}
void DispList(SqList *L)	//������Ա�
{
	int i;
	if (ListEmpty(L)) return;
	for (i=0;i<L->length;i++)
		printf("%c ",L->data[i]);
	printf("\n");
}
bool GetElem(SqList *L,int i,ElemType &e)	//�����Ա���ĳ������Ԫ��ֵ
{
	if (i<1 || i>L->length)
		return false;			//��������ʱ����false
	e=L->data[i-1];				//ȡԪ��ֵ
	return true;				//�ɹ��ҵ�Ԫ��ʱ����true
}
int LocateElem(SqList *L, ElemType e)	//��Ԫ��ֵ����
{
	int i=0;
	while (i<L->length && L->data[i]!=e)
		i++;					//����Ԫ��e
	if (i>=L->length)			//δ�ҵ�ʱ����0
		return 0;
	else
		return i+1;				//�ҵ��󷵻����߼����
}

bool ListInsert(SqList *&L,int i,ElemType e)	//��������Ԫ��
{
	int j;
	if (i<1 || i>L->length+1)
		return false;			//��������ʱ����false
	i--;						//��˳����߼����ת��Ϊ�������
	for (j=L->length;j>i;j--)	//��data[i]������Ԫ�غ���һ��λ��
		L->data[j]=L->data[j-1];
	L->data[i]=e;				//����Ԫ��e
	L->length++;				//˳�������1
	return true;				//�ɹ����뷵��true
}
bool ListDelete(SqList *&L,int i,ElemType &e)	//ɾ������Ԫ��
{
	int j;
	if (i<1 || i>L->length)		//��������ʱ����false
		return false;
	i--;						//��˳����߼����ת��Ϊ�������
	e=L->data[i];
	for (j=i;j<L->length-1;j++)	//��data[i]֮���Ԫ��ǰ��һ��λ��
		L->data[j]=L->data[j+1];
	L->length--;				//˳����ȼ�1
	return true;				//�ɹ�ɾ������true
}
