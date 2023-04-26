#define _CRT_SECURE_NO_WARNINGS 1
#include"ad.h"

void menu()
{
	printf("******************************\n");
	printf("*****1.add     2.del   *******\n");
	printf("*****3.search  4.modify*******\n");
	printf("*****5.sort    6.print *******\n");
	printf("*****      0.exit      *******\n");
	printf("******************************\n");
}
//1.0版本
//void InitContact(Contact* pc)
//{
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));//初始化数组
//}

//2.0版本
void InitContact(Contact* pc)
{
	
	pc->data=(peo_ad *)malloc(Init_num*sizeof(peo_ad));
	//typedef struct people_ad
	//{
	//	char name[MAX_NAME];
	//	char sex[MAX_SEX];
	//	int age;
	//	char tel[MAX_TEL];
	//	char addr[MAX_ADDR];
	//}peo_ad;//struct people_ad=peo_ad
	if (pc->data == NULL)
	{
		perror("Initcontact");
		return;
	}
	pc->capacity = Init_num;
	pc->sz = 0;
}
void dele_contact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}
////1.0
//void add_peo(Contact* pc)
//{
//	if (pc->sz == MAX)
//	{
//		printf("已满");
//		return;
//	}
//	//增加
//	printf("请输入名字>");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("请输入性别>");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("请输入年龄>");
//	scanf("%d", &(pc->data[pc->sz].age));
//	printf("请输入地址>");
//	scanf("%s", pc->data[pc->sz].addr); 
//	printf("请输入电话>");
//	scanf("%s", pc->data[pc->sz].tel);
//
//	pc->sz++;
//
//	printf("增加成功\n");
//}
//2.0
void add_peo(Contact* pc)
{
	//增容
	if (pc->sz == pc->capacity)
	{
		peo_ad *ptr=(peo_ad*)realloc(pc->data, (pc->capacity + every_num) * sizeof(peo_ad));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += every_num; 
			printf("增容成功\n");
		}
		else
		{
			perror("add_peo\n");
			return;
		}
	}
	//增加
	printf("请输入名字>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入性别>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入年龄>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入地址>");
	scanf("%s", pc->data[pc->sz].addr); 
	printf("请输入电话>");
	scanf("%s", pc->data[pc->sz].tel);

	pc->sz++;

	printf("增加成功\n");
}



void Print_ad(const Contact* pc)
{
	int i = 0;
	printf("%-10s\t%-5s\t%-5s\t%-20s\t%-12s\n", "名字", "性别","年龄","地址","电话");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-5s\t%-5d\t%-20s\t%-12s\n", 
			pc->data[i].name,
			pc->data[i].sex, 
			pc->data[i].age, 
			pc->data[i].addr,
			pc->data[i].tel);
	}
}
static int search_peo_byname(Contact *pc, char name[])
{
	//查人函数
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void del_peo(Contact* pc)//删除信息
{
	char name[MAX_NAME] = { 0 };
	if (pc->sz==0)//if后不要加分号
	{
		printf("通讯录为空\n");
		return;
	}
	printf("请输入要删除人的名字：>");
	scanf("%s", name);
	int pos=search_peo_byname(pc,name);//查找人
	if (pos == -1)
	{
		printf("查无此人\n");
	}
	//删除
	int j = 0;
	for (j=pos; j < pc->sz-1;j++)
	{
		pc->data[j] = pc->data[j+1];
	}
	pc->sz--;
	printf("删除成功\n");
}

void search_peo(const Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找人的名字：>");
	scanf("%s", name);
	int pos = search_peo_byname(pc, name);//查找人
	if (pos == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("查到了\n");
		printf("%-10s\t%-5s\t%-5s\t%-20s\t%-12s\n", "名字", "性别", "年龄", "地址", "电话");
		printf("%-10s\t%-5s\t%-5d\t%-20s\t%-12s\n",
				pc->data[pos].name,
				pc->data[pos].sex,
				pc->data[pos].age,
				pc->data[pos].addr,
				pc->data[pos].tel);
	}
}
void modify_peo(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改的名字：>");
	scanf("%s", name);
	int pos = search_peo_byname(pc, name);//查找人
	if (pos == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("请输入名字>");
		scanf("%s", pc->data[pos].name);
		printf("请输入性别>");
		scanf("%s", pc->data[pos].sex);
		printf("请输入年龄>");
		scanf("%d", &(pc->data[pos].age));
		printf("请输入地址>");
		scanf("%s", pc->data[pos].addr);
		printf("请输入电话>");
		scanf("%s", pc->data[pos].tel);
		printf("修改完成\n");
	}
}