#pragma warning(disable:6031)//屏蔽scanf报错
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
typedef char string;

int* GetNext(string str[])
{
	//    "ababaa"-> a(x) -> ab(x) -> aba -> abab -> ababa -> ababaa
	int* next = (int*)malloc(sizeof(int) * 8);
	if (next == NULL)
		exit(-1);
	next[1] = 0;  //第一个必定为0
	if (strlen(str)-1 == 1)
		return next;
	else if (strlen(str)-1 == 2)
	{
		next[2] = 1; 
		return next;
	}
	else  //3个及3个字符以上  
	{
		next[2] = 1;
		for (int i = 3; i <= 7; i++)
		{
			next[i] = 0;
		}
		for (int now = 3; now <= 7; now++)
		{
			//从最长的相同前后缀算起,长度依次递减
			int front = 1, back = 2, now_move = now;
			for (back; back != now_move; back++) //长度(次数)
			{
				int front_move = front, back_move = back;
				if (str[front] == str[back]) //前缀和后缀的第一个字符相同
				{
					while (back_move != now_move)//比较该长度的前后缀的“其他字符”是否相等
					{
						if (++back_move == now_move) //先让后指针向后移动,看看该长度的后缀比完了没有
						{
							//找到了该长度的相同前后缀
							next[now_move] = back_move - back;//后指针移动的距离-1就是最长相同前后缀  
							back = now_move - 1;  //找到了next[]的值，就可以的退出了
							//此时的back_move == now_move，而back <= now_move
							//为了防止back继续后移，要让back==now_move，才能退出循环
							//由于最外层的for(back)循环后back+1
							//因此先back = now_move - 1，循环后back + 1，这样back == now_move
							//就能退出循环了																
						}
						else
						{
							front_move++;  //让前指针向后移动，比较当前对应字符是否相等
							if (str[back_move] != str[front_move]) //不相等->中间断了
								break;  //跳出while循环，back后移，说明当前长度不存在相同前后缀
						}
					}
				}
				//str[front] != str[back]   ->   该长度无最相同前后缀，长度-1再看看是否存在相同前后缀
				//->直接让back_move向后移动
			}
		}
		for (int i = 3; i <= 7; i++)
		{
			next[i] += 1;
		}
		return next;
	}
}
void main()
{
	string str[] = "0ababaaa"; //  
	//printf("%d", strlen(str));
	int * next = GetNext(str);
	for (int i=1;i<=7;i++)
	{
		printf("%d", next[i]);
	}
}

