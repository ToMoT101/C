#pragma warning(disable:6031)//屏蔽scanf报错
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct List
{
	int data;
	struct List* next;
}list;

list* init_list()  //初始化
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
	printf("输入节点的数据：  ");
	scanf("%d", &new->data);
	new->next = NULL;
	last = head->next = new;
	printf("是否继续添加节点(0/1):  ");
	scanf("%d", &flag);
	while (flag)
	{
		list* new = (list*)malloc(sizeof(list));
		if (new == NULL)
			exit(-1);
		printf("输入节点的数据：  ");
		scanf("%d", &new->data);
		new->next = NULL;
		last->next = new;
		last = last->next;
		printf("是否继续添加节点(0/1):  ");
		scanf("%d", &flag);
	}
	printf("\n");
}
void list_travel(list* p)  //遍历
{
	list* travel = p->next;
	for (travel; travel != NULL; travel = travel->next)
	{
		printf("%d  ", travel->data);
	}
	printf("\n");
}
void list_insert(list* head)  //插入
{
	list* p = head;
	int pos;
	printf("插入位置(从1开始)：  ");
	scanf("%d", &pos);
	if (pos < 1)
		printf("位置非法，不能进行插入操作\n");
	else   //位置合法，但不存在，则一律视为尾后插入节点
	{
		for (int i = 1; i < pos; i++)
		{
			p = p->next;
			if (p->next == NULL)  //遍历到最后一个节点退出，防止出错
				break;
		}
		if (p->next == NULL)  //尾后插入
		{
			printf("此位置不存在，因此改为在尾后插入\n");
			list* new = (list*)malloc(sizeof(list));
			if (new == NULL)
				exit(-1);
			printf("输入插入节点的数据：  ");
			scanf("%d", &new->data);
			new->next = NULL;
			p->next = new;
		}
		else   //中间插入
		{
			list* new = (list*)malloc(sizeof(list));
			if (new == NULL)
				exit(-1);
			printf("输入插入节点的数据：  ");
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
	printf("删除位置(从1开始)：  ");
	scanf("%d", &pos);
	if (pos < 1)
		printf("位置非法，不能进行删除操作\n");
	else
	{
		for (int i = 1; i < pos; i++)
		{
			p = p->next;
			if (p->next == NULL)
				break;
		}
		if (p->next == NULL)
			printf("此位置不能进行删除操作\n");
		else
		p->next = p->next->next;
	}
	printf("\n");
}
void list_find(list* head)
{
	list* p = head->next; //从第一个位置开始找
	if (p == NULL)
		printf("链表为空，无数据可查询\n");
	else
	{
		int num, pos = 1;
		bool flag = false;
		printf("输入要查找的数据：  ");
		scanf("%d", &num);
		for (p; p != NULL; p = p->next)
		{
			if (p->data == num)
			{
				flag = true;
				printf("%d的位置为:%d\n", num, pos);
				break;
			}
			pos++;
		}
		if (flag == false)
			printf("未能找到%d的位置\n", num);
	}
}
void list_modify(list* head)
{
	list* p = head->next;   //从第一个位置开始
	if (p == NULL)
		printf("链表为空，无数据可修改\n");
	else
	{
		int pos;
		printf("输入需要修改的位置(从1开始)：  ");
		scanf("%d", &pos);
		if (pos < 1)
			printf("非法位置，不能进行修改操作\n");
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
				printf("该位置无效\n");
			else
			{
				printf("输入该位置修改后的数据：  ");
				scanf("%d", &new_data);
				p->data = new_data;
			}
		}
	}
}

void main()
{
	//带头节点
	list* li_1; 
	li_1 = init_list();
	//创建
	list_create(li_1);
	list_travel(li_1);
	//插入
	list_insert(li_1);
	list_travel(li_1);
	//删除
	list_delete(li_1);
	list_travel(li_1);
	//查找
	list_find(li_1);
	list_travel(li_1);
	//修改
	list_modify(li_1);
	list_travel(li_1);





}