#pragma warning(disable:6031)//屏蔽scanf报错
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<malloc.h>
#define Max 255
typedef struct String
{
	char str[Max + 1];
	int len;
}string;
string* init_string()
{
	string* str = (string*)malloc(sizeof(string));
	if (str == NULL)
		exit(-1);
	str->len = 0;
	return str;
}
int string_len(string* str)
{
	int len = str->len;
	return len;
}
string* string_assign(string* str1, char str2[])
{
	int i = 1;
	for (i; str2[i - 1] != '\0'; i++)
	{
		str1->str[i] = str2[i - 1];
	}
	str1->len = i - 1;
	return str1;
}
void string_print(string* str)
{
	for (int i = 1; i <= str->len; i++)
		printf("%c", str->str[i]);
	printf("\n");
}
//*************************************** next[] **************************************
int* GetNext(string *s)
{
	int* next = (int*)malloc(sizeof(int) * s->len + 1);
	if (next == NULL)
		exit(-1);
	*(next+1) = 0;  //第一个必定为0
	if (s->len == 1)
		return next;
	else if (s->len == 2)
	{
		*(next + 2) = 1;  //第二个必定为1
		return next;
	}
	else  //3个字符及以上
	{
		*(next + 2) = 1;
		for (int i = 3; i <= s->len; i++)
		{
			*(next + i) = 0;
		}
		for (int now = 3; now <= s->len; now++)
		{
			//从最长的相同前后缀算起,长度依次递减
			int front = 1, back = 2, now_move = now;
			for (back; back != now_move; back++) //长度(次数)
			{
				int front_move = front, back_move = back;
				if (s->str[front] == s->str[back]) //前缀和后缀的第一个字符相同
				{
					while (back_move != now_move)//比较该长度的前后缀的“其他字符”是否相等
					{
						if (++back_move == now_move) //先让后指针向后移动,看看该长度的后缀比完了没有
						{
							//找到了该长度的相同前后缀
							*(next + now_move) = back_move - back;
							back = now_move - 1;  //找到了next[]的值，就可以的退出了															
						}
						else
						{
							front_move++;  //让前指针向后移动，比较当前对应字符是否相等
							if (s->str[back_move] != s->str[front_move]) //不相等->中间断了
								break;  //跳出while循环，back后移，说明当前长度不存在相同前后缀
						}
					}
				}
			}
		}
		for (int i = 3; i <= s->len; i++)
		{
			*(next + i) += 1;  //最大相同前后缀+1
		}
		return next;
	}
}
//*************************************** KMP算法 **************************************
int KMP(string* main, string* son, int *next)
{
	/*for (int i = 1; i <= main->len; i++)
		printf("%c", main->str[i]);
	
	printf("\n");
	for (int i = 1; i <= son->len; i++)
		printf("%c", son->str[i]);

	printf("\n");
	for (int i = 1; i <= son->len; i++)
		printf("%d", next[i]);
	printf("\n");
	printf("main_len = %d,son_len = %d\n", main->len, son->len);*/
	int p_main = 1, p_son = 1;
	for (p_main; p_main <= main->len; p_main++ )
	{
		if (main->str[p_main] != son->str[p_son])
		{
			while (p_son > 1)
			{
				p_son = next[p_son - 1] + 1;
				if (main->str[p_main] == son->str[p_son])
				{
					p_son++;  //相等，让子串指针后移，进行下一组的对比，与外层else原理一样
					break;    //相等则不用再回退
				}
			}
			//当子串第一个字符始终于主串对应字符不相等时，如果主串剩余的字符(包含当前字符)与字串的长度
		    //相等时，此时子串第一个字符还是和当前字符不相等，则不必继续移动主串指针，
			//因为移动主串指针后，主串剩余字符数(包含当前字符) < 子串的长度
			//主要是长度不同，再比较就无意义了，其次防止主串指针越界，如果后面的字符一直相同，
			//则主串指针会一直后移，直到子串指针指向最后一个字符，
			//这时，可能会在子串指针指向最后一个字符前，主串指针已经指向了最后一个字符后面的位置
			//就会发生“越界行为”
			if ((p_main == main->len - son->len + 1) && p_son == 1)
				return -1;
		}
		else
		{
			p_son++;
		}
		if (p_son == son->len + 1)
		{
			return p_main - p_son + 2;
		}
	}
	return -1;
}
void main()
{
	//*****************************************  KMP匹配  ************************************
	
	//0.获取next[]测试
	string* test;
	test = init_string();
	char ch[] = "ababaab";
	string_assign(test, ch);
	int* next_test = GetNext(test);
	for (int i=1;i<=test->len;i++)
	{
		printf("%d", next_test[i]);
	}
	printf("\nnext[]测试结束\n");
	//1.获取next[]
	string* str_main, * str_son;
	char ch_main[] = "abababcaa";
	char ch_son[] =  "caa";
	str_main = init_string();
	str_son = init_string();
	string_assign(str_main, ch_main);
	string_assign(str_son, ch_son);
	int* next = GetNext(str_son);
	//2.模式匹配
	printf("主串:   ");
	string_print(str_main);
	printf("模式串: ");
	string_print(str_son);
	printf("匹配结果：");
	int pos;
	pos = KMP(str_main, str_son, next);
	printf("位置 = %d\n", pos);

}