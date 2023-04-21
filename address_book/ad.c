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
void InitContact(Contact* pc)
{
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));//��ʼ������
}
void add_peo(Contact* pc)
{
	if (pc->sz == MAX)
	{
		printf("����");
		return;
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