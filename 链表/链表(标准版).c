#pragma warning(disable:6031)//����scanf����
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct List
{
	int data;
	struct List* next;
}list;

list* init_list()  //��ʼ��
{
	list* p = (list*)malloc(sizeof(list));
	if (p == NULL)
		exit(-1);
	p->next = NULL;
	return p;
}
void list_create(list* head)
{
	int flag = 1;
	list* last;
	list* new = (list*)malloc(sizeof(list));
	if (new == NULL)
		exit(-1);
	printf("����ڵ�����ݣ�  ");
	scanf("%d", &new->data);
	new->next = NULL;
	last = head->next = new;
	printf("�Ƿ������ӽڵ�(0/1):  ");
	scanf("%d", &flag);
	while (flag)
	{
		list* new = (list*)malloc(sizeof(list));
		if (new == NULL)
			exit(-1);
		printf("����ڵ�����ݣ�  ");
		scanf("%d", &new->data);
		new->next = NULL;
		last->next = new;
		last = last->next;
		printf("�Ƿ������ӽڵ�(0/1):  ");
		scanf("%d", &flag);
	}
	printf("\n");
}
void list_travel(list* p)  //����
{
	list* travel = p->next;
	for (travel; travel != NULL; travel = travel->next)
	{
		printf("%d  ", travel->data);
	}
	printf("\n");
}
void list_insert(list* head)  //����
{
	list* p = head;
	int pos;
	printf("����λ��(��1��ʼ)��  ");
	scanf("%d", &pos);
	if (pos < 1)
		printf("λ�÷Ƿ������ܽ��в������\n");
	else   //λ�úϷ����������ڣ���һ����Ϊβ�����ڵ�
	{
		for (int i = 1; i < pos; i++)
		{
			p = p->next;
			if (p->next == NULL)  //���������һ���ڵ��˳�����ֹ����
				break;
		}
		if (p->next == NULL)  //β�����
		{
			printf("��λ�ò����ڣ���˸�Ϊ��β�����\n");
			list* new = (list*)malloc(sizeof(list));
			if (new == NULL)
				exit(-1);
			printf("�������ڵ�����ݣ�  ");
			scanf("%d", &new->data);
			new->next = NULL;
			p->next = new;
		}
		else   //�м����
		{
			list* new = (list*)malloc(sizeof(list));
			if (new == NULL)
				exit(-1);
			printf("�������ڵ�����ݣ�  ");
			scanf("%d", &new->data);
			new->next = p->next;
			p->next = new;
		}
	}
	printf("\n");
}
void list_delete(list* head)
{
	list* p = head;
	int pos;
	printf("ɾ��λ��(��1��ʼ)��  ");
	scanf("%d", &pos);
	if (pos < 1)
		printf("λ�÷Ƿ������ܽ���ɾ������\n");
	else
	{
		for (int i = 1; i < pos; i++)
		{
			p = p->next;
			if (p->next == NULL)
				break;
		}
		if (p->next == NULL)
			printf("��λ�ò��ܽ���ɾ������\n");
		else
		p->next = p->next->next;
	}
	printf("\n");
}
void list_find(list* head)
{
	list* p = head->next; //�ӵ�һ��λ�ÿ�ʼ��
	if (p == NULL)
		printf("����Ϊ�գ������ݿɲ�ѯ\n");
	else
	{
		int num, pos = 1;
		bool flag = false;
		printf("����Ҫ���ҵ����ݣ�  ");
		scanf("%d", &num);
		for (p; p != NULL; p = p->next)
		{
			if (p->data == num)
			{
				flag = true;
				printf("%d��λ��Ϊ:%d\n", num, pos);
				break;
			}
			pos++;
		}
		if (flag == false)
			printf("δ���ҵ�%d��λ��\n", num);
	}
}
void list_modify(list* head)
{
	list* p = head->next;   //�ӵ�һ��λ�ÿ�ʼ
	if (p == NULL)
		printf("����Ϊ�գ������ݿ��޸�\n");
	else
	{
		int pos;
		printf("������Ҫ�޸ĵ�λ��(��1��ʼ)��  ");
		scanf("%d", &pos);
		if (pos < 1)
			printf("�Ƿ�λ�ã����ܽ����޸Ĳ���\n");
		else
		{
			int new_data;
			for (int i = 1; i < pos; i++)
			{
				p = p->next;
				if (p == NULL)
					break;
			}
			if (p == NULL)
				printf("��λ����Ч\n");
			else
			{
				printf("�����λ���޸ĺ�����ݣ�  ");
				scanf("%d", &new_data);
				p->data = new_data;
			}
		}
	}
}

void main()
{
	//��ͷ�ڵ�
	list* li_1; 
	li_1 = init_list();
	//����
	list_create(li_1);
	list_travel(li_1);
	//����
	list_insert(li_1);
	list_travel(li_1);
	//ɾ��
	list_delete(li_1);
	list_travel(li_1);
	//����
	list_find(li_1);
	list_travel(li_1);
	//�޸�
	list_modify(li_1);
	list_travel(li_1);





}