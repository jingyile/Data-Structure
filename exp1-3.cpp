//�ļ�����exp1-3.cpp
//������Ļ����ַ��� 
#include <stdio.h>
#include <string.h>
#define MAX 100					//�ַ�������󳤶�
bool func(char s[])
{
	bool flag=true;
	int i,j,slen=strlen(s);		//slenΪ�ַ���s�ĳ���
	for (i=0,j=slen-1;i<j;i++,j--)
		if (s[i]!=s[j])
		{	
			flag=false;
			break;
		}
	return flag;
}
int main()
{
	char s[MAX];
	printf("����һ�ַ���:");
	scanf("%s",s);
	if (func(s))
		printf("%s�ַ����ǻ���\n",s);
	else
		printf("%s�ַ������ǻ���\n",s);
	return 0;
}
