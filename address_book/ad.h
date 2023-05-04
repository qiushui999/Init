//通讯录
#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>



#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TEL 12
#define MAX_ADDR 30
#define MAX 1000
#define Init_num 3//初始容量
#define every_num 2//每次增加容量

//类型定义
typedef struct people_ad
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tel[MAX_TEL];
	char addr[MAX_ADDR];
}peo_ad;//struct people_ad=peo_ad

////通讯录1.0 静态版本
//typedef struct Contact
//{
//	peo_ad data[MAX];//1000人信息
//	int sz;//当前通讯录元素个数
//}Contact; //struct Contact=Contact

//通讯录2.0 动态版本
typedef struct Contact
{
	peo_ad *data;//指向申请动态空间，用于存放联系人地址
	int sz;//当前通讯录元素个数
	int capacity;//容量
}Contact; //struct Contact=Contact



//函数声明
void menu();//打印菜单 
void InitContact(Contact *pc);//初始化
void add_peo(Contact* pc);//增加
void Print_ad(const Contact* pc);//打印信息
void del_peo(Contact* pc);//删除信息
void search_peo(const Contact* pc);//查找信息
void modify_peo(Contact* pc);//修改信息
void dele_contact(Contact* pc);//释放内存
void save_contact(Contact* pc);//保存在内存中
void load(Contact* pc);//加载内容到通讯录
void check_capacity(Contact* pc);//加载内容到通讯录


