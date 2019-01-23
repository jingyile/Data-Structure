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
	//L=(SqList *)malloc(sizeof(SqList));//先进行过初始化则不需要 
	for(int i=0;i<n;i++)
	L->data[i]=a[i];
	L->length=n;
 } 
void InitList(SqList *&L)//初始化 
{
	L=(SqList *)malloc(sizeof(SqList));
	L->length=0;
}
void DestroyList(SqList *&L)//销毁 
{
	free(L);
}
bool ListEmpty(SqList *L)//判断是否为空 
{
	return(L->length==0);
} 
int ListLength(SqList *L)//求长度 
{
	return L->length; 
}
void DispList(SqList *L)//输出 
{
	for(int i=0;i<L->length;i++)
	{
		printf("%c",L->data[i]);
	}
	printf("\n"); 
}
bool GetElem(SqList *L,int i,ElemType &e)//求某个数据元素值，用e返回第i个元素的值 
{
	if(i<0||i>L->length)
	return false;
	e=L->data[i-1];
	return true;
}
int LocateElem(SqList *L,ElemType e)//按元素值查找，顺序查找第一个值与e相等的元素的逻辑序号，不存在则返回0 
{
	int i=0;
	while(i<L->length&&L->data[i]!=e)
	i++;
	if(i>L->length)
	return 0;
	else
	return i+1;
}
bool ListInsert(SqList *&L,int i,ElemType e)//在L的第i个位置上插入新的元素e 
{
	int j;
	if(i<1||i>L->length+1)
	return false;
	i--; //逻辑序号转换为物理序号！
	for(int j=L->length;j>i;j--)
	 L->data[j]=L->data[j-1];
	 L->data[i]=e;
	 L->length++;
	 return true;
}
bool ListDelete(SqList *&L,int i,ElemType &e)//删除L的第i个元素
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
	printf("空！\n");
	else
	{ 
	printf("不空！\n");
	DispList(L);
	printf("当前长度为：%d\n",ListLength(L)); 
//	ListInsert(L,1,'B');
//	ListInsert(L,1,'A');
//	ListInsert(L,1,'B');
	ListDelete(L,1,e);//此处e保存的是被删除的元素 
	printf("被删除的为%c\n",e);
	printf("当前长度为：%d\n",ListLength(L)); 
	printf("输出：");
	DispList(L);
	} 
	return 0;
} 


