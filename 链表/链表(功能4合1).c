#pragma warning(disable:6031)
#pragma warning(disable:6011)
#include<stdio.h>
#include<stdlib.h>
//**************************************** 静态链表 **************************************************
//
//struct student  //创建节点的数据域和指针域
//{
//	int data;//数据
//	struct student* next;//指向下一个节点的指针
//};
//void main()
//{
//	struct student st1, st2, st3, st4, * head, * p;
//	st1.data = 1;
//	st2.data = 2;
//	st3.data = 3;
//	st4.data = 4;
//	head = &st1;
//	st1.next = &st2;
//	st2.next = &st3;
//	st3.next = &st4;
//	st4.next = NULL;
//	p = head;
//	for (p; p != NULL; p = p->next)
//	{
//		printf("data=%d\n", p->data);
//	}
//}

//**************************************** 动态链表 **************************************************
//node:节点
struct student  //创建节点的数据域和指针域
{
	int data;//数据
	int flag;//在创建节点时用来判断是否继续添加节点
	struct student* next;//指向下一个节点的指针
};
struct student* creat_node()//创建链表
{
	int nodes = 1;
	struct student* node_head, * node_new, * node_now;
	//头节点(head)、新的节点(move)、现在的节点(now)
	node_new = node_now = (struct student*)malloc(sizeof(struct student));
	//给节点动态分配内存
	if (node_new == NULL)//防报错
		exit(-1);
	printf("请写入第%d节点(头节点)的数据：", nodes);
	scanf("%d", &node_new->data);
	printf("是否继续添加节点(0/1)：");
	scanf("%d", &node_new->flag);
	node_head = node_new;//把第一个节点作为头节点
	while (node_new->flag != 0)//添加节点
	{
		nodes++;
		node_new = (struct student*)malloc(sizeof(struct student));//为新的节点分配内存
		printf("请写入第%d节点的数据：", nodes);//写入新节点的数据
		scanf("%d", &node_new->data);
		printf("是否继续添加节点(0/1)：");
		scanf("%d", &node_new->flag);
		//下面两行代码不能写反
		node_now->next = node_new;//指向新开辟的内存区
		node_now = node_new;//控制新开辟的内存区
	}
	printf("链表创建结束\n");
	node_now->next = NULL;//让最后一个节点的指针域变为空指针
//*************************************** 显示当前链表数据 **************************************
	int node_num = 0;
	struct student* node_print = node_head;
	printf("**********  当前链表  ***********\n\n");
	for (node_print; node_print != NULL; node_print = node_print->next)
	{
		node_num++;
		printf("第%d节点的数据为：%d\n\n", node_num, node_print->data);
	}
	printf("\n**********  链表结束  **********\n");
//*************************************** 对链表的操作 ******************************************

	struct student* node_access, * insert_head, * delete_head,* change_head;
	int node_select;
	int insert_location, delete_location, change_location;
	printf("选择对链表的操作：1.插入/2.删除/3.修改/4.退出\n");
	scanf("%d", &node_select);
	switch (node_select)
	{
//*************************************** 节点插入(除开"头和尾") ***************************************
	case 1:
		insert_head = node_access = node_head;//获取链表，以及任命头节点
		printf("选择在哪个节点后面插入(从1开始,1表示头节点)：");
		scanf("%d", &insert_location);
		for (int i = 1; i < insert_location; i++)//遍历到要插入的位置的前一个节点
		{
			node_access = node_access->next;
		}
		struct student* node_insert = (struct student*)malloc(sizeof(struct student));
		//为插入的新节点开辟内存
		printf("插入节点的数据为：");//写入数据
		scanf("%d", &node_insert->data);
		node_insert->next = node_access->next;//先让新节点的指针域指向插入位置后面的节点
		node_access->next = node_insert;//再让插入位置前面的节点指针域指向插入节点
		return insert_head;
		break;
	case 2:
		//************************************ 节点删除(除了头节点) *************************************
		delete_head = node_access = node_head;//获取链表，以及任命头节点
		printf("选择要删除节点的前一个节点的序号(从1开始,1表示头节点)：");
		scanf("%d", &delete_location);
		for (int i = 1; i < delete_location; i++)//遍历到要删除的位置，不循环则表示插入到头节点的后面
		{
			node_access = node_access->next;
		}
		struct student* del;//创建临时结构体指针
		del = node_access->next;//让临时指针指向要删除的节点
		node_access->next = node_access->next->next;//把要删除节点的指针域赋值给当前节点的指针域
		free(del);//释放删除节点的内存空间
		return delete_head;
	case 3://************************************ 节点修改(任意位置) ***********************************
		change_head = node_access = node_head;//获取链表，以及任命头节点
		printf("选择要修改节点的序号(从1开始,1表示头节点)：");
		scanf("%d", &change_location);
		for (int i = 1; i < change_location; i++)//遍历到要修改的位置，不循环则表示插入到头节点的后面
		{
			node_access = node_access->next;
		}
		printf("修改该节点的数据:");
		scanf("%d", &node_access->data);
		return change_head;
		break;
	case 4://************************************ 不做任何操作 ****************************************
		return node_head;
		break;
	}
}
void main()
{
	int node_num = 0;
	struct student* stu1_create;
	stu1_create = creat_node();//接收链表的地址
	for (stu1_create; stu1_create != NULL; stu1_create = stu1_create->next)//打印数据
	{
		node_num++;
		printf("第%d节点的数据为：%d\n\n", node_num, stu1_create->data);
	}
	printf("该链表一共有%d个节点\n", node_num);
	free(stu1_create);
}