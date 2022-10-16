#pragma warning(disable:6031)//屏蔽scanf报错
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define Max 100
typedef struct String
{
	char str[Max];
	int len;
}string;
string* init_string()  //初始化
{
	string* str=(string*)malloc(sizeof(string));
	if (str == NULL)
		exit(-1);
	str->len = 0;
	return str;
}
int string_len(string* str)  //长度
{
	int len = str->len;
	return len;
}
//string* string_assign(string* str)
//{
//	int i = 0;
//	printf("输入字符串：\n");
//	char ch = _getch();
//	printf("%c", ch);
//	while (ch != '\r')
//	{
//		i++;
//		str->str[i] = ch;
//		ch = _getch();
//		printf("%c", ch);
//	}
//	str->len = i;
//	return str;
//}
string* string_assign(string* str1,char str2[])  //赋值
{
	int i = 1;
	for ( i; str2[i-1] != '\0'; i++)
	{
		str1->str[i] = str2[i - 1];
	}
	str1->len = i-1;
	return str1;
}
void string_print(string *str)  //打印
{
	for (int i = 1; i <= str->len; i++)
		printf("%c", str->str[i]);
	printf("\n");
}
string* string_copy(string* str)  //复制
{
	return str;
}
int string_compare(string*str_1, string*str_2)  //比较
{
	for (int i = 1; i <= (str_1->len >= str_2->len ? str_1->len : str_2->len); i++)
	{
		if (str_1->str[i] < str_2->str[i])
			return -1;
		else if (str_1->str[i] > str_2->str[i])
			return 1;
	}
	return 0;
}
void string_connect(string* str1, string* str2)  //连接
{
	
	for (int i = 1; i < str2->len; i++)
	{
		str1->str[str1->len + i] = str2->str[i];
	}
	str1->len += str2->len;
}
string* string_get(string* str, int pos, int num)  //得到子串
{
	if (num > str->len - pos + 1)
	{
		printf("获取子串：非法操作\n");
		return 0;
	}
	string* son;
	son = init_string();
	for (int i = 1; i <= num; i++)   
	{
		son->str[i] = str->str[pos + i - 1];
	}
	son->len = num;
	printf("获取子串：成功\n");
	return son;
}
void string_insert(string* str_1, string* str_2, int pos)  //插入串
{
	if (pos < 1)
		printf("非法位置\n");
	else
	{
		if (pos > str_1->len)  //末尾插入
		{
			for (int i = 1; i <= str_2->len; i++)
			{
				str_1->str[str_1->len + i] = str_2->str[i];
			}
			str_1->len += str_2->len;
		}
		else //中间插入
		{
			for (int i = 1; i <= str_1->len - pos + 1; i++)  //   "abcdefgh0000"  "abcd0000efgh"       "wwww"
			{
				str_1->str[str_1->len + str_2->len + 1 - i] = str_1->str[str_1->len + 1 - i];
			}
			for (int i = 1; i <= str_2->len; i++)
			{
				str_1->str[pos + i - 1] = str_2->str[i];
			}
			str_1->len += str_2->len;
		}
	}
}
void string_delete(string* str,int pos,int num)  //删除子串
{
	if (num > str->len - pos + 1 || pos < 1)    
		printf("非法操作\n");
	else
	{
		for (int i = 1; i <= str->len - pos - num + 1; i++)   
		{
			str->str[pos + i - 1] = str->str[pos + num + i - 1];
		}
	}
	str->len -= num;
}
void main()
{
	string* s_1, * s_2;
	char a[] = "12345678";
	char b[] = "text";
	int len_1;
	//初始化
	s_1 = init_string();
	s_2 = init_string();
	
	//赋值
	string_assign(s_1, a);
	string_assign(s_2, b);
	
	//打印
	
	string_print(s_1);
	string_print(s_2);
	
	//长度
	
	//len_1 = string_len(s_1);
	//printf("字符串长度为：  %d\n", len_1);
	
	//复制
	
	//string* s_copy = string_copy(s_1);
	//string_print(s_copy);
	
	//比较
	
	//int result;
	//result = string_compare(s_1, s_2);
	//printf("\n0:相等  1:前>后  -1:前>后\n比较结果：  %d\n", result);
	
	//连接
	
	//string_connect(s_1, s_2);
	//string_print(s_1);
	
	//得到子串
	
	//string* son;
	//son = string_get(s_1, 4, 3);
	//string_print(son);

	//插入串

	//string_insert(s_1, s_2, 0);
	//string_print(s_1);

	//删除子串

	//string_delete(s_1, 7, 0);
	//string_print(s_1);

}