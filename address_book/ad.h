//ͨѶ¼
#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>



#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TEL 12
#define MAX_ADDR 30
#define MAX 1000
#define Init_num 3//��ʼ����
#define every_num 2//ÿ����������

//���Ͷ���
typedef struct people_ad
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tel[MAX_TEL];
	char addr[MAX_ADDR];
}peo_ad;//struct people_ad=peo_ad

////ͨѶ¼1.0 ��̬�汾
//typedef struct Contact
//{
//	peo_ad data[MAX];//1000����Ϣ
//	int sz;//��ǰͨѶ¼Ԫ�ظ���
//}Contact; //struct Contact=Contact

//ͨѶ¼2.0 ��̬�汾
typedef struct Contact
{
	peo_ad *data;//ָ�����붯̬�ռ䣬���ڴ����ϵ�˵�ַ
	int sz;//��ǰͨѶ¼Ԫ�ظ���
	int capacity;//����
}Contact; //struct Contact=Contact



//��������
void menu();//��ӡ�˵� 
void InitContact(Contact *pc);//��ʼ��
void add_peo(Contact* pc);//����
void Print_ad(const Contact* pc);//��ӡ��Ϣ
void del_peo(Contact* pc);//ɾ����Ϣ
void search_peo(const Contact* pc);//������Ϣ
void modify_peo(Contact* pc);//�޸���Ϣ
void dele_contact(Contact* pc);//�ͷ��ڴ�
void save_contact(Contact* pc);//�������ڴ���
void load(Contact* pc);//�������ݵ�ͨѶ¼
void check_capacity(Contact* pc);//�������ݵ�ͨѶ¼


