#pragma warning(disable:6031)//����scanf����
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
//******************************************˳��ջ******************************************


//#define size 10
//typedef struct Stack
//{
//	int data[size];
//	int top;
//}Stack;
//void Init_Stack(Stack* S)  //��ʼ��ջ
//{
//	S->top = -1;
//}   
//bool stack_empty(Stack S)  //�ж�ջ�Ƿ�Ϊ��
//{
//	if (S.top == -1)
//		return true;
//	else
//		return false;
//}
//void stack_push(Stack* S, int data)  //��ջ
//{
//	int data_push;
//	if (S->top == size - 1)
//		printf("ջ����������\n");
//	else
//	{
//		S->top++;					//����ջ�������ƶ�
//		S->data[S->top] = data;		//д������
//		data_push = S->data[S->top];//�����ջ����
//		//��д��data_push = S->data[++S->top] = data;
//		printf("��ջ����Ϊ��  %d\n", data_push);
//	}
//}
//bool stack_full(Stack S)   //�ж�ջ�Ƿ�����
//{
//	if (S.top = size - 1)
//		return true;
//	else
//		return false;
//}
//void stack_pop(Stack* S)  //��ջ
//{
//	int data_pop;
//	if (S->top == -1)
//		printf("ջ�ѿգ�����\n");
//	else
//	{
//		data_pop = S->data[S->top];   //�����ջ����
//		S->top--;					  //��ջ�������ƶ�
//		//��д��data_pop = S->data[S->top--];
//		printf("��ջ����Ϊ:   %d\n", data_pop);
//	}
//}


//void main()
//{
//	Stack S;
//	Init_Stack(&S);
//	printf("ջ��ʼ���� ջ�� -> %d\n", S.top);
//	stack_push(&S, 10);
//	stack_push(&S, 20);
//	stack_push(&S, 30);
//	stack_pop(&S);
//	printf("ջ��Ԫ��Ϊ��  %d\n", S.data[S.top]);
//}



//******************************************��ջ******************************************

typedef struct Stack
{
	int data;
	struct Stack* next;
}stack;
stack* init_stack()  //��ʼ��ջ
{
	stack* s = NULL;
	return s;
}
void stack_empty(stack* top, stack* base)  //�ж�ջ�Ƿ�Ϊ��
{
	if (top == base)	
		printf("ջΪ��\n");		
	else
		printf("ջ��Ϊ��\n");
}
stack* stack_push(stack* s,int data)  //��ջ
{
	stack* p = (stack*)malloc(sizeof(stack));
	if (p == NULL)
		exit(-1);
	p->data = data;
	p->next = s;
	s = p;
	return s;
}
void get_top(stack* s)  //���ջ������
{
	if (s == NULL)
		printf("ջ�ѿգ���ȡջ��Ԫ�ش���\n");
	else
		printf("��ǰջ��Ԫ��Ϊ�� %d\n", s->data);
}
stack* stack_pop(stack* s)  //��ջ
{
	if(s == NULL)
	{ 
		printf("ջ�ѿգ���ջ����\n");
		return NULL;
	}
	else
	{
		int pop_num;
		pop_num = s->data;
		printf("��ջԪ��Ϊ�� %d\n", pop_num);
		s = s->next;
		return s;
	}
}
void main()
{
	stack* base, * top;
	base = top = init_stack();
	stack_empty(top,base);

	top = stack_push(top, 1);
	top = stack_push(top, 2);
	top = stack_push(top, 3);
	get_top(top);			//��ȡջ������

	top = stack_pop(top);
	top = stack_pop(top);
	stack_empty(top,base);		//��ջ���κ��ж��Ƿ�Ϊ��ջ

	top = stack_pop(top);     //��ջ���һ��Ԫ��
	get_top(top);			//��ȡջ������

	top = stack_pop(top);		//ջ��Ϊ�յ������ջ
	stack_empty(top,base);		//�鿴�Ƿ�Ϊ��ջ
}






















