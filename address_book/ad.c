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
//1.0�汾
//void InitContact(Contact* pc)
//{
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));//��ʼ������
//}

//2.0�汾
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
//		printf("����");
//		return;
//	}
//	//����
//	printf("����������>");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("�������Ա�>");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("����������>");
//	scanf("%d", &(pc->data[pc->sz].age));
//	printf("�������ַ>");
//	scanf("%s", pc->data[pc->sz].addr); 
//	printf("������绰>");
//	scanf("%s", pc->data[pc->sz].tel);
//
//	pc->sz++;
//
//	printf("���ӳɹ�\n");
//}
//2.0
void add_peo(Contact* pc)
{
	//����
	if (pc->sz == pc->capacity)
	{
		peo_ad *ptr=(peo_ad*)realloc(pc->data, (pc->capacity + every_num) * sizeof(peo_ad));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += every_num; 
			printf("���ݳɹ�\n");
		}
		else
		{
			perror("add_peo\n");
			return;
		}
	}
	//����
	printf("����������>");
	scanf("%s", pc->data[pc->sz].name);
	printf("�������Ա�>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("����������>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������ַ>");
	scanf("%s", pc->data[pc->sz].addr); 
	printf("������绰>");
	scanf("%s", pc->data[pc->sz].tel);

	pc->sz++;

	printf("���ӳɹ�\n");
}



void Print_ad(const Contact* pc)
{
	int i = 0;
	printf("%-10s\t%-5s\t%-5s\t%-20s\t%-12s\n", "����", "�Ա�","����","��ַ","�绰");
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
	//���˺���
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
void del_peo(Contact* pc)//ɾ����Ϣ
{
	char name[MAX_NAME] = { 0 };
	if (pc->sz==0)//if��Ҫ�ӷֺ�
	{
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	printf("������Ҫɾ���˵����֣�>");
	scanf("%s", name);
	int pos=search_peo_byname(pc,name);//������
	if (pos == -1)
	{
		printf("���޴���\n");
	}
	//ɾ��
	int j = 0;
	for (j=pos; j < pc->sz-1;j++)
	{
		pc->data[j] = pc->data[j+1];
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");
}

void search_peo(const Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�����˵����֣�>");
	scanf("%s", name);
	int pos = search_peo_byname(pc, name);//������
	if (pos == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("�鵽��\n");
		printf("%-10s\t%-5s\t%-5s\t%-20s\t%-12s\n", "����", "�Ա�", "����", "��ַ", "�绰");
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
	printf("������Ҫ�޸ĵ����֣�>");
	scanf("%s", name);
	int pos = search_peo_byname(pc, name);//������
	if (pos == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("����������>");
		scanf("%s", pc->data[pos].name);
		printf("�������Ա�>");
		scanf("%s", pc->data[pos].sex);
		printf("����������>");
		scanf("%d", &(pc->data[pos].age));
		printf("�������ַ>");
		scanf("%s", pc->data[pos].addr);
		printf("������绰>");
		scanf("%s", pc->data[pos].tel);
		printf("�޸����\n");
	}
}