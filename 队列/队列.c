#pragma warning(disable:6031)//屏蔽scanf报错
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

//******************************************顺序队列******************************************


//#define MAX 10
//typedef struct Queue
//{
//	int data[MAX];
//	int front;
//	int back;
//}queue;
//void init_queue(queue* Q)  //初始化队列
//{
//	Q->front = 0;
//	Q->back = -1;
//}
//void queue_push(queue* Q,int data)  //入队
//{
//	if (Q->back == MAX - 1)
//		printf("队已满，不能入队\n");
//	else
//	{
//		int push_data;
//		Q->back++;
//		Q->data[Q->back] = data;
//		push_data = Q->data[Q->back];
//		printf("入队数据为：  %d\n", push_data);
//	}
//}
//void queue_pop(queue* Q)  //出队
//{
//	if (Q->front > Q->back)
//		printf("队已空,不能出队\n");
//	else
//	{
//		int pop_data;
//		pop_data = Q->data[Q->front];
//		Q->front++;
//		printf("出队数据为：  %d\n", pop_data);
//	}
//}
//bool queue_empty(queue Q)  //判断队列是否为空
//{
//	if (Q.front > Q.back)
//		return true;
//	else
//		return false;
//}
//bool queue_full(queue Q)  //判断队列是否满了
//{
//	if (Q.back == MAX - 1)
//		return true;
//	else
//		return false;
//}
//void get_front(queue Q)  //获取队首数据
//{
//	if (queue_empty(Q))
//	{
//		printf("队列为空，无法获取队首数据\n");
//	}
//	else
//	{
//		int front;
//		front = Q.data[Q.front];
//		printf("队首为：  %d\n", front);
//	}
//}
//void get_back(queue Q)  //获取队尾数据
//{
//	if (queue_empty(Q))
//	{
//		printf("队列为空，无法获取队尾数据\n");	
//	}
//	else
//	{
//		int back;
//		back = Q.data[Q.back];
//		printf("队尾为：  %d\n", back);
//	}
//}


//void main()
//{
//	queue Q;
//	init_queue(&Q);
//	printf("队列初始化： 队首 -> %d  队尾 -> %d\n", Q.front, Q.back);
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


//******************************************链队列******************************************
typedef struct Queue
{
	int data;
	struct Queue * next ;
}queue;
queue* init_Q()			//头节点
{
	queue* p = (queue*)malloc(sizeof(queue));
	if (p == NULL)
		exit(-1);
	p->next = NULL;
	return p;
}
bool Q_empty(queue*p)  //判断队列是否为空
{
	if (p->next == NULL)
	{
		printf("队列为空\n");
		return true;	
	}
	else
	{
		printf("队列非空\n");
		return false;
	}
}
queue* Q_push(queue*back,int data)	//入队
{
	int data_push;
	queue* new = (queue*)malloc(sizeof(queue));
	if (new == NULL)
		exit(-1);
	data_push = new->data = data;
	printf("入队元素为：%d\n", data_push);
	new->next = NULL;
	back->next = new;
	back = back->next;
	return back;
}
queue* Q_pop(queue* p, queue* top, queue* back)	 //出队
{
	if (top == NULL)
	{
		printf("队列为空，无法出队\n");
		return NULL;
	}
	else
	{
		int data_pop;
		queue* top_free = p->next;
		data_pop = p->next->data;
		printf("出队元素为：%d\n", data_pop);
		top = p->next = p->next->next;
		if (top == NULL)
			printf("队列已空，无法查看\n");
		else
		printf("当前队头元素为：%d\n", top->data);
		free(top_free);
		return top;
	}
}

void main()
{
	//带头节点的链队列
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
