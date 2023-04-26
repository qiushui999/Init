#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	
	int* p = malloc(10 * sizeof(int));//在堆区开辟40字节空间
	//int* p = (int*)malloc(40);
	for (int i = 0; i < 10; i++)
	{

		*(p + i) = i;
		printf("%d\n", p[i]);//*(p+i)
	}

	int* ptr=realloc(p, 20 * sizeof(int));//改成80字节
	if (ptr != NULL)
	{
		p = ptr;
	}
	free(p);
	p = NULL;//释放并置为空指针
	return 0;
}