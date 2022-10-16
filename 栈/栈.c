#pragma warning(disable:6031)//屏蔽scanf报错
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
//******************************************顺序栈******************************************


//#define size 10
//typedef struct Stack
//{
//	int data[size];
//	int top;
//}Stack;
//void Init_Stack(Stack* S)  //初始化栈
//{
//	S->top = -1;
//}   
//bool stack_empty(Stack S)  //判断栈是否为空
//{
//	if (S.top == -1)
//		return true;
//	else
//		return false;
//}
//void stack_push(Stack* S, int data)  //入栈
//{
//	int data_push;
//	if (S->top == size - 1)
//		printf("栈已满，错误！\n");
//	else
//	{
//		S->top++;					//先让栈顶向上移动
//		S->data[S->top] = data;		//写入数据
//		data_push = S->data[S->top];//保存进栈数据
//		//简写：data_push = S->data[++S->top] = data;
//		printf("进栈数据为：  %d\n", data_push);
//	}
//}
//bool stack_full(Stack S)   //判断栈是否满了
//{
//	if (S.top = size - 1)
//		return true;
//	else
//		return false;
//}
//void stack_pop(Stack* S)  //出栈
//{
//	int data_pop;
//	if (S->top == -1)
//		printf("栈已空，错误！\n");
//	else
//	{
//		data_pop = S->data[S->top];   //保存出栈数据
//		S->top--;					  //让栈顶向下移动
//		//简写：data_pop = S->data[S->top--];
//		printf("出栈数据为:   %d\n", data_pop);
//	}
//}


//void main()
//{
//	Stack S;
//	Init_Stack(&S);
//	printf("栈初始化： 栈顶 -> %d\n", S.top);
//	stack_push(&S, 10);
//	stack_push(&S, 20);
//	stack_push(&S, 30);
//	stack_pop(&S);
//	printf("栈顶元素为：  %d\n", S.data[S.top]);
//}



//******************************************链栈******************************************

typedef struct Stack
{
	int data;
	struct Stack* next;
}stack;
stack* init_stack()  //初始化栈
{
	stack* s = NULL;
	return s;
}
void stack_empty(stack* top, stack* base)  //判断栈是否为空
{
	if (top == base)	
		printf("栈为空\n");		
	else
		printf("栈不为空\n");
}
stack* stack_push(stack* s,int data)  //入栈
{
	stack* p = (stack*)malloc(sizeof(stack));
	if (p == NULL)
		exit(-1);
	p->data = data;
	p->next = s;
	s = p;
	return s;
}
void get_top(stack* s)  //获得栈顶数据
{
	if (s == NULL)
		printf("栈已空，读取栈顶元素错误\n");
	else
		printf("当前栈顶元素为： %d\n", s->data);
}
stack* stack_pop(stack* s)  //出栈
{
	if(s == NULL)
	{ 
		printf("栈已空，出栈错误\n");
		return NULL;
	}
	else
	{
		int pop_num;
		pop_num = s->data;
		printf("出栈元素为： %d\n", pop_num);
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
	get_top(top);			//获取栈顶数据

	top = stack_pop(top);
	top = stack_pop(top);
	stack_empty(top,base);		//出栈两次后判断是否为空栈

	top = stack_pop(top);     //出栈最后一个元素
	get_top(top);			//获取栈顶数据

	top = stack_pop(top);		//栈已为空的情况出栈
	stack_empty(top,base);		//查看是否为空栈
}






















