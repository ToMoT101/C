#pragma warning(disable:6031)//����scanf����
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

//******************************************˳�����******************************************


//#define MAX 10
//typedef struct Queue
//{
//	int data[MAX];
//	int front;
//	int back;
//}queue;
//void init_queue(queue* Q)  //��ʼ������
//{
//	Q->front = 0;
//	Q->back = -1;
//}
//void queue_push(queue* Q,int data)  //���
//{
//	if (Q->back == MAX - 1)
//		printf("���������������\n");
//	else
//	{
//		int push_data;
//		Q->back++;
//		Q->data[Q->back] = data;
//		push_data = Q->data[Q->back];
//		printf("�������Ϊ��  %d\n", push_data);
//	}
//}
//void queue_pop(queue* Q)  //����
//{
//	if (Q->front > Q->back)
//		printf("���ѿ�,���ܳ���\n");
//	else
//	{
//		int pop_data;
//		pop_data = Q->data[Q->front];
//		Q->front++;
//		printf("��������Ϊ��  %d\n", pop_data);
//	}
//}
//bool queue_empty(queue Q)  //�ж϶����Ƿ�Ϊ��
//{
//	if (Q.front > Q.back)
//		return true;
//	else
//		return false;
//}
//bool queue_full(queue Q)  //�ж϶����Ƿ�����
//{
//	if (Q.back == MAX - 1)
//		return true;
//	else
//		return false;
//}
//void get_front(queue Q)  //��ȡ��������
//{
//	if (queue_empty(Q))
//	{
//		printf("����Ϊ�գ��޷���ȡ��������\n");
//	}
//	else
//	{
//		int front;
//		front = Q.data[Q.front];
//		printf("����Ϊ��  %d\n", front);
//	}
//}
//void get_back(queue Q)  //��ȡ��β����
//{
//	if (queue_empty(Q))
//	{
//		printf("����Ϊ�գ��޷���ȡ��β����\n");	
//	}
//	else
//	{
//		int back;
//		back = Q.data[Q.back];
//		printf("��βΪ��  %d\n", back);
//	}
//}


//void main()
//{
//	queue Q;
//	init_queue(&Q);
//	printf("���г�ʼ���� ���� -> %d  ��β -> %d\n", Q.front, Q.back);
//	queue_push(&Q, 1);
//	queue_push(&Q, 2);
//	queue_push(&Q, 3);
//	queue_push(&Q, 4);
//	queue_push(&Q, 5);
//
//	queue_pop(&Q);
//	get_front(Q);
//	get_back(Q);
//
//	queue_pop(&Q);
//	queue_pop(&Q);
//	queue_pop(&Q);
//	queue_pop(&Q);
//	get_front(Q);
//	get_back(Q);
//
//	queue_pop(&Q);
//
//}


//******************************************������******************************************
typedef struct Queue
{
	int data;
	struct Queue * next ;
}queue;
queue* init_Q()			//ͷ�ڵ�
{
	queue* p = (queue*)malloc(sizeof(queue));
	if (p == NULL)
		exit(-1);
	p->next = NULL;
	return p;
}
bool Q_empty(queue*p)  //�ж϶����Ƿ�Ϊ��
{
	if (p->next == NULL)
	{
		printf("����Ϊ��\n");
		return true;	
	}
	else
	{
		printf("���зǿ�\n");
		return false;
	}
}
queue* Q_push(queue*back,int data)	//���
{
	int data_push;
	queue* new = (queue*)malloc(sizeof(queue));
	if (new == NULL)
		exit(-1);
	data_push = new->data = data;
	printf("���Ԫ��Ϊ��%d\n", data_push);
	new->next = NULL;
	back->next = new;
	back = back->next;
	return back;
}
queue* Q_pop(queue* p, queue* top, queue* back)	 //����
{
	if (top == NULL)
	{
		printf("����Ϊ�գ��޷�����\n");
		return NULL;
	}
	else
	{
		int data_pop;
		queue* top_free = p->next;
		data_pop = p->next->data;
		printf("����Ԫ��Ϊ��%d\n", data_pop);
		top = p->next = p->next->next;
		if (top == NULL)
			printf("�����ѿգ��޷��鿴\n");
		else
		printf("��ǰ��ͷԪ��Ϊ��%d\n", top->data);
		free(top_free);
		return top;
	}
}

void main()
{
	//��ͷ�ڵ��������
	queue* q_1, * top, * back;
	back = top = q_1 = init_Q();
	back = Q_push(back, 1);
	back = Q_push(back, 2);
	back = Q_push(back, 3);
	Q_empty(q_1);
	printf("\n");
	top = Q_pop(q_1, top, back);
	top = Q_pop(q_1, top, back);
	top = Q_pop(q_1, top, back);
	Q_empty(q_1);
}
