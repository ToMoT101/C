#pragma warning(disable:6031)
#pragma warning(disable:6011)
#include<stdio.h>
#include<stdlib.h>
//**************************************** ��̬���� **************************************************
//
//struct student  //�����ڵ���������ָ����
//{
//	int data;//����
//	struct student* next;//ָ����һ���ڵ��ָ��
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

//**************************************** ��̬���� **************************************************
//node:�ڵ�
struct student  //�����ڵ���������ָ����
{
	int data;//����
	int flag;//�ڴ����ڵ�ʱ�����ж��Ƿ������ӽڵ�
	struct student* next;//ָ����һ���ڵ��ָ��
};
struct student* creat_node()//��������
{
	int nodes = 1;
	struct student* node_head, * node_new, * node_now;
	//ͷ�ڵ�(head)���µĽڵ�(move)�����ڵĽڵ�(now)
	node_new = node_now = (struct student*)malloc(sizeof(struct student));
	//���ڵ㶯̬�����ڴ�
	if (node_new == NULL)//������
		exit(-1);
	printf("��д���%d�ڵ�(ͷ�ڵ�)�����ݣ�", nodes);
	scanf("%d", &node_new->data);
	printf("�Ƿ������ӽڵ�(0/1)��");
	scanf("%d", &node_new->flag);
	node_head = node_new;//�ѵ�һ���ڵ���Ϊͷ�ڵ�
	while (node_new->flag != 0)//��ӽڵ�
	{
		nodes++;
		node_new = (struct student*)malloc(sizeof(struct student));//Ϊ�µĽڵ�����ڴ�
		printf("��д���%d�ڵ�����ݣ�", nodes);//д���½ڵ������
		scanf("%d", &node_new->data);
		printf("�Ƿ������ӽڵ�(0/1)��");
		scanf("%d", &node_new->flag);
		//�������д��벻��д��
		node_now->next = node_new;//ָ���¿��ٵ��ڴ���
		node_now = node_new;//�����¿��ٵ��ڴ���
	}
	printf("����������\n");
	node_now->next = NULL;//�����һ���ڵ��ָ�����Ϊ��ָ��
//*************************************** ��ʾ��ǰ�������� **************************************
	int node_num = 0;
	struct student* node_print = node_head;
	printf("**********  ��ǰ����  ***********\n\n");
	for (node_print; node_print != NULL; node_print = node_print->next)
	{
		node_num++;
		printf("��%d�ڵ������Ϊ��%d\n\n", node_num, node_print->data);
	}
	printf("\n**********  �������  **********\n");
//*************************************** ������Ĳ��� ******************************************

	struct student* node_access, * insert_head, * delete_head,* change_head;
	int node_select;
	int insert_location, delete_location, change_location;
	printf("ѡ�������Ĳ�����1.����/2.ɾ��/3.�޸�/4.�˳�\n");
	scanf("%d", &node_select);
	switch (node_select)
	{
//*************************************** �ڵ����(����"ͷ��β") ***************************************
	case 1:
		insert_head = node_access = node_head;//��ȡ�����Լ�����ͷ�ڵ�
		printf("ѡ�����ĸ��ڵ�������(��1��ʼ,1��ʾͷ�ڵ�)��");
		scanf("%d", &insert_location);
		for (int i = 1; i < insert_location; i++)//������Ҫ�����λ�õ�ǰһ���ڵ�
		{
			node_access = node_access->next;
		}
		struct student* node_insert = (struct student*)malloc(sizeof(struct student));
		//Ϊ������½ڵ㿪���ڴ�
		printf("����ڵ������Ϊ��");//д������
		scanf("%d", &node_insert->data);
		node_insert->next = node_access->next;//�����½ڵ��ָ����ָ�����λ�ú���Ľڵ�
		node_access->next = node_insert;//���ò���λ��ǰ��Ľڵ�ָ����ָ�����ڵ�
		return insert_head;
		break;
	case 2:
		//************************************ �ڵ�ɾ��(����ͷ�ڵ�) *************************************
		delete_head = node_access = node_head;//��ȡ�����Լ�����ͷ�ڵ�
		printf("ѡ��Ҫɾ���ڵ��ǰһ���ڵ�����(��1��ʼ,1��ʾͷ�ڵ�)��");
		scanf("%d", &delete_location);
		for (int i = 1; i < delete_location; i++)//������Ҫɾ����λ�ã���ѭ�����ʾ���뵽ͷ�ڵ�ĺ���
		{
			node_access = node_access->next;
		}
		struct student* del;//������ʱ�ṹ��ָ��
		del = node_access->next;//����ʱָ��ָ��Ҫɾ���Ľڵ�
		node_access->next = node_access->next->next;//��Ҫɾ���ڵ��ָ����ֵ����ǰ�ڵ��ָ����
		free(del);//�ͷ�ɾ���ڵ���ڴ�ռ�
		return delete_head;
	case 3://************************************ �ڵ��޸�(����λ��) ***********************************
		change_head = node_access = node_head;//��ȡ�����Լ�����ͷ�ڵ�
		printf("ѡ��Ҫ�޸Ľڵ�����(��1��ʼ,1��ʾͷ�ڵ�)��");
		scanf("%d", &change_location);
		for (int i = 1; i < change_location; i++)//������Ҫ�޸ĵ�λ�ã���ѭ�����ʾ���뵽ͷ�ڵ�ĺ���
		{
			node_access = node_access->next;
		}
		printf("�޸ĸýڵ������:");
		scanf("%d", &node_access->data);
		return change_head;
		break;
	case 4://************************************ �����κβ��� ****************************************
		return node_head;
		break;
	}
}
void main()
{
	int node_num = 0;
	struct student* stu1_create;
	stu1_create = creat_node();//��������ĵ�ַ
	for (stu1_create; stu1_create != NULL; stu1_create = stu1_create->next)//��ӡ����
	{
		node_num++;
		printf("��%d�ڵ������Ϊ��%d\n\n", node_num, stu1_create->data);
	}
	printf("������һ����%d���ڵ�\n", node_num);
	free(stu1_create);
}