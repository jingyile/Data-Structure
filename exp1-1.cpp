//�ļ�����exp1-1.cpp
//Ҳ����ֱ����ɸѡ�������� 
//˼�룺һ������Ϊ���������䱶���϶���Ϊ������ 
#include <stdio.h>
#include <math.h>
bool prime(int n)					//�ж�������n�Ƿ�Ϊ����
{
	int i;
	for (i=2;i<=(int)sqrt(n);i++)
		if (n%i==0) 
			return false;			//��n��������,���˳�������false
	return true;
}
int main()
{
	int n,i,j=0;					//j�����ۼ���������
	printf("n:");
	scanf("%d",&n);
	printf("С�ڵ���%d������:\n",n);
	if (n>2)
	{	printf("%4d",2);
		j++;
	}
	for (i=3;i<=n;i+=2)
		if (prime(i))
		{	printf("%4d",i);
			if (j!=0 && ++j%10==0)	//ÿ�������ʾ10������
				printf("\n");
		}
	printf("\n");
	return 0;
}
