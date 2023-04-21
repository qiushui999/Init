#define _CRT_SECURE_NO_WARNINGS 1
int x = 1017;//定义变量在add.c里面用  全局变量整个工程都能用

static int ab = 0;//如果用static修饰全局变量， 则不能在外部文件使用

 int add(int x, int y)
{

	return x + y;

}