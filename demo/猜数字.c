//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>//随机数
//#include<time.h>
//
//void menu()
//{
//	printf("***************************\n");
//	printf("********* 1.play **********\n");
//	printf("********* 0.exit **********\n");
//	printf("***************************\n");
//}
//void game() 
//{
//	int ret = rand()%100+1;//1.生成随机数	1-100
//	int guess = 0;
//	while (1)
//	{
//		printf("请你猜数字：>");
//		scanf("%d", &guess);
//		if (guess < ret)
//		{
//			printf("猜小了,往大了猜\n");
//		}
//		else if (guess > ret)
//		{
//			printf("猜大了,往小了猜\n");
//		}
//		else
//		{
//			printf("恭喜你！猜中了\n");
//			break;
//		}
//	}
//}
//int main() 
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));//种子传入时间才能随机
//	do
//	{
//		menu();//打印菜单
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{//菜单选择
//		case 1:
//			printf("猜数字开始\n");
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误，请重新选择\n");
//			break;
//		}
//	} 
//	while (input);
//	return 0;
//}