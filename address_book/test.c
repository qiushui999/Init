//����ͨѶ¼
#define _CRT_SECURE_NO_WARNINGS 1
#include"ad.h"

enum option
{
	EXIT,//0 �˳�
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
	//����ͨѶ¼
	Contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do 
	{
		menu();
		printf("��ѡ��>");
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
			case PRINT://��ӡ
				Print_ad(&con);
				break;
			case EXIT:
				printf("���˳�\n");
				break;
			default:
				printf("������ѡ��>");
				break;	
		}	
	}
	while (input);

	return 0;
}
