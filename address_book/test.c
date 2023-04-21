//测试通讯录
#define _CRT_SECURE_NO_WARNINGS 1
#include"ad.h"

enum option
{
	EXIT,//0 退出
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT
};

int main()
{
	int input = 0;
	//创建通讯录
	Contact con;
	//初始化通讯录
	InitContact(&con);
	do 
	{
		menu();
		printf("请选择>");
		scanf("%d", &input);
		switch (input)
		{
			case ADD:
				add_peo(&con);
				break;
			case DEL:
				del_peo(&con);
				break;
			case SEARCH:
				search_peo(&con);
				break;
			case MODIFY:
				modify_peo(&con);
				break;
			case SORT:
				break;
			case PRINT://打印
				Print_ad(&con);
				break;
			case EXIT:
				printf("已退出\n");
				break;
			default:
				printf("请重新选择>");
				break;	
		}	
	}
	while (input);

	return 0;
}
